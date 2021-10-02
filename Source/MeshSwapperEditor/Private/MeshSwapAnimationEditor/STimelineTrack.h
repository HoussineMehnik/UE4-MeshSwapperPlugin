//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once 

#include "CoreMinimal.h"
#include "Misc/Attribute.h"
#include "Input/DragAndDrop.h"
#include "Input/Reply.h"
#include "Layout/Margin.h"
#include "Widgets/SWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "Types/SlateStructs.h"
#include "ScopedTransaction.h"
#include "MeshSwapAnimation.h"
#include "SMeshSwapAnimationTimeline.h"

class FUICommandList;
class SHorizontalBox;

namespace FMeshSwapAnimationUIConstants
{
	const float HandleWidth = 12.0f;
	const float FrameHeight = 64;
	const float HeightBeforeFrames = 16;
	const FMargin FramePadding(0.0f, 7.0f, 0.0f, 7.0f);
};

//////////////////////////////////////////////////////////////////////////
// FMeshSwapAnimationKeyFrameDragDropOp

class FMeshSwapAnimationKeyFrameDragDropOp : public FDragDropOperation
{
public:
	DRAG_DROP_OPERATOR_TYPE(FMeshSwapAnimationKeyFrameDragDropOp, FDragDropOperation)

	float WidgetWidth;
	FMeshKeyFrameData KeyFrameData;
	int32 SourceFrameIndex;
	FText BodyText;
	TWeakObjectPtr<UMeshSwapAnimation> SourceMeshSwapAnimation;
	FScopedTransaction Transaction;

	// FDragDropOperation interface
	virtual TSharedPtr<SWidget> GetDefaultDecorator() const override;
	virtual void OnDragged(const class FDragDropEvent& DragDropEvent) override;
	virtual void Construct() override;
	virtual void OnDrop(bool bDropWasHandled, const FPointerEvent& MouseEvent) override;
	// End of FDragDropOperation interface

	void AppendToMeshSwapAnimation(UMeshSwapAnimation* DestinationMeshSwapAnimation);

	void InsertInMeshSwapAnimation(UMeshSwapAnimation* DestinationMeshSwapAnimation, int32 Index);

	void SetCanDropHere(bool bCanDropHere)
	{
		MouseCursor = bCanDropHere ? EMouseCursor::TextEditBeam : EMouseCursor::SlashedCircle;
	}

	static TSharedRef<FMeshSwapAnimationKeyFrameDragDropOp> New(int32 InWidth, UMeshSwapAnimation* InMeshSwapAnimation, int32 InFrameIndex);

protected:
	FMeshSwapAnimationKeyFrameDragDropOp();
};

//////////////////////////////////////////////////////////////////////////
// SMeshSwapAnimationKeyframeWidget

class SMeshSwapAnimationKeyframeWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMeshSwapAnimationKeyframeWidget)
		: _SlateUnitsPerFrame(1)
		, _MeshSwapAnimationBeingEdited(nullptr)
	{}

	SLATE_ATTRIBUTE(float, SlateUnitsPerFrame)
		SLATE_ATTRIBUTE(class UMeshSwapAnimation*, MeshSwapAnimationBeingEdited)
		SLATE_EVENT(FOnMeshSwapAnimationKeyframeSelectionChanged, OnSelectionChanged)

		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs, int32 InFrameIndex, TSharedPtr<FUICommandList> InCommandList);

	// SWidget interface
	virtual FReply OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
	// End of SWidget interface

protected:
	FReply KeyframeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

	FText GetKeyframeAssetName() const;
	FText GetKeyframeText() const;
	FText GetKeyframeTooltip() const;

	FText  GetKeyframeNotifyTag() const;
	void SetKeyframeNotifyTag(const FText& NewText, ETextCommit::Type TextType);
	FReply ClearKeyFrameTag();
	EVisibility GetNotifyWidgetVisibility() const;
	FText GetKeyframeNotifyTagTooltip() const;


	EVisibility GetParticesWidgetVisibility() const;
	FText GetKeyframeParticesTooltip() const;

	EVisibility GetSoundsWidgetVisibility() const;
	FText GetKeyframeSoundsTooltip() const;

	
	void OnResetTransform();
	bool CanResetTransform() const;

	void OnToggleSmoothTransform();
	bool CanSmoothTransform() const;

	void OnToggleCollision();
	bool IsCollisionEnabled() const;

	TSharedRef<SWidget> GenerateContextMenu();

	FOptionalSize GetFrameWidth() const;

	void OpenMeshKeyframePickerMenu(class FMenuBuilder& MenuBuilder);
	void OnAssetSelected(const struct FAssetData& AssetData);
	void CloseMenu();
	void ShowInContentBrowser();
	void EditKeyFrame();

	// Can return null
	const struct FMeshKeyFrameData* GetKeyFrameData() const;

protected:
	int32 FrameIndex;
	TAttribute<float> SlateUnitsPerFrame;
	TAttribute<class UMeshSwapAnimation*> MeshSwapAnimationBeingEdited;
	FOnMeshSwapAnimationKeyframeSelectionChanged OnSelectionChanged;
	TSharedPtr<FUICommandList> CommandList;
};

//////////////////////////////////////////////////////////////////////////
// SMeshSwapAnimationTimelineTrack

class SMeshSwapAnimationTimelineTrack : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMeshSwapAnimationTimelineTrack)
		: _SlateUnitsPerFrame(1)
		, _MeshSwapAnimationBeingEdited(nullptr)
	{}

		SLATE_ATTRIBUTE( float, SlateUnitsPerFrame )
		SLATE_ATTRIBUTE( class UMeshSwapAnimation*, MeshSwapAnimationBeingEdited )
		SLATE_EVENT( FOnMeshSwapAnimationKeyframeSelectionChanged, OnSelectionChanged )

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FUICommandList> InCommandList);

	void Rebuild();

private:
	TAttribute<float> SlateUnitsPerFrame;
	TAttribute< class UMeshSwapAnimation* > MeshSwapAnimationBeingEdited;

	TSharedPtr<SHorizontalBox> MainBoxPtr;

	float HandleWidth;

	FOnMeshSwapAnimationKeyframeSelectionChanged OnSelectionChanged;
	TSharedPtr<FUICommandList> CommandList;
};
