//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapAnimationEditor/MeshSwapAnimationEditor.h"
#include "EditorViewportClient.h"
#include "UObject/Package.h"
#include "Modules/ModuleManager.h"
#include "EditorStyleSet.h"
#include "SSingleObjectDetailsPanel.h"
#include "SEditorViewport.h"
#include "ScopedTransaction.h"
#include "SCommonEditorViewportToolbarBase.h"
#include "SScrubControlPanel.h"
#include "Widgets/Docking/SDockTab.h"
#include "Framework/Commands/GenericCommands.h"
#include "MeshSwapAnimationEditorCommands.h"
#include "MeshSwapperEditorModule.h"
#include "MeshSwapAnimation.h"
#include "MeshSwapperComponent.h"
#include "MeshSwapAnimationEditorViewportClient.h"
#include "SMeshSwapAnimationTimeline.h"
#include "SMeshSwapAnimationEditorViewportToolbar.h"
#include "Subsystems/AssetEditorSubsystem.h"
#include "Styling/AppStyle.h"


#define LOCTEXT_NAMESPACE "MeshSwapAnimationEditor"

//////////////////////////////////////////////////////////////////////////

const FName MeshSwapAnimationEditorAppName = FName(TEXT("MeshSwapAnimationEditorApp"));

//////////////////////////////////////////////////////////////////////////

struct FMeshSwapAnimationEditorTabs
{
	// Tab identifiers
	static const FName DetailsID;
	static const FName ViewportID;
};

//////////////////////////////////////////////////////////////////////////

const FName FMeshSwapAnimationEditorTabs::DetailsID(TEXT("Details"));
const FName FMeshSwapAnimationEditorTabs::ViewportID(TEXT("Viewport"));

//////////////////////////////////////////////////////////////////////////
// SMeshSwapAnimationEditorViewport

class SMeshSwapAnimationEditorViewport : public SEditorViewport, public ICommonEditorViewportToolbarInfoProvider
{
public:
	SLATE_BEGIN_ARGS(SMeshSwapAnimationEditorViewport)
		: _MeshSwapAnimationBeingEdited((UMeshSwapAnimation*)nullptr)
	{}

		SLATE_ATTRIBUTE( UMeshSwapAnimation*, MeshSwapAnimationBeingEdited )

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	// SEditorViewport interface
	virtual void BindCommands() override;
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;
	virtual TSharedPtr<SWidget> MakeViewportToolbar() override;
	virtual EVisibility GetTransformToolbarVisibility() const override;
	// End of SEditorViewport interface

	// ICommonEditorViewportToolbarInfoProvider interface
	virtual TSharedRef<class SEditorViewport> GetViewportWidget() override;
	virtual TSharedPtr<FExtender> GetExtenders() const override;
	virtual void OnFloatingButtonClicked() override;
	// End of ICommonEditorViewportToolbarInfoProvider interface

	UMeshSwapperComponent* GetPreviewComponent() const
	{
		return EditorViewportClient->GetPreviewComponent();
	}

private:
	TAttribute<UMeshSwapAnimation*> MeshSwapAnimationBeingEdited;

public:
	// Viewport client
	TSharedPtr<FMeshSwapAnimationEditorViewportClient> EditorViewportClient;
};

void SMeshSwapAnimationEditorViewport::Construct(const FArguments& InArgs)
{
	MeshSwapAnimationBeingEdited = InArgs._MeshSwapAnimationBeingEdited;

	SEditorViewport::Construct(SEditorViewport::FArguments());
}

void SMeshSwapAnimationEditorViewport::BindCommands()
{
	SEditorViewport::BindCommands();

	const FMeshSwapAnimationEditorCommands& Commands = FMeshSwapAnimationEditorCommands::Get();

	TSharedRef<FMeshSwapAnimationEditorViewportClient> EditorViewportClientRef = EditorViewportClient.ToSharedRef();

}

