//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapperComponent.h"
#include "RenderingThread.h"
#include "Engine/CollisionProfile.h"
#include "Net/UnrealNetwork.h"
#include "ContentStreaming.h"
#include "Logging/TokenizedMessage.h"
#include "Logging/MessageLog.h"
#include "Misc/MapErrors.h"
#include "Misc/UObjectToken.h"
#include "PhysicsEngine/BodySetup.h"
#include "Engine/StaticMesh.h"
#include "MeshSwapperModule.h"
#include "MeshSwapAnimation.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"


DECLARE_CYCLE_STAT(TEXT("Tick Animation"), STAT_TickAnimation, STATGROUP_MeshSwapper);

#define LOCTEXT_NAMESPACE "MeshSwapper"


UMeshSwapperComponent::UMeshSwapperComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);

	CastShadow = false;
	bUseAsOccluder = false;
	bCanEverAffectNavigation = false;

	Mobility = EComponentMobility::Movable;
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_DuringPhysics;
	bTickInEditor = true;
	
	CachedFrameIndex = INDEX_NONE;
	AccumulatedTime = 0.0f;
	PlayRate = 1.0f;

	bLooping = true;
	bReversePlayback = false;
	bPlaying = true;

	LastKeyframeLocation = FVector::ZeroVector;
	LastKeyframeRotation = FRotator::ZeroRotator;
	LastKeyframeScale = FVector::OneVector;
}


int32 UMeshSwapperComponent::GetCachedFrameIndex() const
{
	return CachedFrameIndex;
}

UStaticMesh* UMeshSwapperComponent::GetStaticMeshAtCachedIndex() const
{
	UStaticMesh* KeyframeToSend = nullptr;
	if ((SourceAnimation != nullptr) && SourceAnimation->IsValidKeyFrameIndex(CachedFrameIndex))
	{
		UStaticMesh* KeyFrameAsset = SourceAnimation->GetKeyFrameChecked(CachedFrameIndex).StaticMesh;
		KeyframeToSend = KeyFrameAsset;
	}
	return KeyframeToSend;
}


FMeshKeyFrameData* UMeshSwapperComponent::GetKeyframeDataAtCachedIndex() const
{
	return SourceAnimation != nullptr ? SourceAnimation->GetKeyFrameDataAtFrame(CachedFrameIndex) : nullptr;
}

FPrimitiveSceneProxy* UMeshSwapperComponent::CreateSceneProxy()
{
	CalculateCurrentFrame();
	return Super::CreateSceneProxy();
}

UBodySetup* UMeshSwapperComponent::GetBodySetup()
{
	CachedBodySetup = nullptr;

	if ((SourceAnimation != nullptr) && (SourceAnimation->GetCollisionSource() != EMeshAnimCollisionMode::NoCollision))
	{
		const int32 PotentialStaticMeshIndex = (SourceAnimation->GetCollisionSource() == EMeshAnimCollisionMode::FirstFrameCollision) ? 0 : CachedFrameIndex;
		UStaticMesh* KeyFrameAsset = SourceAnimation->GetStaticMeshAtFrame(PotentialStaticMeshIndex);
		UStaticMesh* PotentialStaticMeshSource = KeyFrameAsset ? KeyFrameAsset : nullptr;

		if (PotentialStaticMeshSource != nullptr)
		{
			CachedBodySetup = PotentialStaticMeshSource->GetBodySetup();
		}
	}

	return CachedBodySetup;
}

