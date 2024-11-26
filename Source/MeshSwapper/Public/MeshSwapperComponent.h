//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once


#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Particles/ParticleSystem.h"
#include "Engine/EngineTypes.h"
#include "Components/StaticMeshComponent.h"
#include "MeshSwapAnimation.h"
#include "MeshSwapperComponent.generated.h"



class UBodySetup;
class UMeshSwapAnimation;
class UNiagaraComponent;
struct FMeshKeyFrameData;


// Event for a non-looping animation finishing play
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnimationFinishedPlaySignature);

/* Keyframe Notify Event Delegate  */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FKeyframeNotifyEvent, FString, NotifyTag, int32, FrameIndex);


UCLASS(ShowCategories=(Mobility, ComponentReplication), ClassGroup = "Mesh Swapper", meta=(BlueprintSpawnableComponent))
class MESHSWAPPER_API UMeshSwapperComponent : public UStaticMeshComponent
{
	GENERATED_UCLASS_BODY()

protected:
	/** Animation currently being played */
	UPROPERTY(Category = "MeshSwapAnimation", EditAnywhere, meta = (DisplayThumbnail = "true"), ReplicatedUsing = OnRep_SourceAnimation)
		UMeshSwapAnimation* SourceAnimation;


	/** Current play rate of the Animation */
	UPROPERTY(Category = "MeshSwapAnimation", EditAnywhere, Replicated)
		float PlayRate;

	/** Whether the Animation should loop when it reaches the end, or stop */
	UPROPERTY(Replicated)
		uint32 bLooping : 1;

	/** If playback should move the current position backwards instead of forwards */
	UPROPERTY(Replicated)
		uint32 bReversePlayback : 1;

	/** Are we currently playing (moving Position) */
	UPROPERTY(Replicated)
		uint32 bPlaying : 1;

	/** Current position in the timeline */
	UPROPERTY(Replicated)
		float AccumulatedTime;

	/** Last frame index calculated */
	UPROPERTY()
		int32 CachedFrameIndex;

	/** The cached body setup */
	UPROPERTY(Transient)
		UBodySetup* CachedBodySetup;

public:
	/** Event called whenever a non-looping Animation finishes playing (either reaching the beginning or the end, depending on the play direction) */
	UPROPERTY(BlueprintAssignable)
		FAnimationFinishedPlaySignature OnFinishedPlaying;

	UPROPERTY(BlueprintAssignable)
		FKeyframeNotifyEvent OnAnimationNotifyEvent;
public:
	/** Change the Animation used by this instance (will reset the play time to 0 if it is a new Animation). */
	UFUNCTION(BlueprintCallable, Category = "MeshSwapAnimation")
		virtual bool SetAnimation(class UMeshSwapAnimation* NewAnimation);

	virtual bool SetAnimation(class UMeshSwapAnimation* NewAnimation, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds);

	/** Gets the Animation used by this instance. */
	UFUNCTION(BlueprintPure, Category = "MeshSwapAnimation")
		virtual UMeshSwapAnimation* GetAnimation();

	/** Start playback of Animation */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void Play();

	/** Start playback of Animation from the start */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void PlayFromStart( bool bFireEvents, bool bSpawnParticles, bool bPlaySounds);

	/** Start playback of Animation in reverse */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void Reverse();

	/** Start playback of Animation in reverse from the end */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void ReverseFromEnd( bool bFireEvents, bool bSpawnParticles, bool bPlaySounds);

	/** Stop playback of Animation */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void Stop();

	/** Get whether this Animation is playing or not. */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		bool IsPlaying() const;

	/** Get whether we are reversing or not */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		bool IsReversing() const;

	/** Jump to a position in the Animation (expressed in frames). */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void SetPlaybackPositionInFrames(int32 NewFramePosition, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds);

	/** Get the current playback position (in frames) of the Animation */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		int32 GetPlaybackPositionInFrames() const;

	/** Jump to a position in the Animation (expressed in seconds). */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void SetPlaybackPosition(float NewPosition, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds);


	/** Get the current playback position (in seconds) of the Animation */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		float GetPlaybackPosition() const;

	/** true means we should loop, false means we should not. */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void SetLooping(bool bNewLooping);

	/** Get whether we are looping or not */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		bool IsLooping() const;

	/** Sets the new play rate for this Animation */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void SetPlayRate(float NewRate);

	/** Get the current play rate for this Animation */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		float GetPlayRate() const;

	/** Set the new playback position time to use */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		void SetNewTime(float NewTime, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds);

	/** Get length of the Animation (in seconds) */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		float GetAnimationLength() const;

	/** Get length of the Animation (in frames) */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		int32 GetAnimationLengthInFrames() const;

	/** Get the nominal framerate that the Animation will be played back at (ignoring PlayRate), in frames per second */
	UFUNCTION(BlueprintCallable, Category = "Components|MeshSwapAnimation")
		float GetAnimationFramerate() const;

protected:
	UFUNCTION()
		void OnRep_SourceAnimation(class UMeshSwapAnimation* OldAnimation);

	void CalculateCurrentFrame( bool bFireEvents = true, bool bSpawnParticles= true, bool bPlaySounds= true);


	void AnimationChangedPhysicsState();

	public:
		int32 GetCachedFrameIndex() const;
		UStaticMesh* GetStaticMeshAtCachedIndex() const;
		FMeshKeyFrameData* GetKeyframeDataAtCachedIndex() const;

public:
	// UActorComponent interface
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual const UObject* AdditionalStatObject() const override;
	// End of UActorComponent interface


	// UPrimitiveComponent interface
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	virtual UBodySetup* GetBodySetup() override;
	// End of UPrimitiveComponent interface

	void TickAnimation(float DeltaTime, bool bFireEvents, bool bSpawnParticles, bool bPlaySounds);

private:
	FVector LastKeyframeLocation;
	FRotator LastKeyframeRotation;
	FVector LastKeyframeScale;
};