TSharedRef<FEditorViewportClient> SMeshSwapAnimationEditorViewport::MakeEditorViewportClient()
{
	EditorViewportClient = MakeShareable(new FMeshSwapAnimationEditorViewportClient(MeshSwapAnimationBeingEdited, SharedThis(this)));

	return EditorViewportClient.ToSharedRef();
}

TSharedPtr<SWidget> SMeshSwapAnimationEditorViewport::MakeViewportToolbar()
{
	return SNew(SMeshSwapAnimationEditorViewportToolbar, SharedThis(this));
}

EVisibility SMeshSwapAnimationEditorViewport::GetTransformToolbarVisibility() const
{
	return EVisibility::Visible;
}


TSharedRef<class SEditorViewport> SMeshSwapAnimationEditorViewport::GetViewportWidget()
{
	return SharedThis(this);
}

TSharedPtr<FExtender> SMeshSwapAnimationEditorViewport::GetExtenders() const
{
	TSharedPtr<FExtender> Result(MakeShareable(new FExtender));
	return Result;
}

void SMeshSwapAnimationEditorViewport::OnFloatingButtonClicked()
{
}

/////////////////////////////////////////////////////
// SMeshSwapAnimationPropertiesTabBody

class SMeshSwapAnimationPropertiesTabBody : public SSingleObjectDetailsPanel
{
public:
	SLATE_BEGIN_ARGS(SMeshSwapAnimationPropertiesTabBody) {}
	SLATE_END_ARGS()

private:
	// Pointer back to owning mesh keyframe editor instance (the keeper of state)
	TWeakPtr<class FMeshSwapAnimationEditor> MeshSwapAnimationEditorPtr;
public:
	void Construct(const FArguments& InArgs, TSharedPtr<FMeshSwapAnimationEditor> InMeshSwapAnimationEditor)
	{
		MeshSwapAnimationEditorPtr = InMeshSwapAnimationEditor;

		SSingleObjectDetailsPanel::Construct(SSingleObjectDetailsPanel::FArguments().HostCommandList(InMeshSwapAnimationEditor->GetToolkitCommands()).HostTabManager(InMeshSwapAnimationEditor->GetTabManager()), /*bAutomaticallyObserveViaGetObjectToObserve=*/ true, /*bAllowSearch=*/ true);
	}

	// SSingleObjectDetailsPanel interface
	virtual UObject* GetObjectToObserve() const override
	{
		return MeshSwapAnimationEditorPtr.Pin()->GetMeshSwapAnimationBeingEdited();
	}

	virtual TSharedRef<SWidget> PopulateSlot(TSharedRef<SWidget> PropertyEditorWidget) override
	{
		return SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.FillHeight(1)
			[
				PropertyEditorWidget
			];
	}
	// End of SSingleObjectDetailsPanel interface
};

//////////////////////////////////////////////////////////////////////////
// FMeshSwapAnimationEditor


FKeyframeRelativeTransform FMeshSwapAnimationEditor::SavedTransform = FKeyframeRelativeTransform();

FMeshSwapAnimationEditor::FMeshSwapAnimationEditor()
	: MeshSwapAnimationBeingEdited(nullptr)
	, CurrentSelectedKeyframe(INDEX_NONE)
{

}

