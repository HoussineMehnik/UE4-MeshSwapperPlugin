//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapAnimationEditor/STimelineTrack.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SOverlay.h"
#include "Layout/WidgetPath.h"
#include "Framework/Application/MenuStack.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Commands/UICommandList.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBox.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "AssetData.h"
#include "Framework/Commands/GenericCommands.h"
#include "DragAndDrop/AssetDragDropOp.h"
#include "Editor.h"
#include "PropertyCustomizationHelpers.h"
#include "Engine/StaticMesh.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SEditableText.h"
#include "EditorFontGlyphs.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"

#include "MeshSwapAnimationEditorCommands.h"
#include "MeshSwapperStyle.h"
#include "MeshSwapAnimation.h"
#include "SMeshSwapAnimationTrackHandle.h"

#include "Subsystems/AssetEditorSubsystem.h"

#define LOCTEXT_NAMESPACE "MeshSwapAnimationbookEditor"

//////////////////////////////////////////////////////////////////////////
// SMeshSwapAnimationKeyframeWidget

TSharedRef<SWidget> SMeshSwapAnimationKeyframeWidget::GenerateContextMenu()
{
	const FMeshSwapAnimationEditorCommands& Commands = FMeshSwapAnimationEditorCommands::Get();

	OnSelectionChanged.ExecuteIfBound(FrameIndex);

	FMenuBuilder MenuBuilder(true, CommandList);
	{
		FNumberFormattingOptions NoCommas;
		NoCommas.UseGrouping = false;
		
		const FText KeyframeSectionTitle = FText::Format(LOCTEXT("KeyframeActionsSectionHeader", "Keyframe #{0} Actions"), FText::AsNumber(FrameIndex, &NoCommas));
		MenuBuilder.BeginSection("KeyframeActions", KeyframeSectionTitle);

		// 		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Cut);
		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Duplicate);
		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Delete);
		

		MenuBuilder.AddMenuSeparator();

		MenuBuilder.AddMenuEntry(Commands.AddNewFrameBefore);
		MenuBuilder.AddMenuEntry(Commands.AddNewFrameAfter);

		MenuBuilder.EndSection();
	}


	

	CommandList->MapAction(Commands.ShowInContentBrowser, FExecuteAction::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::ShowInContentBrowser));
	CommandList->MapAction(Commands.EditStaticMesh, FExecuteAction::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::EditKeyFrame));

	CommandList->MapAction(
		Commands.ResetTransform,
		FExecuteAction::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::OnResetTransform),
		FCanExecuteAction::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::CanResetTransform));

	CommandList->MapAction(
		Commands.SmoothTransformInterpolation, 
		FExecuteAction::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::OnToggleSmoothTransform),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::CanSmoothTransform));

	CommandList->MapAction(
		Commands.SetCollisionEnabled,
		FExecuteAction::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::OnToggleCollision),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::IsCollisionEnabled));



	{
		TAttribute<FText> CurrentAssetTitle = TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::GetKeyframeAssetName));
		MenuBuilder.BeginSection("KeyframeAssetActions", CurrentAssetTitle);

		MenuBuilder.AddSubMenu(
			Commands.PickNewStaticMesh->GetLabel(),
			Commands.PickNewStaticMesh->GetDescription(),
			FNewMenuDelegate::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::OpenMeshKeyframePickerMenu));

		MenuBuilder.AddMenuEntry(Commands.ShowInContentBrowser);
		MenuBuilder.AddMenuEntry(Commands.EditStaticMesh);

		MenuBuilder.EndSection();
		
	}


	if (GetKeyFrameData() != nullptr)
	{
		MenuBuilder.BeginSection("Notify", FText::FromString("Properties"));

		MenuBuilder.AddWidget(
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				[
					SNew(SEditableTextBox)
					.MinDesiredWidth(64)
					.Text(this, &SMeshSwapAnimationKeyframeWidget::GetKeyframeNotifyTag)
					.OnTextCommitted(this, &SMeshSwapAnimationKeyframeWidget::SetKeyframeNotifyTag)
				]
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Right)
				[
					SNew(SButton)
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Center)
					.ButtonStyle(FEditorStyle::Get(), "FlatButton.Danger")
					.ToolTipText(LOCTEXT("ClearKeyframeTag", "Clear Keyframe Tag"))
					.OnClicked(this, &SMeshSwapAnimationKeyframeWidget::ClearKeyFrameTag)
					[
						SNew(SHorizontalBox)
						.Clipping(EWidgetClipping::ClipToBounds)
						+ SHorizontalBox::Slot()
						.Padding(2.f)
						.AutoWidth()
						[
							SNew(SImage)
							.Image(FAppStyle::Get().GetBrush("Sequencer.Tracks.Event"))
						]
					]
				]
			]


		, FText::FromString("Notify Tag ")
			);

		MenuBuilder.AddMenuSeparator();
		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Copy, NAME_None, FText::FromString("Copy Transform"));
		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Paste, NAME_None, FText::FromString("Paste Transform"));
		MenuBuilder.AddMenuEntry(Commands.ResetTransform);
		MenuBuilder.AddMenuEntry(Commands.SmoothTransformInterpolation);
		MenuBuilder.AddMenuSeparator();
		MenuBuilder.AddMenuEntry(Commands.SetCollisionEnabled);

		MenuBuilder.EndSection();
	}


	return MenuBuilder.MakeWidget();
}