void UMeshSwapperComponent::CalculateCurrentFrame(bool bFireEvents /*= true*/, bool bSpawnParticles/*= true*/, bool bPlaySounds/*= true*/)
{
	const int32 LastCachedFrame = CachedFrameIndex;
	FMeshKeyFrameData* LastKeyframeData = GetKeyframeDataAtCachedIndex();
	CachedFrameIndex = (SourceAnimation != nullptr) ? SourceAnimation->GetKeyFrameIndexAtTime(AccumulatedTime) : INDEX_NONE;

	if (FMeshKeyFrameData* KeyframeDataToSend = GetKeyframeDataAtCachedIndex())
	{
		UStaticMesh* StaticMeshAsset = KeyframeDataToSend->StaticMesh;

		if (CachedFrameIndex != LastCachedFrame)
		{

			if (LastKeyframeData != nullptr)
			{
				LastKeyframeLocation = LastKeyframeData->RelativeTransform.Location;
				LastKeyframeRotation = LastKeyframeData->RelativeTransform.Rotation;
				LastKeyframeScale = LastKeyframeData->RelativeTransform.Scale;
			}

			// Update children transforms in case we have anything attached to an animated socket
			UpdateChildTransforms();

			SetStaticMesh(StaticMeshAsset);

			if (SourceAnimation != nullptr)
			{
				if (bFireEvents)
				{
					if (!SourceAnimation->GetKeyFrameChecked(CachedFrameIndex).NotifyTag.IsEmpty())
					{
						OnAnimationNotifyEvent.Broadcast
						(SourceAnimation->GetKeyFrameChecked(CachedFrameIndex).NotifyTag,
							CachedFrameIndex);
					}
				}

				if (bPlaySounds)
				{
					const TArray< FMeshKeyFrameSoundEffectData>& SoundEffects = SourceAnimation->GetKeyFrameChecked(CachedFrameIndex).SoundEffects;
					if (SoundEffects.Num() > 0)
					{
						for (const FMeshKeyFrameSoundEffectData& SoundEffect : SoundEffects)
						{
							if (SoundEffect.Sound)
							{
								if (!SoundEffect.Sound->IsLooping())
								{
									if (SoundEffect.bFollow)
									{
										UGameplayStatics::SpawnSoundAttached(SoundEffect.Sound, this, SoundEffect.AttachName, FVector(ForceInit), EAttachLocation::KeepRelativeOffset, false, SoundEffect.VolumeMultiplier, SoundEffect.PitchMultiplier);
									}
									else
									{
										UGameplayStatics::PlaySoundAtLocation(GetWorld(), SoundEffect.Sound, this->GetComponentLocation(), SoundEffect.VolumeMultiplier, SoundEffect.PitchMultiplier);
									}
								}
							}
						}
					}
				}

				if (bSpawnParticles)
				{
					const TArray< FMeshKeyFrameParticleEffectData>& ParticleEffets = SourceAnimation->GetKeyFrameChecked(CachedFrameIndex).ParticleEffects;
					if (ParticleEffets.Num() > 0)
					{
						for (const FMeshKeyFrameParticleEffectData& ParticleEffet : ParticleEffets)
						{
							if (ParticleEffet.PSTemplate != nullptr)
							{
								UParticleSystemComponent* NewComponent = UGameplayStatics::SpawnEmitterAttached(ParticleEffet.PSTemplate, this, ParticleEffet.SocketName, ParticleEffet.LocationOffset, ParticleEffet.RotationOffset, EAttachLocation::KeepRelativeOffset, ParticleEffet.bAutoDestroy);
							}
						}
					}
				}
			}

			ECollisionEnabled::Type CollisionType = !KeyframeDataToSend->bEnableCollision ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics;
			SetCollisionEnabled(CollisionType);
		}

		if (GetAnimationLength() > 0)
		{
			const FKeyframeRelativeTransform& CurrentTransform = KeyframeDataToSend->RelativeTransform;


			if (!KeyframeDataToSend->bSmoothTransformInterpolation)
			{
				SetRelativeTransform(CurrentTransform.ToTransform());
			}
			else
			{
				const float AnimDuration = SourceAnimation->GetTotalDuration();
				const int32 AnimFramesNum = SourceAnimation->GetNumKeyFrames();
				const int32 NextKeyframeIndex = (CachedFrameIndex + 1) % AnimFramesNum;
				const float CurrentKeyframeStartPosition = SourceAnimation->GetPositionAtKeyframeIndex(CachedFrameIndex);
				const float NextKeyframePosition = SourceAnimation->IsValidKeyFrameIndex(CachedFrameIndex + 1) ?
					SourceAnimation->GetPositionAtKeyframeIndex(CachedFrameIndex + 1) : GetAnimationLength();

				FKeyframeRelativeTransform PreviousTransform = SourceAnimation->InitialTransform;
				if (CachedFrameIndex != 0)
				{
					if (FMeshKeyFrameData* KeyframeAnim = SourceAnimation->GetKeyFrameDataAtFrame(CachedFrameIndex - 1))
					{
						PreviousTransform = KeyframeAnim->RelativeTransform;
					}
				}

				float LerpAlpha = bReversePlayback ? 1 : 0;

				if (CurrentKeyframeStartPosition != NextKeyframePosition)
				{
					LerpAlpha = (AccumulatedTime - CurrentKeyframeStartPosition) / (NextKeyframePosition - CurrentKeyframeStartPosition);
				}

				LerpAlpha = FMath::Clamp<float>(LerpAlpha, 0, 1);

				SetRelativeLocation(FMath::Lerp<FVector>(PreviousTransform.Location, CurrentTransform.Location, LerpAlpha));
				SetRelativeScale3D(FMath::Lerp<FVector>(PreviousTransform.Scale, CurrentTransform.Scale, LerpAlpha));
				SetRelativeRotation(FQuat::Slerp(PreviousTransform.Rotation.Quaternion(), CurrentTransform.Rotation.Quaternion(), LerpAlpha));
			}
		}
	}
}