TSharedRef<SDockTab> FMeshSwapAnimationEditor::SpawnTab_Viewport(const FSpawnTabArgs& Args)
{
	ViewInputMin = 0.0f;
	ViewInputMax = GetTotalSequenceLength();
	LastObservedSequenceLength = ViewInputMax;

	//@TODO : Implement OnBeginSliderMovement/OnEndSliderMovement so that refreshing works, animation stops, etc...

	TSharedRef<SWidget> ScrubControl = SNew(SScrubControlPanel)
		.IsEnabled(true)
		.Value(this, &FMeshSwapAnimationEditor::GetPlaybackPosition)
		.NumOfKeys(this, &FMeshSwapAnimationEditor::GetTotalFrameCountPlusOne)
		.SequenceLength(this, &FMeshSwapAnimationEditor::GetTotalSequenceLength)
		.OnValueChanged(this, &FMeshSwapAnimationEditor::SetPlaybackPosition)
//		.OnBeginSliderMovement(this, &SAnimationScrubPanel::OnBeginSliderMovement)
//		.OnEndSliderMovement(this, &SAnimationScrubPanel::OnEndSliderMovement)
		.OnClickedForwardPlay(this, &FMeshSwapAnimationEditor::OnClick_Forward)
		.OnClickedForwardStep(this, &FMeshSwapAnimationEditor::OnClick_Forward_Step)
		.OnClickedForwardEnd(this, &FMeshSwapAnimationEditor::OnClick_Forward_End)
		.OnClickedBackwardPlay(this, &FMeshSwapAnimationEditor::OnClick_Backward)
		.OnClickedBackwardStep(this, &FMeshSwapAnimationEditor::OnClick_Backward_Step)
		.OnClickedBackwardEnd(this, &FMeshSwapAnimationEditor::OnClick_Backward_End)
		.OnClickedToggleLoop(this, &FMeshSwapAnimationEditor::OnClick_ToggleLoop)
		.OnGetLooping(this, &FMeshSwapAnimationEditor::IsLooping)
		.OnGetPlaybackMode(this, &FMeshSwapAnimationEditor::GetPlaybackMode)
		.ViewInputMin(this, &FMeshSwapAnimationEditor::GetViewRangeMin)
		.ViewInputMax(this, &FMeshSwapAnimationEditor::GetViewRangeMax)
		.OnSetInputViewRange(this, &FMeshSwapAnimationEditor::SetViewRange)
		.bAllowZoom(true)
		.IsRealtimeStreamingMode(false);

	return SNew(SDockTab)
		.Label(LOCTEXT("ViewportTab_Title", "Viewport"))
		[
			SNew(SVerticalBox)
			
			+SVerticalBox::Slot()
			[
				ViewportPtr.ToSharedRef()
			]

			+SVerticalBox::Slot()
			.Padding(0, 8, 0, 0)
			.AutoHeight()
			[
				SNew(SMeshSwapAnimationTimeline, GetToolkitCommands())
				.MeshSwapAnimationBeingEdited(this, &FMeshSwapAnimationEditor::GetMeshSwapAnimationBeingEdited)
				.OnSelectionChanged(this, &FMeshSwapAnimationEditor::SetSelection)
				.PlayTime(this, &FMeshSwapAnimationEditor::GetPlaybackPosition)
			]

			+SVerticalBox::Slot()
			.Padding(0, 8, 0, 0)
			.AutoHeight()
			[
				ScrubControl
			]
		];
}

TSharedRef<SDockTab> FMeshSwapAnimationEditor::SpawnTab_Details(const FSpawnTabArgs& Args)
{
	TSharedPtr<FMeshSwapAnimationEditor> MeshSwapAnimationEditorPtr = SharedThis(this);

	// Spawn the tab
	return SNew(SDockTab)
		.Label(LOCTEXT("DetailsTab_Title", "Details"))
		[
			SNew(SMeshSwapAnimationPropertiesTabBody, MeshSwapAnimationEditorPtr)
		];
}

void FMeshSwapAnimationEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_MeshSwapAnimationEditor", "MeshSwap Animation Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(FMeshSwapAnimationEditorTabs::ViewportID, FOnSpawnTab::CreateSP(this, &FMeshSwapAnimationEditor::SpawnTab_Viewport))
		.SetDisplayName( LOCTEXT("ViewportTab", "Viewport") )
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Viewports"));

	InTabManager->RegisterTabSpawner(FMeshSwapAnimationEditorTabs::DetailsID, FOnSpawnTab::CreateSP(this, &FMeshSwapAnimationEditor::SpawnTab_Details))
		.SetDisplayName( LOCTEXT("DetailsTabLabel", "Details") )
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FMeshSwapAnimationEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(FMeshSwapAnimationEditorTabs::ViewportID);
	InTabManager->UnregisterTabSpawner(FMeshSwapAnimationEditorTabs::DetailsID);
}