void SMeshSwapAnimationKeyframeWidget::Construct(const FArguments& InArgs, int32 InFrameIndex, TSharedPtr<FUICommandList> InCommandList)
{
	FrameIndex = InFrameIndex;
	CommandList = MakeShareable(new FUICommandList);
	CommandList->Append(InCommandList.ToSharedRef());
	SlateUnitsPerFrame = InArgs._SlateUnitsPerFrame;
	MeshSwapAnimationBeingEdited = InArgs._MeshSwapAnimationBeingEdited;
	OnSelectionChanged = InArgs._OnSelectionChanged;

	// Color each region based on whether a static mesh has been set or not for it
	const auto BorderColorDelegate = [](TAttribute<UMeshSwapAnimation*> ThisMeshSwapAnimationPtr, int32 TestIndex) -> FSlateColor
	{
		UMeshSwapAnimation* MeshSwapAnimationPtr = ThisMeshSwapAnimationPtr.Get();
		const bool bFrameValid = (MeshSwapAnimationPtr != nullptr) && (MeshSwapAnimationPtr->GetStaticMeshAtFrame(TestIndex) != nullptr);
		return bFrameValid ? FLinearColor::White : FLinearColor::Black;
	};



	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
		[
			SNew(SBox)
			.Padding(FMeshSwapAnimationUIConstants::FramePadding)
			.WidthOverride(this, &SMeshSwapAnimationKeyframeWidget::GetFrameWidth)
			[
				SNew(SBorder)
				.BorderImage(FMeshSwapperStyle::Get()->GetBrush("MeshSwapAnimationEditor.RegionBody"))
				.BorderBackgroundColor_Static(BorderColorDelegate, MeshSwapAnimationBeingEdited, FrameIndex)
				.OnMouseButtonUp(this, &SMeshSwapAnimationKeyframeWidget::KeyframeOnMouseButtonUp)
				.ToolTipText(this, &SMeshSwapAnimationKeyframeWidget::GetKeyframeTooltip)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(SVerticalBox)
					+SVerticalBox::Slot()
					.HAlign(HAlign_Center)
					[
						SNew(STextBlock)
						.ColorAndOpacity(FLinearColor::Black)
						.Text(this, &SMeshSwapAnimationKeyframeWidget::GetKeyframeText)
					]
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Bottom)
					.Padding(4,2)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.Padding(2)
						[
							SNew(SImage)
							.Image(FAppStyle::Get().GetBrush("Sequencer.Tracks.Event"))
							.Visibility(this, &SMeshSwapAnimationKeyframeWidget::GetNotifyWidgetVisibility)
							.ToolTipText(this, &SMeshSwapAnimationKeyframeWidget::GetKeyframeNotifyTagTooltip)
							.ColorAndOpacity(FLinearColor::Red)
						]
						+ SHorizontalBox::Slot()
						.Padding(2)
						[
							SNew(SImage)
							.Image(FAppStyle::Get().GetBrush("Icons.VisualEffects"))
							.Visibility(this, &SMeshSwapAnimationKeyframeWidget::GetParticesWidgetVisibility)
							.ToolTipText(this, &SMeshSwapAnimationKeyframeWidget::GetKeyframeParticesTooltip)
							.ColorAndOpacity(FLinearColor::Blue)
						]
						+ SHorizontalBox::Slot()
						.Padding(2)
						[
							SNew(SImage)
							.Image(FEditorStyle::GetBrush("Sequencer.Tracks.Audio"))
							.Visibility(this, &SMeshSwapAnimationKeyframeWidget::GetSoundsWidgetVisibility)
							.ToolTipText(this, &SMeshSwapAnimationKeyframeWidget::GetKeyframeSoundsTooltip)
							.ColorAndOpacity(FColor::Orange)
						]
					]
				]
			]
		]
		+SOverlay::Slot()
		.HAlign(HAlign_Right)
		[
			SNew(SBox)
			.WidthOverride(FMeshSwapAnimationUIConstants::HandleWidth)
			[
				SNew(SMeshSwapAnimationTrackHandle)
				.SlateUnitsPerFrame(SlateUnitsPerFrame)
				.MeshSwapAnimationBeingEdited(MeshSwapAnimationBeingEdited)
				.KeyFrameIdx(FrameIndex)
			]
		]
	];

	
}


