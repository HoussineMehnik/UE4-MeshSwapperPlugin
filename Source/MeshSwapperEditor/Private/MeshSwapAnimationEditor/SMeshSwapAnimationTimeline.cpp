//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapAnimationEditor/SMeshSwapAnimationTimeline.h"
#include "Rendering/DrawElements.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SOverlay.h"
#include "Layout/WidgetPath.h"
#include "Framework/Application/MenuStack.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBox.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Colors/SColorBlock.h"
#include "EditorStyleSet.h"
#include "DragAndDrop/AssetDragDropOp.h"
#include "ScopedTransaction.h"
#include "Engine/StaticMesh.h"



#include "MeshSwapAnimationEditor/STimelineHeader.h"
#include "STimelineTrack.h"
#include "MeshSwapAnimation.h"
#include "MeshSwapAnimationEditorCommands.h"

#define LOCTEXT_NAMESPACE "MeshSwapAnimationEditor"

//////////////////////////////////////////////////////////////////////////
// SMeshSwapAnimationTimeline

void SMeshSwapAnimationTimeline::Construct(const FArguments& InArgs, TSharedPtr<FUICommandList> InCommandList)
{
	MeshSwapAnimationBeingEdited = InArgs._MeshSwapAnimationBeingEdited;
	PlayTime = InArgs._PlayTime;
	OnSelectionChanged = InArgs._OnSelectionChanged;
	CommandList = InCommandList;

	SlateUnitsPerFrame = 120.0f;

	BackgroundPerFrameSlices = SNew(SHorizontalBox);

	TimelineHeader = SNew(STimelineHeader)
		.SlateUnitsPerFrame(this, &SMeshSwapAnimationTimeline::GetSlateUnitsPerFrame)
		.MeshSwapAnimationBeingEdited(MeshSwapAnimationBeingEdited)
		.PlayTime(PlayTime);

	TimelineTrack = SNew(SMeshSwapAnimationTimelineTrack, CommandList)
		.SlateUnitsPerFrame(this, &SMeshSwapAnimationTimeline::GetSlateUnitsPerFrame)
		.MeshSwapAnimationBeingEdited(MeshSwapAnimationBeingEdited)
		.OnSelectionChanged(OnSelectionChanged);

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
		[
			SNew(SScrollBox)
			.Orientation(Orient_Horizontal)
			.ScrollBarAlwaysVisible(true)
			.OnUserScrolled(this, &SMeshSwapAnimationTimeline::AnimationScrollBar_OnUserScrolled)
			+SScrollBox::Slot()
			[
				SNew(SOverlay)

				// Per-frame background
				+SOverlay::Slot()
				.VAlign(VAlign_Fill)
				[
					BackgroundPerFrameSlices.ToSharedRef()
				]

				// MeshSwapAnimation header and track
				+SOverlay::Slot()
				[
					SNew(SVerticalBox)
		
					+SVerticalBox::Slot()
					.AutoHeight()
					.Padding(0,0,0,2)
					[
						TimelineHeader.ToSharedRef()
					]

					+SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SBox)
						.HeightOverride(FMeshSwapAnimationUIConstants::FrameHeight)
						[
							TimelineTrack.ToSharedRef()
						]
					]
				]

				// Empty MeshSwapAnimation instructions
				+ SOverlay::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				[
					SNew(STextBlock)
					.Visibility(this, &SMeshSwapAnimationTimeline::NoFramesWarningVisibility)
					.Text(LOCTEXT("EmptyTimelineInstruction", "Right-click here or drop in mesh keyframes to add new key frames"))
				]
			]
		]
	];

	UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
	NumKeyFramesFromLastRebuild = (MeshSwapAnimation != nullptr) ? MeshSwapAnimation->GetNumKeyFrames() : 0;
	NumFramesFromLastRebuild = (MeshSwapAnimation != nullptr) ? MeshSwapAnimation->GetNumFrames() : 0;
	RebuildPerFrameBG();
}

void SMeshSwapAnimationTimeline::OnDragEnter(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	SCompoundWidget::OnDragEnter(MyGeometry, DragDropEvent);

	TSharedPtr<FDragDropOperation> Operation = DragDropEvent.GetOperation();
	if (!Operation.IsValid())
	{
	}
	else if (Operation->IsOfType<FMeshSwapAnimationKeyFrameDragDropOp>())
	{
		const auto& FrameDragDropOp = StaticCastSharedPtr<FMeshSwapAnimationKeyFrameDragDropOp>(Operation);
		FrameDragDropOp->SetCanDropHere(true);
	}
}