void FMeshSwapAnimationEditor::InitMeshSwapAnimationEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UMeshSwapAnimation* InitMeshSwapAnimation)
{
	GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->CloseOtherEditors(InitMeshSwapAnimation, this);
	MeshSwapAnimationBeingEdited = InitMeshSwapAnimation;
	CurrentSelectedKeyframe = INDEX_NONE;

	FMeshSwapAnimationEditorCommands::Register();

	ViewportPtr = SNew(SMeshSwapAnimationEditorViewport)
		.MeshSwapAnimationBeingEdited(this, &FMeshSwapAnimationEditor::GetMeshSwapAnimationBeingEdited);
	
	// Default layout
	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_MeshSwapAnimationEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewSplitter()
				->SetOrientation(Orient_Horizontal)
				->SetSizeCoefficient(0.9f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.8f)
					->SetHideTabWell(true)
					->AddTab(FMeshSwapAnimationEditorTabs::ViewportID, ETabState::OpenedTab)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.2f)
					->AddTab(FMeshSwapAnimationEditorTabs::DetailsID, ETabState::OpenedTab)
				)
			)
		);

	// Initialize the asset editor and spawn nothing (dummy layout)
	InitAssetEditor(Mode, InitToolkitHost, MeshSwapAnimationEditorAppName, StandaloneDefaultLayout, /*bCreateDefaultStandaloneMenu=*/ true, /*bCreateDefaultToolbar=*/ true, InitMeshSwapAnimation);

	BindCommands();
	// Extend things
	ExtendMenu();
	ExtendToolbar();
	RegenerateMenusAndToolbars();
}

UMeshSwapperComponent* FMeshSwapAnimationEditor::GetPreviewComponent() const
{
	UMeshSwapperComponent* PreviewComponent = ViewportPtr->GetPreviewComponent();
	check(PreviewComponent);
	return PreviewComponent;
}

void FMeshSwapAnimationEditor::BindCommands()
{
	const FMeshSwapAnimationEditorCommands& Commands = FMeshSwapAnimationEditorCommands::Get();

	const TSharedRef<FUICommandList>& UICommandList = GetToolkitCommands();

	UICommandList->MapAction(FGenericCommands::Get().Delete,
		FExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::DeleteSelection),
		FCanExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::HasValidSelection));

	UICommandList->MapAction(FGenericCommands::Get().Duplicate,
		FExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::DuplicateSelection),
		FCanExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::HasValidSelection));

	UICommandList->MapAction(Commands.AddNewFrame,
		FExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::AddNewKeyFrameAtEnd),
		FCanExecuteAction());
	UICommandList->MapAction(Commands.AddNewFrameBefore,
		FExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::AddNewKeyFrameBefore),
		FCanExecuteAction());
	UICommandList->MapAction(Commands.AddNewFrameAfter,
		FExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::AddNewKeyFrameAfter),
		FCanExecuteAction());

	UICommandList->MapAction(Commands.AddKeyFrame,
		FExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::AddKeyFrameAtCurrentTime));

	UICommandList->MapAction(
		FGenericCommands::Get().Copy,
		FExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::CopySelectionTransform),
		FCanExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::HasValidSelection));

	UICommandList->MapAction(
		FGenericCommands::Get().Paste,
		FExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::PasteSavedTransformToSelection),
		FCanExecuteAction::CreateSP(this, &FMeshSwapAnimationEditor::HasValidSelection));


	TSharedRef<FMeshSwapAnimationEditorViewportClient> EditorViewportClientRef = ViewportPtr->EditorViewportClient.ToSharedRef();


	UICommandList->MapAction(Commands.ToggleParticles,
		FExecuteAction::CreateSP(EditorViewportClientRef, &FMeshSwapAnimationEditorViewportClient::ToggleShowParticles),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(EditorViewportClientRef, &FMeshSwapAnimationEditorViewportClient::IsShowParticlesChecked));

	UICommandList->MapAction(Commands.ToggleSounds,
		FExecuteAction::CreateSP(EditorViewportClientRef, &FMeshSwapAnimationEditorViewportClient::TogglePlaySounds),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(EditorViewportClientRef, &FMeshSwapAnimationEditorViewportClient::IsPlaySoundsChecked));

	UICommandList->MapAction(
		Commands.SetShowGrid,
		FExecuteAction::CreateSP(EditorViewportClientRef, &FEditorViewportClient::SetShowGrid),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(EditorViewportClientRef, &FEditorViewportClient::IsSetShowGridChecked));

	UICommandList->MapAction(
		Commands.SetShowBounds,
		FExecuteAction::CreateSP(EditorViewportClientRef, &FEditorViewportClient::ToggleShowBounds),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(EditorViewportClientRef, &FEditorViewportClient::IsSetShowBoundsChecked));

	UICommandList->MapAction(
		Commands.SetShowCollision,
		FExecuteAction::CreateSP(EditorViewportClientRef, &FEditorViewportClient::SetShowCollision),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(EditorViewportClientRef, &FEditorViewportClient::IsSetShowCollisionChecked));

	UICommandList->MapAction(
		Commands.SetShowPivot,
		FExecuteAction::CreateSP(EditorViewportClientRef, &FMeshSwapAnimationEditorViewportClient::ToggleShowPivot),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(EditorViewportClientRef, &FMeshSwapAnimationEditorViewportClient::IsShowPivotChecked));

	UICommandList->MapAction(
		Commands.SetShowSockets,
		FExecuteAction::CreateSP(EditorViewportClientRef, &FMeshSwapAnimationEditorViewportClient::ToggleShowSockets),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(EditorViewportClientRef, &FMeshSwapAnimationEditorViewportClient::IsShowSocketsChecked));
}