FReply SMeshSwapAnimationKeyframeWidget::OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
		{
			if (IsValid(KeyFrame->StaticMesh))
			{
				GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(KeyFrame->StaticMesh);
			}
		}
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

FReply SMeshSwapAnimationKeyframeWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		return FReply::Handled().DetectDrag(SharedThis(this), EKeys::LeftMouseButton);
	}

	return FReply::Unhandled();
}

FReply SMeshSwapAnimationKeyframeWidget::OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
		if ((MeshSwapAnimation != nullptr) && MeshSwapAnimation->IsValidKeyFrameIndex(FrameIndex))
		{
			TSharedRef<FMeshSwapAnimationKeyFrameDragDropOp> Operation = FMeshSwapAnimationKeyFrameDragDropOp::New(
				GetFrameWidth().Get(), MeshSwapAnimation, FrameIndex);

			return FReply::Handled().BeginDragDrop(Operation);
		}
	}

	return FReply::Unhandled();
}

FReply SMeshSwapAnimationKeyframeWidget::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	bool bWasDropHandled = false;

	UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
	if ((MeshSwapAnimation != nullptr) && MeshSwapAnimation->IsValidKeyFrameIndex(FrameIndex))
	{

		TSharedPtr<FDragDropOperation> Operation = DragDropEvent.GetOperation();
		if (!Operation.IsValid())
		{
		}
		else if (Operation->IsOfType<FAssetDragDropOp>())
		{
			const auto& AssetDragDropOp = StaticCastSharedPtr<FAssetDragDropOp>(Operation);
			//@TODO: Handle asset inserts

			// 			OnAssetsDropped(*AssetDragDropOp);
			// 			bWasDropHandled = true;
		}
		else if (Operation->IsOfType<FMeshSwapAnimationKeyFrameDragDropOp>())
		{
			const auto& FrameDragDropOp = StaticCastSharedPtr<FMeshSwapAnimationKeyFrameDragDropOp>(Operation);
			FrameDragDropOp->InsertInMeshSwapAnimation(MeshSwapAnimation, FrameIndex);
			bWasDropHandled = true;
		}
	}

	return bWasDropHandled ? FReply::Handled() : FReply::Unhandled();
}

FReply SMeshSwapAnimationKeyframeWidget::KeyframeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		TSharedRef<SWidget> MenuContents = GenerateContextMenu();
		FWidgetPath WidgetPath = MouseEvent.GetEventPath() != nullptr ? *MouseEvent.GetEventPath() : FWidgetPath();
		FSlateApplication::Get().PushMenu(AsShared(), WidgetPath, MenuContents, MouseEvent.GetScreenSpacePosition(), FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));

		return FReply::Handled();
	}

	return FReply::Unhandled();
}