void UMeshSwapperComponent::AnimationChangedPhysicsState()
{
	// If the frame has changed and we're using animated collision, we need to recreate that state as well
	RecreatePhysicsState();

	// We just totally changed the physics setup so update overlaps too
	UpdateOverlaps();
}

void UMeshSwapperComponent::TickAnimation(float DeltaTime, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds)
{
	bool bIsFinished = false;

	if (bPlaying)
	{
		const float TimelineLength = GetAnimationLength();
		const float EffectiveDeltaTime = DeltaTime * (bReversePlayback ? (-PlayRate) : (PlayRate));

		float NewPosition = AccumulatedTime + EffectiveDeltaTime;

		if (EffectiveDeltaTime > 0.0f)
		{
			if (NewPosition > TimelineLength)
			{
				if (bLooping)
				{
					// If looping, play to end, jump to start, and set target to somewhere near the beginning.
					SetPlaybackPosition(TimelineLength, bFireEvents, bSpawnParticles, bPlaySounds);
					SetPlaybackPosition(0.0f, bFireEvents, bSpawnParticles, bPlaySounds);

					if (TimelineLength > 0.0f)
					{
						while (NewPosition > TimelineLength)
						{
							NewPosition -= TimelineLength;
						}
					}
					else
					{
						NewPosition = 0.0f;
					}
				}
				else
				{
					// If not looping, snap to end and stop playing.
					NewPosition = TimelineLength;
					Stop();
					bIsFinished = true;
				}
			}
		}
		else
		{
			if (NewPosition < 0.0f)
			{
				if (bLooping)
				{
					// If looping, play to start, jump to end, and set target to somewhere near the end.
					SetPlaybackPosition(0.0f, bFireEvents, bSpawnParticles, bPlaySounds);
					SetPlaybackPosition(TimelineLength, bFireEvents, bSpawnParticles, bPlaySounds);

					if (TimelineLength > 0.0f)
					{
						while (NewPosition < 0.0f)
						{
							NewPosition += TimelineLength;
						}
					}
					else
					{
						NewPosition = 0.0f;
					}
				}
				else
				{
					// If not looping, snap to start and stop playing.
					NewPosition = 0.0f;
					Stop();
					bIsFinished = true;
				}
			}
		}

		SetPlaybackPosition(NewPosition, bFireEvents, bSpawnParticles, bPlaySounds);
	}

	// Notify user that the Animation finished playing
	if (bIsFinished)
	{
		OnFinishedPlaying.Broadcast();
	}

	// Update the frame and push it to the renderer if necessary
	CalculateCurrentFrame(bFireEvents, bSpawnParticles, bPlaySounds);
}

/// @cond DOXYGEN_WARNINGS

void UMeshSwapperComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UMeshSwapperComponent, SourceAnimation);
}

/// @endcond

void UMeshSwapperComponent::OnRep_SourceAnimation(class UMeshSwapAnimation* OldAnimation)
{
	if (OldAnimation != SourceAnimation)
	{
		// Force SetAnimation to change the animation (by default it won't change)
		UMeshSwapAnimation* NewAnimation = SourceAnimation;
		SourceAnimation = nullptr;

		SetAnimation(NewAnimation);
	}
}

void UMeshSwapperComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	SCOPE_CYCLE_COUNTER(STAT_TickAnimation);

	if (GetWorld() && GetWorld()->IsGameWorld())
	{
		// Advance time
		TickAnimation(DeltaTime, true, true, true);
	}
}


bool UMeshSwapperComponent::SetAnimation(class UMeshSwapAnimation* NewAnimation)
{
	if (NewAnimation != SourceAnimation)
	{
		// Don't allow changing the StaticMesh if we are "static".
		AActor* ComponentOwner = GetOwner();
		if ((ComponentOwner == nullptr) || AreDynamicDataChangesAllowed())
		{
			SourceAnimation = NewAnimation;

			// We need to also reset the frame and time also
			AccumulatedTime = 0.0f;
			CalculateCurrentFrame();

			return true;
		}
	}

	return false;
}