FName FMeshSwapAnimationEditor::GetToolkitFName() const
{
	return FName("MeshSwapAnimationEditor");
}

FText FMeshSwapAnimationEditor::GetBaseToolkitName() const
{
	return LOCTEXT("MeshSwapAnimationEditorAppLabel", "MeshSwap Animation Editor");
}

FText FMeshSwapAnimationEditor::GetToolkitName() const
{
	const bool bDirtyState = MeshSwapAnimationBeingEdited->GetOutermost()->IsDirty();

	FFormatNamedArguments Args;
	Args.Add(TEXT("MeshSwapAnimationName"), FText::FromString(MeshSwapAnimationBeingEdited->GetName()));
	Args.Add(TEXT("DirtyState"), bDirtyState ? FText::FromString( TEXT( "*" ) ) : FText::GetEmpty());
	return FText::Format(LOCTEXT("MeshSwapAnimationEditorToolkitName", "{MeshSwapAnimationName}{DirtyState}"), Args);
}

FText FMeshSwapAnimationEditor::GetToolkitToolTipText() const
{
	return FAssetEditorToolkit::GetToolTipTextForObject(MeshSwapAnimationBeingEdited);
}

FString FMeshSwapAnimationEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("MeshSwapAnimationEditor");
}

FLinearColor FMeshSwapAnimationEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}

void FMeshSwapAnimationEditor::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(MeshSwapAnimationBeingEdited);
}

FString FMeshSwapAnimationEditor::GetReferencerName() const
{
	return TEXT("FMeshSwapAnimationEditor");
}


void FMeshSwapAnimationEditor::ExtendMenu()
{
}