// Can return null
const FMeshKeyFrameData* SMeshSwapAnimationKeyframeWidget::GetKeyFrameData() const
{
	UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
	if ((MeshSwapAnimation != nullptr) && MeshSwapAnimation->IsValidKeyFrameIndex(FrameIndex))
	{
		return &(MeshSwapAnimation->GetKeyFrameChecked(FrameIndex));
	}

	return nullptr;
}

FText SMeshSwapAnimationKeyframeWidget::GetKeyframeAssetName() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		const FText StaticMeshLine = (KeyFrame->StaticMesh != nullptr) ? 
			FText::FromString(KeyFrame->StaticMesh->GetName()) : LOCTEXT("NoStaticMesh", "(none)");
		return FText::Format(LOCTEXT("KeyFrameAssetName", "Current Asset: {0}"), StaticMeshLine);
	}
	else
	{
		return LOCTEXT("KeyFrameAssetName_None", "Current Asset: (none)");
	}
}

FText SMeshSwapAnimationKeyframeWidget::GetKeyframeText() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		if (KeyFrame->StaticMesh != nullptr)
		{
			return FText::AsCultureInvariant(KeyFrame->StaticMesh->GetName());
		}
	}

	return FText::GetEmpty();
}

FText SMeshSwapAnimationKeyframeWidget::GetKeyframeTooltip() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		const FText StaticMeshLine = (KeyFrame->StaticMesh != nullptr) ? FText::FromString(KeyFrame->StaticMesh->GetName()) : LOCTEXT("NoStaticMesh", "(none)");

		const FText FramesText = (KeyFrame->FrameRun == 1) ? LOCTEXT("SingularFrames", "frame") : LOCTEXT("PluralFrames", "frames");
		
		return FText::Format(LOCTEXT("KeyFrameTooltip", "StaticMesh: {0}\nIndex: {1}\nDuration: {2} {3}"),
			StaticMeshLine,
			FText::AsNumber(FrameIndex),
			FText::AsNumber(KeyFrame->FrameRun),
			FramesText);
	}
	else
	{
		return LOCTEXT("KeyFrameTooltip_Invalid", "Invalid key frame index");
	}
}


FText SMeshSwapAnimationKeyframeWidget::GetKeyframeNotifyTag() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		return FText::FromString(KeyFrame->NotifyTag);
	}
	else
	{
		return LOCTEXT("KeyFrameTooltip_Invalid", "Invalid key frame index");
	}
}

void SMeshSwapAnimationKeyframeWidget::SetKeyframeNotifyTag(const FText& NewText, ETextCommit::Type TextType)
{
	FString NewTextToString = NewText.ToString();
	if (UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get())
	{
		const FScopedTransaction Transaction(LOCTEXT("EditKeyframeNotifyTag", "Edit Notify Tag"));
		MeshSwapAnimation->Modify();
		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimation);

		if (EditLock.KeyFrames.IsValidIndex(FrameIndex))
		{
			EditLock.KeyFrames[FrameIndex].NotifyTag = NewTextToString;
		}
	}
}


FReply SMeshSwapAnimationKeyframeWidget::ClearKeyFrameTag()
{
	if (UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get())
	{
		const FScopedTransaction Transaction(LOCTEXT("ClearKeyframeNotifyTag", "Clear Notify Tag"));
		MeshSwapAnimation->Modify();
		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimation);

		if (EditLock.KeyFrames.IsValidIndex(FrameIndex))
		{
			EditLock.KeyFrames[FrameIndex].NotifyTag.Empty();
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}


EVisibility SMeshSwapAnimationKeyframeWidget::GetNotifyWidgetVisibility() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		return KeyFrame->NotifyTag.IsEmpty() ? EVisibility::Hidden : EVisibility::Visible;
	}
	return EVisibility::Hidden;
}

FText SMeshSwapAnimationKeyframeWidget::GetKeyframeNotifyTagTooltip() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		return FText::FromString(KeyFrame->NotifyTag);
	}
	return FText();
}


EVisibility SMeshSwapAnimationKeyframeWidget::GetParticesWidgetVisibility() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		return KeyFrame->ParticleEffects.Num() <= 0 ? EVisibility::Hidden : EVisibility::Visible;
	}
	return EVisibility::Hidden;
}


