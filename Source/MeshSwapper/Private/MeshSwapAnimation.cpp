//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapAnimation.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshSocket.h"
#include "MeshSwapperComponent.h"

#if WITH_EDITORONLY_DATA
#include "UObject/UObjectHash.h"
#include "ComponentReregisterContext.h"
#endif //WITH_EDITORONLY_DATA


//////////////////////////////////////////////////////////////////////////
// UMeshSwapAnimation

UMeshSwapAnimation::UMeshSwapAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, OutAnimation(nullptr)
	, InitialTransform(FKeyframeRelativeTransform())
{
	FramesPerSecond = 15;
}

float UMeshSwapAnimation::GetFramesPerSecond() const
{
	return FramesPerSecond;
}

int32 UMeshSwapAnimation::GetNumFrames() const
{
	int32 SumFrames = 0;
	for (int32 KeyFrameIndex = 0; KeyFrameIndex < KeyFrames.Num(); ++KeyFrameIndex)
	{
		SumFrames += KeyFrames[KeyFrameIndex].FrameRun;
	}

	return SumFrames;
}

float UMeshSwapAnimation::GetTotalDuration() const
{
	if (FramesPerSecond != 0)
	{
		return GetNumFrames() / FramesPerSecond;
	}

	return 0.0f;
}


float UMeshSwapAnimation::GetPositionAtKeyframeIndex(int32 KeyframeIndex) const
{
	int32 SumFrames = 0;

	if (KeyFrames.IsValidIndex(KeyframeIndex))
	{
		for (int32 KeyFrameIndex = 0; KeyFrameIndex < KeyframeIndex; ++KeyFrameIndex)
		{
			SumFrames += KeyFrames[KeyFrameIndex].FrameRun;
		}
	}

	if (FramesPerSecond != 0)
	{
		return SumFrames / FramesPerSecond;
	}

	return 0.0f;
}

int32 UMeshSwapAnimation::GetKeyFrameIndexAtTime(float Time, bool bClampToEnds) const
{
	if ((Time < 0.0f) && !bClampToEnds)
	{
		return INDEX_NONE;
	}

	if (FramesPerSecond > 0.0f)
	{
		float SumTime = 0.0f;

		for (int32 KeyFrameIndex = 0; KeyFrameIndex < KeyFrames.Num(); ++KeyFrameIndex)
		{
			SumTime += KeyFrames[KeyFrameIndex].FrameRun / FramesPerSecond;

			if (Time <= SumTime)
			{
				return KeyFrameIndex;
			}
		}

		// Return the last frame (note: relies on INDEX_NONE = -1 if there are no key frames)
		return KeyFrames.Num() - 1;
	}
	else
	{
		return (KeyFrames.Num() > 0) ? 0 : INDEX_NONE;
	}
}

UStaticMesh* UMeshSwapAnimation::GetStaticMeshAtTime(float Time, bool bClampToEnds /*= false*/) const
{
	const int32 KeyFrameIndex = GetKeyFrameIndexAtTime(Time, bClampToEnds);
	return KeyFrames.IsValidIndex(KeyFrameIndex) ? KeyFrames[KeyFrameIndex].StaticMesh : nullptr;
}

UStaticMesh* UMeshSwapAnimation::GetStaticMeshAtFrame(int32 FrameIndex) const
{
	return KeyFrames.IsValidIndex(FrameIndex) ? KeyFrames[FrameIndex].StaticMesh : nullptr;
}


FMeshKeyFrameData* UMeshSwapAnimation::GetKeyFrameDataAtFrame(int32 FrameIndex)
{
	return KeyFrames.IsValidIndex(FrameIndex) ? &KeyFrames[FrameIndex] : nullptr;
}


bool UMeshSwapAnimation::GetKeyFrameDataAtFrame(int32 FrameIndex, FMeshKeyFrameData& OutKeyframeData) const
{
	if (KeyFrames.IsValidIndex(FrameIndex))
	{
		OutKeyframeData = KeyFrames[FrameIndex];
		return true;
	}
	OutKeyframeData.FrameRun = -1;
	return false;
}