void FMeshSwapAnimationEditor::ExtendToolbar()
{
	struct Local
	{
		static void FillToolbar(FToolBarBuilder& ToolbarBuilder)
		{
			ToolbarBuilder.BeginSection("Command");
			{
				ToolbarBuilder.AddToolBarButton(FMeshSwapAnimationEditorCommands::Get().AddKeyFrame);
				ToolbarBuilder.AddSeparator();
				ToolbarBuilder.AddToolBarButton(FMeshSwapAnimationEditorCommands::Get().ToggleParticles);
				ToolbarBuilder.AddToolBarButton(FMeshSwapAnimationEditorCommands::Get().ToggleSounds);
			}
			ToolbarBuilder.EndSection();

			ToolbarBuilder.BeginSection("Visibility");
			{
				ToolbarBuilder.AddToolBarButton(FMeshSwapAnimationEditorCommands::Get().SetShowSockets);
				ToolbarBuilder.AddToolBarButton(FMeshSwapAnimationEditorCommands::Get().SetShowPivot);

				ToolbarBuilder.AddSeparator();

				ToolbarBuilder.AddToolBarButton(FMeshSwapAnimationEditorCommands::Get().SetShowGrid);
				ToolbarBuilder.AddToolBarButton(FMeshSwapAnimationEditorCommands::Get().SetShowBounds);

				ToolbarBuilder.AddSeparator();

				ToolbarBuilder.AddToolBarButton(FMeshSwapAnimationEditorCommands::Get().SetShowCollision);
			}
		}
	};

	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);

	ToolbarExtender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		/*ViewportPtr->GetCommandList()*/ GetToolkitCommands(),
		FToolBarExtensionDelegate::CreateStatic( &Local::FillToolbar )
		);

	AddToolbarExtender(ToolbarExtender);

 	IMeshSwapperEditorModule* MeshSwapperEditorModule = &FModuleManager::LoadModuleChecked<IMeshSwapperEditorModule>("MeshSwapperEditor");
 	AddToolbarExtender(MeshSwapperEditorModule->GetMeshSwapAnimationEditorToolBarExtensibilityManager()->GetAllExtenders());
}

void FMeshSwapAnimationEditor::DeleteSelection()
{
	if (MeshSwapAnimationBeingEdited->IsValidKeyFrameIndex(CurrentSelectedKeyframe))
	{
		const FScopedTransaction Transaction(LOCTEXT("DeleteKeyframe", "Delete Keyframe"));
		MeshSwapAnimationBeingEdited->Modify();

		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimationBeingEdited);
		EditLock.KeyFrames.RemoveAt(CurrentSelectedKeyframe);

		CurrentSelectedKeyframe = INDEX_NONE;
	}
}

void FMeshSwapAnimationEditor::DuplicateSelection()
{
	if (MeshSwapAnimationBeingEdited->IsValidKeyFrameIndex(CurrentSelectedKeyframe))
	{
		const FScopedTransaction Transaction(LOCTEXT("DuplicateKeyframe", "Duplicate Keyframe"));
		MeshSwapAnimationBeingEdited->Modify();

		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimationBeingEdited);

		FMeshKeyFrameData NewFrame = EditLock.KeyFrames[CurrentSelectedKeyframe];
		EditLock.KeyFrames.Insert(NewFrame, CurrentSelectedKeyframe);

		CurrentSelectedKeyframe = INDEX_NONE;
	}
}

void FMeshSwapAnimationEditor::AddKeyFrameAtCurrentTime()
{
	const FScopedTransaction Transaction(LOCTEXT("InsertKeyFrame", "Insert Key Frame"));
	MeshSwapAnimationBeingEdited->Modify();

	const float CurrentTime = GetPlaybackPosition();
	const int32 KeyFrameIndex = MeshSwapAnimationBeingEdited->GetKeyFrameIndexAtTime(CurrentTime);
	const int32 ClampedIndex = FMath::Clamp<int32>(KeyFrameIndex, 0, MeshSwapAnimationBeingEdited->GetNumFrames());

	FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimationBeingEdited);
	FMeshKeyFrameData NewFrame;
	EditLock.KeyFrames.Insert(NewFrame, ClampedIndex);
}

void FMeshSwapAnimationEditor::AddNewKeyFrameAtEnd()
{
	const FScopedTransaction Transaction(LOCTEXT("AddKeyFrame", "Add Key Frame"));
	MeshSwapAnimationBeingEdited->Modify();

	FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimationBeingEdited);

	FMeshKeyFrameData& NewFrame = *new (EditLock.KeyFrames) FMeshKeyFrameData();
}

