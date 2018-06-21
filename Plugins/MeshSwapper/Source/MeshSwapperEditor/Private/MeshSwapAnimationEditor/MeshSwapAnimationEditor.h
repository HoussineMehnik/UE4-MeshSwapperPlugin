// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/Reply.h"
#include "UObject/GCObject.h"
#include "Framework/Docking/TabManager.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "Editor/EditorWidgets/Public/ITransportControl.h"
#include "MeshSwapAnimation.h"



class SMeshSwapAnimationEditorViewport;
class UMeshSwapperComponent;
class UMeshSwapAnimation;

//////////////////////////////////////////////////////////////////////////
// FMeshSwapAnimationEditor

class FMeshSwapAnimationEditor : public FAssetEditorToolkit, public FGCObject
{
public:
	FMeshSwapAnimationEditor();

	// IToolkit interface
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;
	// End of IToolkit interface

	// FAssetEditorToolkit
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	// End of FAssetEditorToolkit

	// FSerializableObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	// End of FSerializableObject interface

public:
	void InitMeshSwapAnimationEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UMeshSwapAnimation* InitMeshSwapAnimation);

	UMeshSwapAnimation* GetMeshSwapAnimationBeingEdited() const { return MeshSwapAnimationBeingEdited; }

	UMeshSwapperComponent* GetPreviewComponent() const;
protected:
	UMeshSwapAnimation* MeshSwapAnimationBeingEdited;

	TSharedPtr<SMeshSwapAnimationEditorViewport> ViewportPtr;

	// Selection set
	int32 CurrentSelectedKeyframe;

	static FKeyframeRelativeTransform SavedTransform;

	// Range of times currently being viewed
	mutable float ViewInputMin;
	mutable float ViewInputMax;
	mutable float LastObservedSequenceLength;

protected:
	float GetFramesPerSecond() const
	{
		return MeshSwapAnimationBeingEdited->GetFramesPerSecond();
	}

	int32 GetCurrentFrame() const
	{
		const int32 TotalLengthInFrames = GetTotalFrameCount();

		if (TotalLengthInFrames == 0)
		{
			return INDEX_NONE;
		}
		else
		{
			return FMath::Clamp<int32>((int32)(GetPlaybackPosition() * GetFramesPerSecond()), 0, TotalLengthInFrames);
		}
	}

	void SetCurrentFrame(int32 NewIndex)
	{
		const int32 TotalLengthInFrames = GetTotalFrameCount();
		if (TotalLengthInFrames > 0)
		{
			int32 ClampedIndex = FMath::Clamp<int32>(NewIndex, 0, TotalLengthInFrames);
			SetPlaybackPosition(ClampedIndex / GetFramesPerSecond());
		}
		else
		{
			SetPlaybackPosition(0.0f);
		}
	}

protected:
	void BindCommands();
	void ExtendMenu();
	void ExtendToolbar();

	TSharedRef<SDockTab> SpawnTab_Viewport(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Details(const FSpawnTabArgs& Args);

	void DeleteSelection();
	void DuplicateSelection();
	void SetSelection(int32 NewSelection);
	bool HasValidSelection() const;

	void AddKeyFrameAtCurrentTime();
	void AddNewKeyFrameAtEnd();
	void AddNewKeyFrameBefore();
	void AddNewKeyFrameAfter();
	void CopySelectionTransform();
	void PasteSavedTransformToSelection();

	FReply OnClick_Forward();
	FReply OnClick_Forward_Step();
	FReply OnClick_Forward_End();
	FReply OnClick_Backward();
	FReply OnClick_Backward_Step();
	FReply OnClick_Backward_End();
	FReply OnClick_ToggleLoop();

	uint32 GetTotalFrameCount() const;
	uint32 GetTotalFrameCountPlusOne() const;
	float GetTotalSequenceLength() const;
	float GetPlaybackPosition() const;
	void SetPlaybackPosition(float NewTime);
	bool IsLooping() const;
	EPlaybackMode::Type GetPlaybackMode() const;

	float GetViewRangeMin() const;
	float GetViewRangeMax() const;
	void SetViewRange(float NewMin, float NewMax);
};