void SMeshSwapAnimationTimeline::OnDragLeave(const FDragDropEvent& DragDropEvent)
{
	SCompoundWidget::OnDragLeave(DragDropEvent);

	TSharedPtr<FDragDropOperation> Operation = DragDropEvent.GetOperation();
	if (!Operation.IsValid())
	{
	}
	else if (Operation->IsOfType<FMeshSwapAnimationKeyFrameDragDropOp>())
	{
		const auto& FrameDragDropOp = StaticCastSharedPtr<FMeshSwapAnimationKeyFrameDragDropOp>(Operation);
		FrameDragDropOp->SetCanDropHere(false);
	}
}

FReply SMeshSwapAnimationTimeline::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	bool bWasDropHandled = false;

	TSharedPtr<FDragDropOperation> Operation = DragDropEvent.GetOperation();
	if (!Operation.IsValid())
	{
	}
	else if (Operation->IsOfType<FAssetDragDropOp>())
	{
		const auto& AssetDragDropOp = StaticCastSharedPtr<FAssetDragDropOp>(Operation);
		OnAssetsDropped(*AssetDragDropOp);
		bWasDropHandled = true;
	}
	else if (Operation->IsOfType<FMeshSwapAnimationKeyFrameDragDropOp>())
	{
		const auto& FrameDragDropOp = StaticCastSharedPtr<FMeshSwapAnimationKeyFrameDragDropOp>(Operation);
		if (UMeshSwapAnimation* ThisMeshSwapAnimation = MeshSwapAnimationBeingEdited.Get())
		{
			FrameDragDropOp->AppendToMeshSwapAnimation(ThisMeshSwapAnimation);
			bWasDropHandled = true;
		}
	}

	return bWasDropHandled ? FReply::Handled() : FReply::Unhandled();
}

void SMeshSwapAnimationTimeline::OnAssetsDropped(const class FAssetDragDropOp& DragDropOp)
{
	//@TODO: Support inserting in addition to dropping at the end
	TArray<FMeshKeyFrameData> NewFrames;
	for (const FAssetData& AssetData : DragDropOp.GetAssets())
	{
		if (UObject* Object = AssetData.GetAsset())
		{
			if (UStaticMesh* StaticMesh = Cast<UStaticMesh>(Object))
			{
				// Insert this Mesh keyframe as a keyframe
				FMeshKeyFrameData& NewFrame = *new (NewFrames) FMeshKeyFrameData();
				NewFrame.StaticMesh = StaticMesh;
			}
			else if (UMeshSwapAnimation* MeshSwapAnimationAsset = Cast<UMeshSwapAnimation>(Object))
			{
				// Insert all of the keyframes from the other MeshSwapAnimation into this one
				for (int32 KeyIndex = 0; KeyIndex < MeshSwapAnimationAsset->GetNumKeyFrames(); ++KeyIndex)
				{
					const FMeshKeyFrameData& OtherMeshSwapAnimationFrame = MeshSwapAnimationAsset->GetKeyFrameChecked(KeyIndex);
					FMeshKeyFrameData& NewFrame = *new (NewFrames) FMeshKeyFrameData();
					NewFrame = OtherMeshSwapAnimationFrame;
				}
			}
		}
	}

	UMeshSwapAnimation* ThisMeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
	if (NewFrames.Num() && (ThisMeshSwapAnimation != nullptr))
	{
		const FScopedTransaction Transaction(LOCTEXT("DroppedAssetOntoTimeline", "Insert assets as frames"));
		ThisMeshSwapAnimation->Modify();

		FScopedMeshSwapAnimationMutator EditLock(ThisMeshSwapAnimation);
		EditLock.KeyFrames.Append(NewFrames);
	}
}

int32 SMeshSwapAnimationTimeline::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	LayerId = SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	const float CurrentTimeSecs = PlayTime.Get();
	UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
	const float TotalTimeSecs = (MeshSwapAnimation != nullptr) ? MeshSwapAnimation->GetTotalDuration() : 0.0f;
	const int32 TotalNumFrames = (MeshSwapAnimation != nullptr) ? MeshSwapAnimation->GetNumFrames() : 0;

	const float SlateTotalDistance = SlateUnitsPerFrame * TotalNumFrames;
	const float CurrentTimeXPos = (((CurrentTimeSecs / TotalTimeSecs) * SlateTotalDistance) - AnimationScrollBarPosition) + FMath::Clamp((AllottedGeometry.GetLocalSize().X + AnimationScrollBarPosition) - SlateTotalDistance, 0.0f, AnimationScrollBarPosition);

	// Draw a line for the current scrub cursor
	++LayerId;
	TArray<FVector2D> LinePoints;
	LinePoints.Add(FVector2D(CurrentTimeXPos, 0.f));
	LinePoints.Add(FVector2D(CurrentTimeXPos, AllottedGeometry.GetLocalSize().Y));

	FSlateDrawElement::MakeLines(
		OutDrawElements,
		LayerId,
		AllottedGeometry.ToPaintGeometry(),
		LinePoints,
		ESlateDrawEffect::None,
		FLinearColor::Red
		);

	return LayerId;
}