void FMeshSwapAnimationEditor::AddNewKeyFrameBefore()
{
	if (MeshSwapAnimationBeingEdited->IsValidKeyFrameIndex(CurrentSelectedKeyframe))
	{
		const FScopedTransaction Transaction(LOCTEXT("InsertKeyFrameBefore", "Insert Key Frame Before"));
		MeshSwapAnimationBeingEdited->Modify();

		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimationBeingEdited);

		FMeshKeyFrameData NewFrame;
		EditLock.KeyFrames.Insert(NewFrame, CurrentSelectedKeyframe);

		CurrentSelectedKeyframe = INDEX_NONE;
	}
}

void FMeshSwapAnimationEditor::AddNewKeyFrameAfter()
{
	if (MeshSwapAnimationBeingEdited->IsValidKeyFrameIndex(CurrentSelectedKeyframe))
	{
		const FScopedTransaction Transaction(LOCTEXT("InsertKeyFrameAfter", "Insert Key Frame After"));
		MeshSwapAnimationBeingEdited->Modify();

		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimationBeingEdited);

		FMeshKeyFrameData NewFrame;
		EditLock.KeyFrames.Insert(NewFrame, CurrentSelectedKeyframe + 1);

		CurrentSelectedKeyframe = INDEX_NONE;
	}
}


void FMeshSwapAnimationEditor::CopySelectionTransform()
{
	if (MeshSwapAnimationBeingEdited->IsValidKeyFrameIndex(CurrentSelectedKeyframe))
	{
		SavedTransform = MeshSwapAnimationBeingEdited->GetKeyFrameChecked(CurrentSelectedKeyframe).RelativeTransform;
	}
}


void FMeshSwapAnimationEditor::PasteSavedTransformToSelection()
{
	if (MeshSwapAnimationBeingEdited->IsValidKeyFrameIndex(CurrentSelectedKeyframe))
	{
		const FScopedTransaction Transaction(LOCTEXT("PasteTranform", "Paste Tranform"));
		MeshSwapAnimationBeingEdited->Modify();

		FScopedMeshSwapAnimationMutator EditLock(MeshSwapAnimationBeingEdited);

		EditLock.KeyFrames[CurrentSelectedKeyframe].RelativeTransform = SavedTransform;
	}
}

void FMeshSwapAnimationEditor::SetSelection(int32 NewSelection)
{
	CurrentSelectedKeyframe = NewSelection;
}

bool FMeshSwapAnimationEditor::HasValidSelection() const
{
	return MeshSwapAnimationBeingEdited->IsValidKeyFrameIndex(CurrentSelectedKeyframe);
}

FReply FMeshSwapAnimationEditor::OnClick_Forward()
{
	UMeshSwapperComponent* PreviewComponent = GetPreviewComponent();

	const bool bIsReverse = PreviewComponent->IsReversing();
	const bool bIsPlaying = PreviewComponent->IsPlaying();
		
	if (bIsReverse && bIsPlaying)
	{
		// Play forwards instead of backwards
		PreviewComponent->Play();
	}
	else if (bIsPlaying)
	{
		// Was already playing forwards, so pause
		PreviewComponent->Stop();
	}
	else
	{
		// Was paused, start playing
		PreviewComponent->Play();
	}

	return FReply::Handled();
}

FReply FMeshSwapAnimationEditor::OnClick_Forward_Step()
{
	GetPreviewComponent()->Stop();
	SetCurrentFrame(GetCurrentFrame() + 1);
	return FReply::Handled();
}

FReply FMeshSwapAnimationEditor::OnClick_Forward_End()
{
	UMeshSwapperComponent* PreviewComponent = GetPreviewComponent();
	PreviewComponent->Stop();
	PreviewComponent->SetPlaybackPosition(PreviewComponent->GetAnimationLength(), false, false, false);
	return FReply::Handled();
}