FText SMeshSwapAnimationKeyframeWidget::GetKeyframeParticesTooltip() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		return FText::FromString(FString::FromInt(KeyFrame->ParticleEffects.Num()) + TEXT(" Particle(s)"));
	}
	return FText();
}


EVisibility SMeshSwapAnimationKeyframeWidget::GetSoundsWidgetVisibility() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		return KeyFrame->SoundEffects.Num() <= 0 ? EVisibility::Hidden : EVisibility::Visible;
	}
	return EVisibility::Hidden;
}


FText SMeshSwapAnimationKeyframeWidget::GetKeyframeSoundsTooltip() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		return FText::FromString(FString::FromInt(KeyFrame->SoundEffects.Num()) + TEXT(" Sound(s)"));
	}
	return FText();
}


void SMeshSwapAnimationKeyframeWidget::OnResetTransform()
{
	if (UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get())
	{
		const FScopedTransaction Transaction(LOCTEXT("OnResetTransform", " Reset Keyframe Transform"));
		MeshSwapAnimation->Modify();
		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimation);

		if (EditLock.KeyFrames.IsValidIndex(FrameIndex))
		{
			EditLock.KeyFrames[FrameIndex].RelativeTransform.Reset();
		}
	}
}


bool SMeshSwapAnimationKeyframeWidget::CanResetTransform() const
{
	return true;
}


void SMeshSwapAnimationKeyframeWidget::OnToggleSmoothTransform()
{
	if (UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get())
	{
		const FScopedTransaction Transaction(LOCTEXT("OnToggleSmoothTransform", " Toggle Smooth Transform"));
		MeshSwapAnimation->Modify();
		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimation);

		if (EditLock.KeyFrames.IsValidIndex(FrameIndex))
		{
			EditLock.KeyFrames[FrameIndex].bSmoothTransformInterpolation = !EditLock.KeyFrames[FrameIndex].bSmoothTransformInterpolation;
		}
	}
}

bool SMeshSwapAnimationKeyframeWidget::CanSmoothTransform() const
{
	UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
	if ((MeshSwapAnimation != nullptr) && MeshSwapAnimation->IsValidKeyFrameIndex(FrameIndex))
	{
		return (MeshSwapAnimation->GetKeyFrameChecked(FrameIndex)).bSmoothTransformInterpolation;
	}
	return false;
}

bool SMeshSwapAnimationKeyframeWidget::IsCollisionEnabled() const
{
	UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
	if ((MeshSwapAnimation != nullptr) && MeshSwapAnimation->IsValidKeyFrameIndex(FrameIndex))
	{
		return (MeshSwapAnimation->GetKeyFrameChecked(FrameIndex)).bEnableCollision;
	}
	return false;
}

void SMeshSwapAnimationKeyframeWidget::OnToggleCollision()
{
	if (UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get())
	{
		const FScopedTransaction Transaction(LOCTEXT("OnToggleCollision", " Toggle Collision"));
		MeshSwapAnimation->Modify();
		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimation);

		if (EditLock.KeyFrames.IsValidIndex(FrameIndex))
		{
			EditLock.KeyFrames[FrameIndex].bEnableCollision = !EditLock.KeyFrames[FrameIndex].bEnableCollision;
		}
	}
}

FOptionalSize SMeshSwapAnimationKeyframeWidget::GetFrameWidth() const
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		return FMath::Max<float>(0, KeyFrame->FrameRun * SlateUnitsPerFrame.Get());
	}
	else
	{
		return 1;
	}
}