FReply SMeshSwapAnimationTimeline::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.IsControlDown())
	{
		const float DirectionScale = 0.08f;
		const float MinFrameSize = 16.0f;
		const float Direction = MouseEvent.GetWheelDelta();
		const float NewUnitsPerFrame = FMath::Max(MinFrameSize, SlateUnitsPerFrame * (1.0f + Direction * DirectionScale));
		SlateUnitsPerFrame = NewUnitsPerFrame;
		
		CheckForRebuild(/*bRebuildAll=*/ true);

		return FReply::Handled();
	}
	else
	{
		return FReply::Unhandled();
	}
}

TSharedRef<SWidget> SMeshSwapAnimationTimeline::GenerateContextMenu()
{
	FMenuBuilder MenuBuilder(true, CommandList);
	MenuBuilder.BeginSection("KeyframeActions", LOCTEXT("KeyframeActionsSectionHeader", "Keyframe Actions"));

	// 		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Cut);
	// 		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Copy);
	// 		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Paste);
	MenuBuilder.AddMenuEntry(FMeshSwapAnimationEditorCommands::Get().AddNewFrame);

	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}

FReply SMeshSwapAnimationTimeline::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		TSharedRef<SWidget> MenuContents = GenerateContextMenu();
		FWidgetPath WidgetPath = MouseEvent.GetEventPath() != nullptr ? *MouseEvent.GetEventPath() : FWidgetPath();
		FSlateApplication::Get().PushMenu(AsShared(), WidgetPath, MenuContents, MouseEvent.GetScreenSpacePosition(), FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));

		return FReply::Handled();
	}
	else
	{
		return FReply::Unhandled();
	}
}

void SMeshSwapAnimationTimeline::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	CheckForRebuild();
}

void SMeshSwapAnimationTimeline::CheckForRebuild(bool bRebuildAll)
{
	UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();

	const int32 NewNumKeyframes = (MeshSwapAnimation != nullptr) ? MeshSwapAnimation->GetNumKeyFrames() : 0;
	if ((NewNumKeyframes != NumKeyFramesFromLastRebuild) || bRebuildAll)
	{
		NumKeyFramesFromLastRebuild = NewNumKeyframes;
		TimelineTrack->Rebuild();
	}

	const int32 NewNumFrames = (MeshSwapAnimation != nullptr) ? MeshSwapAnimation->GetNumFrames() : 0;
	if ((NewNumFrames != NumFramesFromLastRebuild) || bRebuildAll)
	{
		NumFramesFromLastRebuild = NewNumFrames;
		TimelineHeader->Rebuild();
		RebuildPerFrameBG();
	}
}

EVisibility SMeshSwapAnimationTimeline::NoFramesWarningVisibility() const
{
	UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
	const int32 TotalNumFrames = (MeshSwapAnimation != nullptr) ? MeshSwapAnimation->GetNumFrames() : 0;
	return (TotalNumFrames == 0) ? EVisibility::Visible : EVisibility::Collapsed;
}

void SMeshSwapAnimationTimeline::RebuildPerFrameBG()
{
	const FLinearColor BackgroundColors[2] = { FLinearColor(1.0f, 1.0f, 1.0f, 0.05f), FLinearColor(0.0f, 0.0f, 0.0f, 0.05f) };

	BackgroundPerFrameSlices->ClearChildren();
	for (int32 FrameIndex = 0; FrameIndex < NumFramesFromLastRebuild; ++FrameIndex)
	{
		const FLinearColor& BackgroundColorForFrameIndex = BackgroundColors[FrameIndex & 1];

		BackgroundPerFrameSlices->AddSlot()
		.AutoWidth()
		[
			SNew(SBox)
			.WidthOverride(SlateUnitsPerFrame)
			[
				SNew(SColorBlock)
				.Color(BackgroundColorForFrameIndex)
			]
		];
	}
}

void SMeshSwapAnimationTimeline::AnimationScrollBar_OnUserScrolled(float ScrollOffset)
{
	AnimationScrollBarPosition = ScrollOffset;
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