bool UMeshSwapperComponent::SetAnimation(class UMeshSwapAnimation* NewAnimation, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds)
{
	if (NewAnimation != SourceAnimation)
	{
		// Don't allow changing the StaticMesh if we are "static".
		AActor* ComponentOwner = GetOwner();
		if ((ComponentOwner == nullptr) || AreDynamicDataChangesAllowed())
		{
			SourceAnimation = NewAnimation;

			// We need to also reset the frame and time also
			AccumulatedTime = 0.0f;
			CalculateCurrentFrame(bFireEvents, bSpawnParticles, bPlaySounds);

			return true;
		}
	}

	return false;
}

UMeshSwapAnimation* UMeshSwapperComponent::GetAnimation()
{
	return SourceAnimation;
}

const UObject* UMeshSwapperComponent::AdditionalStatObject() const
{
	return SourceAnimation;
}

void UMeshSwapperComponent::Play()
{
	Activate();
	bReversePlayback = false;
	bPlaying = true;
}

void UMeshSwapperComponent::PlayFromStart(bool bFireEvents, bool bSpawnParticles, bool bPlaySounds)
{
	SetPlaybackPosition(0.0f, bFireEvents , bSpawnParticles , bPlaySounds );
	Play();
}

void UMeshSwapperComponent::Reverse()
{
	Activate();
	bReversePlayback = true;
	bPlaying = true;
}

void UMeshSwapperComponent::ReverseFromEnd(bool bFireEvents, bool bSpawnParticles, bool bPlaySounds)
{
	SetPlaybackPosition(GetAnimationLength(), bFireEvents , bSpawnParticles , bPlaySounds );
	Reverse();
}

void UMeshSwapperComponent::Stop()
{
	bPlaying = false;
}

bool UMeshSwapperComponent::IsPlaying() const
{
	return bPlaying;
}

bool UMeshSwapperComponent::IsReversing() const
{
	return bPlaying && bReversePlayback;
}

void UMeshSwapperComponent::SetPlaybackPositionInFrames(int32 NewFramePosition, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds)
{
	const float Framerate = GetAnimationFramerate();
	const float NewTime = (Framerate > 0.0f) ? (NewFramePosition / Framerate) : 0.0f;
	SetPlaybackPosition(NewTime, bFireEvents, bSpawnParticles, bPlaySounds);
}

int32 UMeshSwapperComponent::GetPlaybackPositionInFrames() const
{
	const float Framerate = GetAnimationFramerate();
	const int32 NumFrames = GetAnimationLengthInFrames();
	if (NumFrames > 0)
	{
		return FMath::Clamp<int32>(FMath::TruncToInt(AccumulatedTime * Framerate), 0, NumFrames - 1);
	}
	else
	{
		return 0;
	}
}

void UMeshSwapperComponent::SetPlaybackPosition(float NewPosition, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds)
{
	float OldPosition = AccumulatedTime;
	AccumulatedTime = NewPosition;


	if (OldPosition != AccumulatedTime)
	{
		CalculateCurrentFrame(bFireEvents, bSpawnParticles, bPlaySounds);
	}
}

float UMeshSwapperComponent::GetPlaybackPosition() const
{
	return AccumulatedTime;
}

void UMeshSwapperComponent::SetLooping(bool bNewLooping)
{
	bLooping = bNewLooping;
}

bool UMeshSwapperComponent::IsLooping() const
{
	return bLooping;
}

void UMeshSwapperComponent::SetPlayRate(float NewRate)
{
	PlayRate = NewRate;
}

float UMeshSwapperComponent::GetPlayRate() const
{
	return PlayRate;
}

void UMeshSwapperComponent::SetNewTime(float NewTime, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds)
{
	// Ensure value is sensible
	//@TODO: NewTime = FMath::Clamp<float>(NewTime, 0.0f, Length);

	SetPlaybackPosition(NewTime, bFireEvents, bSpawnParticles, bPlaySounds);
}

float UMeshSwapperComponent::GetAnimationLength() const
{
	return (SourceAnimation != nullptr) ? SourceAnimation->GetTotalDuration() : 0.0f;
}

int32 UMeshSwapperComponent::GetAnimationLengthInFrames() const
{
	return (SourceAnimation != nullptr) ? SourceAnimation->GetNumFrames() : 0;
}

float UMeshSwapperComponent::GetAnimationFramerate() const
{
	return (SourceAnimation != nullptr) ? SourceAnimation->GetFramesPerSecond() : 15.0f;
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