void SMeshSwapAnimationKeyframeWidget::OpenMeshKeyframePickerMenu(FMenuBuilder& MenuBuilder)
{
	const bool bAllowClear = true;

	TArray<const UClass*> AllowedClasses;
	AllowedClasses.Add(UStaticMesh::StaticClass());

	FAssetData CurrentAssetData;
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		CurrentAssetData = FAssetData(KeyFrame->StaticMesh);
	}

	TSharedRef<SWidget> AssetPickerWidget = PropertyCustomizationHelpers::MakeAssetPickerWithMenu(CurrentAssetData,
		bAllowClear,
		AllowedClasses,
		PropertyCustomizationHelpers::GetNewAssetFactoriesForClasses(AllowedClasses),
		FOnShouldFilterAsset(),
		FOnAssetSelected::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::OnAssetSelected),
		FSimpleDelegate::CreateSP(this, &SMeshSwapAnimationKeyframeWidget::CloseMenu));

	MenuBuilder.AddWidget(AssetPickerWidget, FText::GetEmpty(), /*bNoIndent=*/ true);
}

void SMeshSwapAnimationKeyframeWidget::CloseMenu()
{
	FSlateApplication::Get().DismissAllMenus();
}

void SMeshSwapAnimationKeyframeWidget::OnAssetSelected(const FAssetData& AssetData)
{
	if (UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get())
	{
		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimation);

		if (EditLock.KeyFrames.IsValidIndex(FrameIndex))
		{
			UStaticMesh* NewStaticMesh = Cast<UStaticMesh>(AssetData.GetAsset());

			EditLock.KeyFrames[FrameIndex].StaticMesh = NewStaticMesh;
		}
	}
}

void SMeshSwapAnimationKeyframeWidget::ShowInContentBrowser()
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		if (KeyFrame->StaticMesh != nullptr)
		{
			TArray<UObject*> ObjectsToSync;
			ObjectsToSync.Add(KeyFrame->StaticMesh);
			GEditor->SyncBrowserToObjects(ObjectsToSync);
		}
	}
}