FReply FMeshSwapAnimationEditor::OnClick_Backward()
{
	UMeshSwapperComponent* PreviewComponent = GetPreviewComponent();

	const bool bIsReverse = PreviewComponent->IsReversing();
	const bool bIsPlaying = PreviewComponent->IsPlaying();

	if (bIsReverse && bIsPlaying)
	{
		// Was already playing backwards, so pause
		PreviewComponent->Stop();
	}
	else if (bIsPlaying)
	{
		// Play backwards instead of forwards
		PreviewComponent->Reverse();
	}
	else
	{
		// Was paused, start reversing
		PreviewComponent->Reverse();
	}

	return FReply::Handled();
}

FReply FMeshSwapAnimationEditor::OnClick_Backward_Step()
{
	GetPreviewComponent()->Stop();
	SetCurrentFrame(GetCurrentFrame() - 1);
	return FReply::Handled();
}

FReply FMeshSwapAnimationEditor::OnClick_Backward_End()
{
	UMeshSwapperComponent* PreviewComponent = GetPreviewComponent();
	PreviewComponent->Stop();
	PreviewComponent->SetPlaybackPosition(0.0f, false, false, false);
	return FReply::Handled();
}

FReply FMeshSwapAnimationEditor::OnClick_ToggleLoop()
{
	UMeshSwapperComponent* PreviewComponent = GetPreviewComponent();
	PreviewComponent->SetLooping(!PreviewComponent->IsLooping());
	return FReply::Handled();
}

EPlaybackMode::Type FMeshSwapAnimationEditor::GetPlaybackMode() const
{
	UMeshSwapperComponent* PreviewComponent = GetPreviewComponent();
	if (PreviewComponent->IsPlaying())
	{
		return PreviewComponent->IsReversing() ? EPlaybackMode::PlayingReverse : EPlaybackMode::PlayingForward;
	}
	else
	{
		return EPlaybackMode::Stopped;
	}
}

uint32 FMeshSwapAnimationEditor::GetTotalFrameCount() const
{
	return MeshSwapAnimationBeingEdited->GetNumFrames();
}

uint32 FMeshSwapAnimationEditor::GetTotalFrameCountPlusOne() const
{
	return MeshSwapAnimationBeingEdited->GetNumFrames() + 1;
}

float FMeshSwapAnimationEditor::GetTotalSequenceLength() const
{
	return MeshSwapAnimationBeingEdited->GetTotalDuration();
}

float FMeshSwapAnimationEditor::GetPlaybackPosition() const
{
	return GetPreviewComponent()->GetPlaybackPosition();
}

void FMeshSwapAnimationEditor::SetPlaybackPosition(float NewTime)
{
	NewTime = FMath::Clamp<float>(NewTime, 0.0f, GetTotalSequenceLength());

	GetPreviewComponent()->SetPlaybackPosition(NewTime, false, false, false);
}

bool FMeshSwapAnimationEditor::IsLooping() const
{
	return GetPreviewComponent()->IsLooping();
}

float FMeshSwapAnimationEditor::GetViewRangeMin() const
{
	return ViewInputMin;
}

float FMeshSwapAnimationEditor::GetViewRangeMax() const
{
	// See if the MeshSwapAnimation changed length, and if so reframe the scrub bar to include the full length
	//@TODO: This is a pretty odd place to put it, but there's no callback for a modified timeline at the moment, so...
	const float SequenceLength = GetTotalSequenceLength();
	if (SequenceLength != LastObservedSequenceLength)
	{
		LastObservedSequenceLength = SequenceLength;
		ViewInputMin = 0.0f;
		ViewInputMax = SequenceLength;
	}

	return ViewInputMax;
}

void FMeshSwapAnimationEditor::SetViewRange(float NewMin, float NewMax)
{
	ViewInputMin = FMath::Max<float>(NewMin, 0.0f);
	ViewInputMax = FMath::Min<float>(NewMax, GetTotalSequenceLength());
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
