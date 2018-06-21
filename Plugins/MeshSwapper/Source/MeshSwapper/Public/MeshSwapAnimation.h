// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "UObject/ScriptMacros.h"
#include "MeshSwapAnimation.generated.h"

class USoundBase;
class UParticleSystem;


USTRUCT(BlueprintType)
struct MESHSWAPPER_API FKeyframeRelativeTransform
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh Keyframe")
		FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh Keyframe")
		FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh Keyframe")
		FVector Scale;

	FTransform ToTransform() const
	{
		return FTransform(Rotation, Location, Scale);
	}

	void Reset()
	{
		Rotation = FRotator::ZeroRotator;
		Location = FVector::ZeroVector;
		Scale = FVector::OneVector;
	}

	FKeyframeRelativeTransform()
		: Rotation(ForceInit)
		, Location(ForceInit)
		, Scale(FVector::OneVector)
	{

	}

};

USTRUCT(BlueprintType)
struct MESHSWAPPER_API FMeshKeyFrameSoundEffectData
{
	GENERATED_USTRUCT_BODY()

public:

	// Sound to Play
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MeshAnimNotify")
		USoundBase* Sound;

	// Volume Multiplier
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MeshAnimNotify")
		float VolumeMultiplier;

	// Pitch Multiplier
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MeshAnimNotify")
		float PitchMultiplier;

	// If this sound should follow its owner
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MeshAnimNotify")
		uint32 bFollow : 1;

	// Socket or bone name to attach sound to
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MeshAnimNotify", meta = (EditCondition = "bFollow"))
		FName AttachName;


	FMeshKeyFrameSoundEffectData()
		:Sound(nullptr)
		, VolumeMultiplier(1.0f)
		, PitchMultiplier(1.0f)
		, bFollow(true)
		, AttachName(NAME_None)
	{
	}

};

USTRUCT(BlueprintType)
struct MESHSWAPPER_API FMeshKeyFrameParticleEffectData
{
	GENERATED_USTRUCT_BODY()

public:

	// The particle system template to use when spawning the particle component
	UPROPERTY(EditAnywhere, Category = MeshAnimNotify, meta = (ToolTip = "The particle system to spawn for the notify state"))
		UParticleSystem* PSTemplate;

	// The socket within our mesh component to attach to when we spawn the particle component
	UPROPERTY(EditAnywhere, Category = MeshAnimNotify, meta = (ToolTip = "The socket or bone to attach the system to"))
		FName SocketName;

	// Offset from the socket / bone location
	UPROPERTY(EditAnywhere, Category = MeshAnimNotify, meta = (ToolTip = "Offset from the socket or bone to place the particle system"))
		FVector LocationOffset;

	// Offset from the socket / bone rotation
	UPROPERTY(EditAnywhere, Category = MeshAnimNotify, meta = (ToolTip = "Rotation offset from the socket or bone for the particle system"))
		FRotator RotationOffset;

	// Whether or not we destroy the component at the end of the notify or instead just stop
	// the emitters.
	UPROPERTY(EditAnywhere, Category = MeshAnimNotify, meta = (DisplayName = "Destroy Immediately", ToolTip = "Whether the particle system should be immediately destroyed at the end of the notify state or be allowed to finish"))
		bool bAutoDestroy;


	FMeshKeyFrameParticleEffectData()
		: PSTemplate(nullptr)
		, LocationOffset(ForceInit)
		, RotationOffset((ForceInit))
		, bAutoDestroy(true)
		, SocketName(NAME_None)
	{
	}

};


USTRUCT(BlueprintType)
struct MESHSWAPPER_API FMeshKeyFrameData
{
	GENERATED_USTRUCT_BODY()

public:


	UPROPERTY(Category = "KeyFrame", EditAnywhere, BlueprintReadOnly, meta = (DisplayThumbnail = "true"))
		UStaticMesh* StaticMesh;

	UPROPERTY(Category = "KeyFrame", EditAnywhere, BlueprintReadOnly, meta = (ClampMin = 1))
		int32 FrameRun;