bool UMeshSwapAnimation::GetKeyFrameDataAtTime(float Time, FMeshKeyFrameData& OutKeyframeData, bool bClampToEnds /*= false*/) const
{
	const int32 KeyFrameIndex = GetKeyFrameIndexAtTime(Time, bClampToEnds);
	if (KeyFrames.IsValidIndex(KeyFrameIndex))
	{
		OutKeyframeData = KeyFrames[KeyFrameIndex];
		return true;
	}
	OutKeyframeData.FrameRun = -1;
	return false;
}

#if WITH_EDITOR
void UMeshSwapAnimation::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (FramesPerSecond < 0.0f)
	{
		FramesPerSecond = 0.0f;
	}

	//@TODO: Determine when this is really needed, as it is seriously expensive!
	TComponentReregisterContext<UMeshSwapperComponent> ReregisterAnimatedComponents;

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

FBoxSphereBounds UMeshSwapAnimation::GetRenderBounds() const
{
	FBoxSphereBounds MergedBoundingBox(ForceInit);
	bool bHasValidBounds = false;

	for (const FMeshKeyFrameData& KeyFrame : KeyFrames)
	{
		if (KeyFrame.StaticMesh != nullptr )
		{
			const FBoxSphereBounds FrameBounds = KeyFrame.StaticMesh->GetBounds();

			if (bHasValidBounds)
			{
				MergedBoundingBox = Union(MergedBoundingBox, FrameBounds);
			}
			else
			{
				MergedBoundingBox = FrameBounds;
				bHasValidBounds = true;
			}
		}
	}

	return MergedBoundingBox;
}

bool UMeshSwapAnimation::FindSocket(FName SocketName, int32 KeyFrameIndex, FTransform& OutLocalTransform)
{
	if (KeyFrames.IsValidIndex(KeyFrameIndex) && (SocketName != NAME_None))
	{
		if (UStaticMesh* StaticMesh = KeyFrames[KeyFrameIndex].StaticMesh)
		{
			if (UStaticMeshSocket* SocketInfo = StaticMesh->FindSocket(SocketName))
			{
				OutLocalTransform = FTransform(SocketInfo->RelativeRotation, SocketInfo->RelativeLocation, SocketInfo->RelativeScale);;
				return true;
			}
		}
	}

	return false;
}

bool UMeshSwapAnimation::HasAnySockets() const
{
	for (const FMeshKeyFrameData& KeyFrame : KeyFrames)
	{
		if (KeyFrame.StaticMesh != nullptr)
		{
			if (KeyFrame.StaticMesh->Sockets.Num() > 0)
			{
				return true;
			}
		}
	}

	return false;
}

bool UMeshSwapAnimation::DoesSocketExist(FName SocketName) const
{
	for (const FMeshKeyFrameData& KeyFrame : KeyFrames)
	{
		if (KeyFrame.StaticMesh != nullptr )
		{
			if (KeyFrame.StaticMesh->FindSocket(SocketName))
			{
				return true;
			}
		}
	}

	return false;
}

void UMeshSwapAnimation::QuerySupportedSockets(TArray<FComponentSocketDescription>& OutSockets) const
{
	TSet<FName> SocketNames;
	TArray<FComponentSocketDescription> FrameDescriptions;

	for (const FMeshKeyFrameData& KeyFrame : KeyFrames)
	{
		if (const UStaticMesh* StaticMesh = KeyFrame.StaticMesh)
		{
			FrameDescriptions.Reset();

			for (int32 SocketIndex = 0; SocketIndex < StaticMesh->Sockets.Num(); ++SocketIndex)
			{
				const UStaticMeshSocket* Socket = StaticMesh->Sockets[SocketIndex];
				new (OutSockets) FComponentSocketDescription(Socket->SocketName, EComponentSocketType::Socket);
			}

			for (const FComponentSocketDescription& FrameSocket : FrameDescriptions)
			{
				if (!SocketNames.Contains(FrameSocket.Name))
				{
					SocketNames.Add(FrameSocket.Name);
					OutSockets.Add(FrameSocket);
				}
			}
		}
	}
}

void UMeshSwapAnimation::InvalidateCachedData()
{
	// No cached data yet, but the functions that currently have to iterate over all frames can use cached data in the future
}

bool UMeshSwapAnimation::ContainsStaticMesh(UStaticMesh* KeyFrameAsset) const
{
	for (const FMeshKeyFrameData& KeyFrame : KeyFrames)
	{
		if (KeyFrame.StaticMesh == KeyFrameAsset)
		{
			return true;
		}
	}

	return false;
}
