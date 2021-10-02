//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once

#include "CoreMinimal.h"
#include "Misc/Attribute.h"
#include "InputCoreTypes.h"
#include "Input/CursorReply.h"
#include "Input/Reply.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Images/SImage.h"
#include "MeshSwapperStyle.h"
#include "MeshSwapAnimation.h"


#define LOCTEXT_NAMESPACE "SMeshSwapAnimationTrackHandle"

//////////////////////////////////////////////////////////////////////////
// SMeshSwapAnimationTrackHandle

// This is the grab handle at the end of a frame region, which can be dragged to change the duration
class SMeshSwapAnimationTrackHandle : public SImage
{
public:
	SLATE_BEGIN_ARGS(SMeshSwapAnimationTrackHandle)
		: _SlateUnitsPerFrame(1)
		, _MeshSwapAnimationBeingEdited(nullptr)
		, _KeyFrameIdx(INDEX_NONE)
	{}

		SLATE_ATTRIBUTE( float, SlateUnitsPerFrame )
		SLATE_ATTRIBUTE( class UMeshSwapAnimation*, MeshSwapAnimationBeingEdited )
		SLATE_ARGUMENT( int32, KeyFrameIdx )
		
	SLATE_END_ARGS()



	void Construct(const FArguments& InArgs)
	{
		SlateUnitsPerFrame = InArgs._SlateUnitsPerFrame;
		MeshSwapAnimationBeingEdited = InArgs._MeshSwapAnimationBeingEdited;
		KeyFrameIdx = InArgs._KeyFrameIdx;

		DistanceDragged = 0;
		bDragging = false;
		StartingFrameRun = INDEX_NONE;

		const FLinearColor ImageColor = IsTimelineStartHandle() ? FLinearColor::Red : FLinearColor::White;

		SImage::Construct(
			SImage::FArguments()
			.Image(FMeshSwapperStyle::Get()->GetBrush("MeshSwapAnimationEditor.RegionGrabHandle"))
			.ColorAndOpacity(ImageColor));


		UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
		if (MeshSwapAnimation && MeshSwapAnimation->IsValidKeyFrameIndex(KeyFrameIdx))
		{
			const FMeshKeyFrameData& KeyFrame = MeshSwapAnimation->GetKeyFrameChecked(KeyFrameIdx);
			const FKeyframeRelativeTransform& RelativeTransform = KeyFrame.RelativeTransform;
			SetToolTipText(FText::Format(LOCTEXT("KeyFrameTooltip", "Transform: {0} \nLocation: {1}\nRotation: {2}\nScale: {3}"),
				FText::AsNumber(KeyFrameIdx),
				FText::FromString(RelativeTransform.Location.ToString()),
				FText::FromString(RelativeTransform.Rotation.ToString()),
				FText::FromString(RelativeTransform.Scale.ToString())));
		}
		else if (MeshSwapAnimation && IsTimelineStartHandle())
		{
			const FKeyframeRelativeTransform& RelativeTransform = MeshSwapAnimation->InitialTransform;
			SetToolTipText(FText::Format(LOCTEXT("KeyFrameTooltip", "Initial Transform: \nLocation: {0}\nRotation: {1}\nScale: {2}"),
				FText::FromString(RelativeTransform.Location.ToString()),
				FText::FromString(RelativeTransform.Rotation.ToString()),
				FText::FromString(RelativeTransform.Scale.ToString())));
		}
		else
		{
			SetToolTipText(LOCTEXT("KeyFrameTooltip_Invalid", "Invalid key frame index"));
		}
	}

	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override
	{
		if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
		{
			DistanceDragged = 0;
			StartingFrameRun = INDEX_NONE;
			return FReply::Handled().CaptureMouse(SharedThis(this)).UseHighPrecisionMouseMovement(SharedThis(this));
		}
		else
		{

			return FReply::Unhandled();
		}
	}

	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override
	{
		if ((MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton) && this->HasMouseCapture())
		{
			if (bDragging && (StartingFrameRun != INDEX_NONE))
			{
				UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
				if (MeshSwapAnimation && MeshSwapAnimation->IsValidKeyFrameIndex(KeyFrameIdx))
				{
					const FMeshKeyFrameData& KeyFrame = MeshSwapAnimation->GetKeyFrameChecked(KeyFrameIdx);

					if (KeyFrame.FrameRun != StartingFrameRun)
					{
						MeshSwapAnimation->MarkPackageDirty();
						MeshSwapAnimation->PostEditChange();
					}
				}
			}

			bDragging = false;

			FIntPoint NewMousePos(
				(MyGeometry.AbsolutePosition.X + MyGeometry.GetLocalSize().X / 2) * MyGeometry.Scale,
				(MyGeometry.AbsolutePosition.Y + MyGeometry.GetLocalSize().Y / 2) * MyGeometry.Scale
				);

			return FReply::Handled().ReleaseMouseCapture().SetMousePos(NewMousePos);

		}
		else
		{
			return FReply::Unhandled();
		}
	}

	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override
	{
		if (this->HasMouseCapture())
		{
			UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
			if (MeshSwapAnimation && MeshSwapAnimation->IsValidKeyFrameIndex(KeyFrameIdx))
			{
				DistanceDragged += MouseEvent.GetCursorDelta().X;

				if (!bDragging)
				{
					if (FMath::Abs(DistanceDragged) > FSlateApplication::Get().GetDragTriggerDistance())
					{
						const FMeshKeyFrameData& KeyFrame = MeshSwapAnimation->GetKeyFrameChecked(KeyFrameIdx);
						StartingFrameRun = KeyFrame.FrameRun;
						bDragging = true;
					}
				}
				else
				{
					float LocalSlateUnitsPerFrame = SlateUnitsPerFrame.Get();
					if (LocalSlateUnitsPerFrame != 0)
					{
						FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimation);
						FMeshKeyFrameData& KeyFrame = EditLock.KeyFrames[KeyFrameIdx];
						KeyFrame.FrameRun = StartingFrameRun + (DistanceDragged / LocalSlateUnitsPerFrame);
						KeyFrame.FrameRun = FMath::Max<int32>(1, KeyFrame.FrameRun);
					}
				}
			}

			return FReply::Handled();
		}

		return FReply::Unhandled();
	}

	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const override
	{
		return FCursorReply::Cursor(IsTimelineStartHandle() ? EMouseCursor::Default : (bDragging ? EMouseCursor::None : EMouseCursor::ResizeLeftRight));
	}

	
	bool IsTimelineStartHandle() const
	{
		return (SlateUnitsPerFrame.Get() == 0.0f) && (KeyFrameIdx == INDEX_NONE) && (MeshSwapAnimationBeingEdited.Get() != nullptr);
	}

private:
	float DistanceDragged;
	int32 StartingFrameRun;
	bool bDragging;

	TAttribute<float> SlateUnitsPerFrame;
	TAttribute<class UMeshSwapAnimation*> MeshSwapAnimationBeingEdited;
	int32 KeyFrameIdx;
};


#undef LOCTEXT_NAMESPACE