	UPROPERTY(Category = "KeyFrame", EditAnywhere, BlueprintReadOnly)
		FString NotifyTag;

	UPROPERTY(Category = "KeyFrame", EditAnywhere, BlueprintReadOnly)
		TArray< FMeshKeyFrameParticleEffectData> ParticleEffects;

	UPROPERTY(Category = "KeyFrame", EditAnywhere, BlueprintReadOnly)
		TArray< FMeshKeyFrameSoundEffectData> SoundEffects;

	UPROPERTY(Category = "KeyFrame", EditAnywhere, BlueprintReadOnly)
		FKeyframeRelativeTransform RelativeTransform;

	UPROPERTY(Category = "KeyFrame", EditAnywhere, BlueprintReadOnly)
		bool bSmoothTransformInterpolation;

	UPROPERTY(Category = "KeyFrame", EditAnywhere, BlueprintReadOnly)
		bool bEnableCollision;

	FMeshKeyFrameData()
		: StaticMesh(nullptr)
		, FrameRun(1)
		, NotifyTag(TEXT(""))
		, bSmoothTransformInterpolation(false)
		, bEnableCollision(true)
		, RelativeTransform(FKeyframeRelativeTransform())
	{
		ParticleEffects.Empty();
		SoundEffects.Empty();
	}
};

UENUM()
namespace  EMeshAnimCollisionMode
{
	enum Type
	{
		/** the animation clip has no collision */
		NoCollision,

		/** the animation clip has non-animated collision based on the first frame of the animation */
		FirstFrameCollision,

		/** the animation clip changes collision each frame based on the animation (Note: This setting is not recommended and is very expensive, recreating the physics state every frame) */
		EachFrameCollision,
	};
}

/**
 * Contains an animation sequence of static mesh frames
 */
UCLASS(BlueprintType,meta = (DisplayThumbnail = "true"))
class MESHSWAPPER_API UMeshSwapAnimation : public UObject
{
	GENERATED_UCLASS_BODY()

protected:


	// Collision source
	UPROPERTY(Category = "MeshSwapAnimation", EditAnywhere, BlueprintReadOnly)
		TEnumAsByte<EMeshAnimCollisionMode::Type> CollisionSource;

	// The nominal frame rate to play this animation clip back at
	UPROPERTY(Category="MeshSwapAnimation", EditAnywhere, BlueprintReadOnly, meta=(ClampMin=0, ClampMax=1000))
	float FramesPerSecond;

	UPROPERTY(Category = "MeshSwapAnimation", EditAnywhere, BlueprintReadOnly)
		UMeshSwapAnimation* OutAnimation;


	// The set of key frames for this animation clip
	UPROPERTY(Category="MeshSwapAnimation", EditAnywhere)
	TArray<FMeshKeyFrameData> KeyFrames;

public:

	UPROPERTY(Category = "MeshSwapAnimation", EditAnywhere, BlueprintReadOnly)
		FKeyframeRelativeTransform InitialTransform;

public:
	// Returns the collision source of this animation clip (if any)
	TEnumAsByte<EMeshAnimCollisionMode::Type> GetCollisionSource() const { return CollisionSource; }

	// Returns the nominal frame rate to play this animation clip back at
	float GetFramesPerSecond() const;

	// Returns the total number of frames
	UFUNCTION(BlueprintCallable, Category="MeshSwapAnimation")
	int32 GetNumFrames() const;

	// Returns the total duration in seconds
	UFUNCTION(BlueprintCallable, Category = "MeshSwapAnimation")
		float GetTotalDuration() const;

	UFUNCTION(BlueprintCallable, Category = "MeshSwapAnimation")
		float GetPositionAtKeyframeIndex(int32 KeyframeIndex) const;

	// Returns the keyframe index that covers the specified time (in seconds), or INDEX_NONE if none exists.
	// When bClampToEnds is true, it will choose the first or last keyframe if the time is out of range.
	UFUNCTION(BlueprintCallable, Category="MeshSwapAnimation")
	int32 GetKeyFrameIndexAtTime(float Time, bool bClampToEnds = false) const;