void SMeshSwapAnimationKeyframeWidget::EditKeyFrame()
{
	if (const FMeshKeyFrameData* KeyFrame = GetKeyFrameData())
	{
		if (KeyFrame->StaticMesh != nullptr)
		{
			GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(KeyFrame->StaticMesh);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// FMeshSwapAnimationKeyFrameDragDropOp

TSharedPtr<SWidget> FMeshSwapAnimationKeyFrameDragDropOp::GetDefaultDecorator() const
{
	const FLinearColor BorderColor = (KeyFrameData.StaticMesh != nullptr) ? FLinearColor::White : FLinearColor::Black;

	return SNew(SBox)
		.WidthOverride(WidgetWidth - FMeshSwapAnimationUIConstants::FramePadding.GetTotalSpaceAlong<Orient_Horizontal>())
		.HeightOverride(FMeshSwapAnimationUIConstants::FrameHeight- FMeshSwapAnimationUIConstants::FramePadding.GetTotalSpaceAlong<Orient_Vertical>())
		[
			SNew(SBorder)
			.BorderImage(FMeshSwapperStyle::Get()->GetBrush("MeshSwapAnimationEditor.RegionBody"))
			.BorderBackgroundColor(BorderColor)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.ColorAndOpacity(FLinearColor::Black)
				.Text(BodyText)
			]
		];
}

void FMeshSwapAnimationKeyFrameDragDropOp::OnDragged(const class FDragDropEvent& DragDropEvent)
{
	if (CursorDecoratorWindow.IsValid())
	{
		CursorDecoratorWindow->MoveWindowTo(DragDropEvent.GetScreenSpacePosition());
	}
}

void FMeshSwapAnimationKeyFrameDragDropOp::Construct()
{
	MouseCursor = EMouseCursor::GrabHandClosed;

	if (UMeshSwapAnimation* MeshSwapAnimation = SourceMeshSwapAnimation.Get())
	{
		if (UStaticMesh* StaticMesh = MeshSwapAnimation->GetStaticMeshAtFrame(SourceFrameIndex))
		{
			BodyText = FText::AsCultureInvariant(StaticMesh->GetName());
		}
	}

	FDragDropOperation::Construct();
}

void FMeshSwapAnimationKeyFrameDragDropOp::OnDrop(bool bDropWasHandled, const FPointerEvent& MouseEvent)
{
	if (!bDropWasHandled)
	{
		// Add us back to our source, the drop fizzled
		InsertInMeshSwapAnimation(SourceMeshSwapAnimation.Get(), SourceFrameIndex);
		Transaction.Cancel();
	}
}

void FMeshSwapAnimationKeyFrameDragDropOp::AppendToMeshSwapAnimation(UMeshSwapAnimation* DestinationMeshSwapAnimation)
{
	DestinationMeshSwapAnimation->Modify();
	FScopedMeshSwapAnimationMutator EditLock(DestinationMeshSwapAnimation);
	EditLock.KeyFrames.Add(KeyFrameData);
}

void FMeshSwapAnimationKeyFrameDragDropOp::InsertInMeshSwapAnimation(UMeshSwapAnimation* DestinationMeshSwapAnimation, int32 Index)
{
	DestinationMeshSwapAnimation->Modify();
	FScopedMeshSwapAnimationMutator EditLock(DestinationMeshSwapAnimation);
	EditLock.KeyFrames.Insert(KeyFrameData, Index);
}

TSharedRef<FMeshSwapAnimationKeyFrameDragDropOp> FMeshSwapAnimationKeyFrameDragDropOp::New(int32 InWidth, UMeshSwapAnimation* InMeshSwapAnimation, int32 InFrameIndex)
{
	// Create the drag-drop op containing the key
	TSharedRef<FMeshSwapAnimationKeyFrameDragDropOp> Operation = MakeShareable(new FMeshSwapAnimationKeyFrameDragDropOp);
	Operation->KeyFrameData = InMeshSwapAnimation->GetKeyFrameChecked(InFrameIndex);
	Operation->SourceFrameIndex = InFrameIndex;
	Operation->SourceMeshSwapAnimation = InMeshSwapAnimation;
	Operation->WidgetWidth = InWidth;
	Operation->Construct();

	// Remove the key from the MeshSwapAnimation
	{
		InMeshSwapAnimation->Modify();
		FScopedMeshSwapAnimationMutator EditLock(InMeshSwapAnimation);
		EditLock.KeyFrames.RemoveAt(InFrameIndex);
	}

	return Operation;
}

FMeshSwapAnimationKeyFrameDragDropOp::FMeshSwapAnimationKeyFrameDragDropOp()
	: Transaction(LOCTEXT("MovedFramesInTimeline", "Reorder key frames"))
{

}

//////////////////////////////////////////////////////////////////////////
// SMeshSwapAnimationTimelineTrack

void SMeshSwapAnimationTimelineTrack::Construct(const FArguments& InArgs, TSharedPtr<FUICommandList> InCommandList)
{
	CommandList = InCommandList;
	SlateUnitsPerFrame = InArgs._SlateUnitsPerFrame;
	MeshSwapAnimationBeingEdited = InArgs._MeshSwapAnimationBeingEdited;
	OnSelectionChanged = InArgs._OnSelectionChanged;

	ChildSlot
	[
		SAssignNew(MainBoxPtr, SHorizontalBox)
	];

	Rebuild();
}

void SMeshSwapAnimationTimelineTrack::Rebuild()
{
	MainBoxPtr->ClearChildren();

	MainBoxPtr->AddSlot()
	.AutoWidth()
	[
		SNew(SBox)
		//.Visibility(EVisibility::HitTestInvisible)
		.WidthOverride(FMeshSwapAnimationUIConstants::HandleWidth)
			[
				SNew(SMeshSwapAnimationTrackHandle)
				.SlateUnitsPerFrame(0.0f)
				.MeshSwapAnimationBeingEdited(MeshSwapAnimationBeingEdited)
				.KeyFrameIdx(INDEX_NONE)
			]
	];

	// Create the sections for each keyframe
	if (UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get())
	{
		for (int32 KeyFrameIdx = 0; KeyFrameIdx < MeshSwapAnimation->GetNumKeyFrames(); ++KeyFrameIdx)
		{
			MainBoxPtr->AddSlot()
				.AutoWidth()
			[
				SNew(SMeshSwapAnimationKeyframeWidget, KeyFrameIdx, CommandList)
				.SlateUnitsPerFrame(this->SlateUnitsPerFrame)
				.MeshSwapAnimationBeingEdited(this->MeshSwapAnimationBeingEdited)
				.OnSelectionChanged(this->OnSelectionChanged)
			];
		}
	}
}

#undef LOCTEXT_NAMESPACE