	// Returns the key at the specified time (in seconds), or nullptr if none exists.
	// When bClampToEnds is true, it will choose the first or last key if the time is out of range.
	UFUNCTION(BlueprintCallable, Category="MeshSwapAnimation")
	UStaticMesh* GetStaticMeshAtTime(float Time, bool bClampToEnds = false) const;

	// Returns the key at the specified keyframe index, or nullptr if none exists
	UFUNCTION(BlueprintCallable, Category="MeshSwapAnimation")
	 UStaticMesh* GetStaticMeshAtFrame(int32 FrameIndex) const;

	// Returns the key data at the specified keyframe index
	UFUNCTION(BlueprintCallable, Category = "MeshSwapAnimation")
		bool GetKeyFrameDataAtFrame(int32 FrameIndex, FMeshKeyFrameData& OutKeyframeData) const;

	// Returns the key data at the specified time (in seconds),
	// When bClampToEnds is true, it will choose the first or last key if the time is out of range.
	UFUNCTION(BlueprintCallable, Category = "MeshSwapAnimation")
		bool GetKeyFrameDataAtTime(float Time, FMeshKeyFrameData& OutKeyframeData, bool bClampToEnds = false) const;

	FMeshKeyFrameData* GetKeyFrameDataAtFrame(int32 FrameIndex);

	// Returns the render bounds of this mesh
	FBoxSphereBounds GetRenderBounds() const;

	// Returns the number of key frames
	UFUNCTION(BlueprintCallable, Category="MeshSwapAnimation")
	int32 GetNumKeyFrames() const
	{
		return KeyFrames.Num();
	}

	// Is the specified Index within the valid range of key frames?
	UFUNCTION(BlueprintCallable, Category="MeshSwapAnimation")
	bool IsValidKeyFrameIndex(int32 Index) const
	{
		return KeyFrames.IsValidIndex(Index);
	}

	// Returns the key frame at the specified index, make sure the index is valid before use
	const FMeshKeyFrameData& GetKeyFrameChecked(int32 Index) const
	{
		return KeyFrames[Index];
	}

	// Search for a socket at the specified frame
	bool FindSocket(FName SocketName, int32 KeyFrameIndex, FTransform& OutLocalTransform);

	// Returns true if the animation clip has any sockets
	bool HasAnySockets() const;

	// Returns true if the animation clip has a specific named socket
	bool DoesSocketExist(FName SocketName) const;

	// Returns a list of all of the sockets
	void QuerySupportedSockets(TArray<FComponentSocketDescription>& OutSockets) const;

	// Rebuilds cached data about the animation (such as total number of frames that the keyframes span, etc...)
	void InvalidateCachedData();

	//~ Begin UObject Interface
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	//~ End UObject Interface

	// Returns true if the animclip asset contains the specified keyframe asset in any frames
	bool ContainsStaticMesh(UStaticMesh* KeyFrameAsset) const;

private:
	friend class FScopedMeshSwapAnimationMutator;
};


// Helper class to edit properties of a UMeshSwapAnimation while ensuring that cached data remains up to date
class FScopedMeshSwapAnimationMutator
{
public:
	float& FramesPerSecond;
	TArray<FMeshKeyFrameData>& KeyFrames;

private:
	UMeshSwapAnimation* SourceClip;

public:
	FScopedMeshSwapAnimationMutator(UMeshSwapAnimation* InClip)
		: FramesPerSecond(InClip->FramesPerSecond)
		, KeyFrames(InClip->KeyFrames)
		, SourceClip(InClip)
	{
	}

	~FScopedMeshSwapAnimationMutator()
	{
		InvalidateCachedData();
	}

	void InvalidateCachedData()
	{
		SourceClip->InvalidateCachedData();
	}

	UMeshSwapAnimation* GetSourceAnimClip() const
	{
		return SourceClip;
	}
};
