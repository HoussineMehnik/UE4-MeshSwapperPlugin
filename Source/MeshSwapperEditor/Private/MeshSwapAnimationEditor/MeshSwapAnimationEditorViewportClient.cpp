//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapAnimationEditor/MeshSwapAnimationEditorViewportClient.h"
#include "CanvasItem.h"
#include "Engine/Engine.h"
#include "EngineGlobals.h"
#include "Engine/CollisionProfile.h"
#include "Utils.h"
#include "CanvasTypes.h"
#include "MeshSwapperComponent.h"
#include "MeshSwapAnimationEditorSettings.h"
#include "MeshSwapperEditorShared/SocketEditing.h"
#include "MeshSwapAnimation.h"
#include "AudioDevice.h"
#include "AssetEditorModeManager.h"
#include "CanvasTypes.h"
#include "SEditorViewport.h"
#include "Components/PrimitiveComponent.h"
#include "Utils.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Widgets/Input/SButton.h"
#include "MeshSwapperEditorShared/SocketEditing.h"
#include "ScopedTransaction.h"
#include "MeshSwapperComponent.h"
#include "MeshSwapperEditorHitProxies.h"
#include "Components/StaticMeshComponent.h"
#include "Widgets/SWidget.h"
#include "MeshSwapAnimationEditorCommands.h"
#include "Framework/Commands/GenericCommands.h"
#include "PropertyCustomizationHelpers.h"
#include "HAL/PlatformApplicationMisc.h"

#define LOCTEXT_NAMESPACE "MeshSwapAnimationEditor"

//////////////////////////////////////////////////////////////////////////
// FMeshSwapAnimationEditorViewportClient

FMeshSwapAnimationEditorViewportClient::FMeshSwapAnimationEditorViewportClient(const TAttribute<UMeshSwapAnimation*>& InMeshSwapAnimationBeingEdited, const TWeakPtr<SEditorViewport>& InEditorViewportWidget)
	: FEditorViewportClient(nullptr, nullptr, InEditorViewportWidget)
	, bForceInitialFocus(true)
	, OwnedPreviewScene(FPreviewScene::ConstructionValues())
	, CurrentViewportWidget(InEditorViewportWidget.Pin())
	, AnimatedRenderComponent(nullptr)
{
	PreviewScene = &OwnedPreviewScene;
	MeshSwapAnimationBeingEdited = InMeshSwapAnimationBeingEdited;
	MeshSwapAnimationBeingEditedLastFrame = MeshSwapAnimationBeingEdited.Get();



	// Create a render component for the anim being edited
	AnimatedRenderComponent = NewObject<UMeshSwapperComponent>();
	AnimatedRenderComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	AnimatedRenderComponent->SetAnimation(MeshSwapAnimationBeingEdited.Get());
	AnimatedRenderComponent->UpdateBounds();
	PreviewScene->AddComponent(AnimatedRenderComponent.Get(), FTransform::Identity);

	DrawHelper.bDrawGrid = GetDefault<UMeshSwapAnimationEditorSettings>()->bShowGridByDefault;

	// Set audio mute option
	UWorld* World = PreviewScene->GetWorld();
	if (World)
	{
		World->bAllowAudioPlayback = true;

		if (FAudioDevice* AudioDevice = World->GetAudioDevice().GetAudioDevice())
		{
			AudioDevice->SetUseAttenuationForNonGameWorlds(true);
		}
	}


	
	SetRealtime(true);

	bShowPivot = true;
	bShowSockets = true;
	bShowBoxes = true;


	OwnedPreviewScene.SetFloorVisibility(false);
	OwnedPreviewScene.SetEnvironmentVisibility(true);

	// Setup defaults for the common draw helper.
	static const float GridSize = 2048.0f;
	static const int32 CellSize = 16;
	DrawHelper.bDrawPivot = false;
	DrawHelper.bDrawWorldBox = false;
	DrawHelper.bDrawKillZ = false;
	DrawHelper.bDrawGrid = true;
	DrawHelper.GridColorAxis = FColor(160, 160, 160);
	DrawHelper.GridColorMajor = FColor(144, 144, 144);
	DrawHelper.GridColorMinor = FColor(128, 128, 128);
	DrawHelper.PerspectiveGridSize = GridSize;
	DrawHelper.NumCells = DrawHelper.PerspectiveGridSize / (CellSize * 2);


	SetViewMode(VMI_Lit);

	SetViewportType(LVT_Perspective);

	EngineShowFlags.SetTranslucency(true);
	EngineShowFlags.SetSeparateTranslucency(true);
	EngineShowFlags.SetSnap(true);
	EngineShowFlags.SetCompositeEditorPrimitives(true);
	OverrideNearClipPlane(1.0f);
	bUsingOrbitCamera = true;
	bShouldCheckHitProxy = true;



	EngineShowFlags.SetPostProcessing(false);


	const bool bAdvancedShowFlags = true;
	if (bAdvancedShowFlags)
	{
		EngineShowFlags.EnableAdvancedFeatures();
	}
	else
	{
		EngineShowFlags.DisableAdvancedFeatures();
	}

	ScopedTransaction = nullptr;
	bManipulatingTransform = false;
	SocketNameToCopy = NAME_None;
}


FMeshSwapAnimationEditorViewportClient::~FMeshSwapAnimationEditorViewportClient()
{

}

FLinearColor FMeshSwapAnimationEditorViewportClient::GetBackgroundColor() const
{
	return GetDefault<UMeshSwapAnimationEditorSettings>()->BackgroundColor;
}

void FMeshSwapAnimationEditorViewportClient::DrawCanvas(FViewport& InViewport, FSceneView& View, FCanvas& Canvas)
{
	FEditorViewportClient::DrawCanvas(InViewport, View, Canvas);

	const bool bIsHitTesting = Canvas.IsHitTesting();
	if (!bIsHitTesting)
	{
		Canvas.SetHitProxy(nullptr);
	}


	if (bShowSockets)
	{
		FSocketEditingHelper::DrawSocketNames(AnimatedRenderComponent.Get(), InViewport, View, Canvas);
	}
}

void FMeshSwapAnimationEditorViewportClient::Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	if (UMeshSwapperComponent* MeshSwapperComponentComp = AnimatedRenderComponent.Get())
	{

		if (bShowPivot)
		{
			FUnrealEdUtils::DrawWidget(View, PDI, FMatrix::Identity, 0, 0, EAxisList::Screen, EWidgetMovementMode::WMM_Translate);
		}

		if (bShowSockets)
		{
			bool bIsPlaying = MeshSwapperComponentComp->IsPlaying();


			{
				const float DiamondSize = 5.0f;
				const FColor UnselectedDiamondColor(255, 128, 128);
				const FColor SelectedDiamondColor(FColor::White);

				TArray<FComponentSocketDescription> SocketList;
				MeshSwapperComponentComp->QuerySupportedSockets(/*out*/ SocketList);

				for (const FComponentSocketDescription& Socket : SocketList)
				{
					if (!bIsPlaying)
					{
						PDI->SetHitProxy(new HKeyMeshSocketHitProxy(Socket.Name));
					}

					const FColor& DiamondColor = UnselectedDiamondColor;
					const FMatrix SocketTM = MeshSwapperComponentComp->GetSocketTransform(Socket.Name, RTS_World).ToMatrixWithScale();
					DrawWireDiamond(PDI, SocketTM, DiamondSize, DiamondColor, SDPG_Foreground);

					if (!bIsPlaying)
					{
						PDI->SetHitProxy(nullptr);
					}

				}
			}
		}
	}

	FEditorViewportClient::Draw(View, PDI);
}


void FMeshSwapAnimationEditorViewportClient::Draw(FViewport* InViewport, FCanvas* Canvas)
{

	FEditorViewportClient::Draw(InViewport, Canvas);

}

void FMeshSwapAnimationEditorViewportClient::Tick(float DeltaSeconds)
{


	
	if (AnimatedRenderComponent.IsValid())
	{
		if (bForceInitialFocus)
		{
			FocusViewportOnBox(AnimatedRenderComponent->Bounds.GetBox(), true);
			bForceInitialFocus = false;
		}

		bool bForceHide = false;
		if (AnimatedRenderComponent->IsPlaying())
		{
			bForceHide = true;
		}
		if (bForceHide && GetWidgetMode() != UE::Widget::WM_None)
		{
			SetWidgetMode(UE::Widget::WM_None);
		}
		else if (!bForceHide && GetWidgetMode() == UE::Widget::WM_None)
		{
			SetWidgetMode(UE::Widget::WM_Translate);
		}


		UMeshSwapAnimation* MeshSwapAnimation = MeshSwapAnimationBeingEdited.Get();
		if (MeshSwapAnimation != MeshSwapAnimationBeingEditedLastFrame.Get())
		{
			AnimatedRenderComponent->SetAnimation(MeshSwapAnimation, false, bShowParticles, bPlaySounds);
			MeshSwapAnimationBeingEditedLastFrame = MeshSwapAnimation;
		}
	}

	//FEditorViewportClient::Tick(DeltaSeconds);

	if (!GIntraFrameDebuggingGameThread)
	{
		OwnedPreviewScene.GetWorld()->Tick(LEVELTICK_All, DeltaSeconds);
		if (AnimatedRenderComponent.IsValid() /*&& AnimatedRenderComponent->IsPlaying()*/)
		{
			AnimatedRenderComponent->TickAnimation(DeltaSeconds, false, bShowParticles, bPlaySounds);
		}
	}
}


bool FMeshSwapAnimationEditorViewportClient::InputWidgetDelta(FViewport* InViewport, EAxisList::Type CurrentAxis, FVector& Drag, FRotator& Rot, FVector& Scale)
{
	if (CurrentAxis != EAxisList::None)
	{

		bool bHandled = false;
		if (FMeshKeyFrameData* Keyframe = GetEditedKeyFrameData())
		{
			if (CurrentAxis != EAxisList::None && Keyframe != nullptr)
			{
				if (!Drag.IsNearlyZero())
				{
					Keyframe->RelativeTransform.Location += Drag;
					bHandled = true;
					bManipulatingTransform = true;
				}

				if (!Rot.IsNearlyZero())
				{
					FQuat CurrentQuat = Keyframe->RelativeTransform.Rotation.Quaternion();
					CurrentQuat *= Rot.Quaternion();
					Keyframe->RelativeTransform.Rotation = CurrentQuat.Rotator();
					bHandled = true;
					bManipulatingTransform = true;
				}

				if (!Scale.IsNearlyZero())
				{
					Keyframe->RelativeTransform.Scale += Scale;
					bHandled = true;
					bManipulatingTransform = true;
				}

				if (bHandled)
				{
					MarkTransactionAsDirty();
				}

				if (bHandled && AnimatedRenderComponent.IsValid())
				{
					AnimatedRenderComponent->SetRelativeTransform(Keyframe->RelativeTransform.ToTransform());
				}

				return bHandled;
			}

		}
		return bHandled;
	}

	return FEditorViewportClient::InputWidgetDelta(InViewport, CurrentAxis, Drag, Rot, Scale);
}


void FMeshSwapAnimationEditorViewportClient::TrackingStarted(const struct FInputEventState& InInputState, bool bIsDragging, bool bNudge)
{
	//@TODO: Should push this into FEditorViewportClient
	// Begin transacting.  Give the current editor mode an opportunity to do the transacting.
	const bool bTrackingHandledExternally = ModeTools->StartTracking(this, Viewport);

	if (bIsDragging && !bTrackingHandledExternally)
	{
		BeginTransaction(LOCTEXT("ModificationInViewport", "Modification in Viewport"));
	}
}


void FMeshSwapAnimationEditorViewportClient::TrackingStopped()
{
	// Stop transacting.  Give the current editor mode an opportunity to do the transacting.
	const bool bTransactingHandledByEditorMode = ModeTools->EndTracking(this, Viewport);

	if (!bTransactingHandledByEditorMode)
	{
		EndTransaction();
	}
}


void FMeshSwapAnimationEditorViewportClient::BeginTransaction(const FText& SessionName)
{
	if (ScopedTransaction == nullptr)
	{
		ScopedTransaction = new FScopedTransaction(SessionName);

		if (UMeshSwapAnimation* AnimAsset = MeshSwapAnimationBeingEdited.Get())
		{
			AnimAsset->Modify();
		}
	}
}


void FMeshSwapAnimationEditorViewportClient::MarkTransactionAsDirty()
{
	Invalidate();
	if (UMeshSwapAnimation* AnimAsset = MeshSwapAnimationBeingEdited.Get())
	{
		AnimAsset->PostEditChange();
	}
}


void FMeshSwapAnimationEditorViewportClient::EndTransaction()
{
	if (ScopedTransaction != nullptr)
	{
		if (bManipulatingTransform)
		{
			if (UMeshSwapAnimation* AnimAsset = MeshSwapAnimationBeingEdited.Get())
			{
				AnimAsset->PostEditChange();
			}
		}
		else
		{
			ScopedTransaction->Cancel();
		}
		if (ScopedTransaction)
			delete ScopedTransaction;

		bManipulatingTransform = false;
		ScopedTransaction = nullptr;

		Invalidate();
	}
}


TSharedRef<SWidget> FMeshSwapAnimationEditorViewportClient::GenerateContextMenu(const FName& SocketName)
{
	const FMeshSwapAnimationEditorCommands& Commands = FMeshSwapAnimationEditorCommands::Get();

	FMenuBuilder MenuBuilder(true, nullptr);
	{
		if (UMeshSwapperComponent* MeshSwapperComponentComp = AnimatedRenderComponent.Get())
		{
			const FText KeyframeSectionTitle = FText::Format(LOCTEXT("KeyframeActionsSectionHeader", "Keyframe #{0} Effects Actions"), FText::AsNumber(MeshSwapperComponentComp->GetCachedFrameIndex()));
			MenuBuilder.BeginSection("KeyframeEffectsActions", KeyframeSectionTitle);
			MenuBuilder.AddWidget(
				SNew(SButton)
				.Text(LOCTEXT("OnCopySocketName", "Copy Socket Name"))
				.ButtonStyle(FAppStyle::Get(), "FlatButton.Success")
				.OnClicked(this, &FMeshSwapAnimationEditorViewportClient::OnCopySocketName)
				, FText::FromString("")
			);
			MenuBuilder.EndSection();
		}
	}

	return MenuBuilder.MakeWidget();
}

void FMeshSwapAnimationEditorViewportClient::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEditorViewportClient::AddReferencedObjects(Collector);
}


bool FMeshSwapAnimationEditorViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	if (EventArgs.Key == EKeys::F && EventArgs.Event == IE_Pressed)
	{
		if (AnimatedRenderComponent.IsValid())
		{
			FocusViewportOnBox(AnimatedRenderComponent->Bounds.GetBox(), true);
			return true;
		}
		return true;
	}


	return FEditorViewportClient::InputKey(EventArgs);
}

void FMeshSwapAnimationEditorViewportClient::ProcessClick(FSceneView& View, HHitProxy* HitProxy, FKey Key, EInputEvent Event, uint32 HitX, uint32 HitY)
{
	FEditorViewportClient::ProcessClick(View, HitProxy, Key, Event, HitX, HitY);

	if (UMeshSwapperComponent* MeshSwapperComponentComp = AnimatedRenderComponent.Get())
	{
		if (!MeshSwapperComponentComp->IsPlaying())
		{
			if (HitProxy && HitProxy->IsA(HKeyMeshSocketHitProxy::StaticGetType()))
			{
				HKeyMeshSocketHitProxy* SocketProxy = (HKeyMeshSocketHitProxy*)HitProxy;
				if (GetEditedKeyFrameData())
				{
					if (Key == EKeys::RightMouseButton && Event == IE_Released)
					{
						//SocketProxy->KeyframeIndex
						const FVector2D MouseCursorLocation = FSlateApplication::Get().GetCursorPos();
						SocketNameToCopy = SocketProxy->SocketName;
						TSharedRef<SWidget> MenuContents = GenerateContextMenu(SocketProxy->SocketName);
						FWidgetPath WidgetPath = FWidgetPath();
						FSlateApplication::Get().PushMenu(CurrentViewportWidget.ToSharedRef(), WidgetPath, MenuContents, MouseCursorLocation, FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));
					}
				}
			}
		}
	}
}


FVector FMeshSwapAnimationEditorViewportClient::GetWidgetLocation() const
{
	if (FMeshKeyFrameData* Keyframe = GetEditedKeyFrameData())
	{
		if (AnimatedRenderComponent.IsValid())
		{
			return AnimatedRenderComponent->GetComponentLocation();
		}
	}

	return FVector::ZeroVector;
}


FMatrix FMeshSwapAnimationEditorViewportClient::GetWidgetCoordSystem() const
{
	if (GetWidgetCoordSystemSpace() == COORD_Local)
	{
		return FRotationMatrix::Make(AnimatedRenderComponent->GetComponentQuat());
	}
	return FEditorViewportClient::GetWidgetCoordSystem();
}


 FMeshKeyFrameData* FMeshSwapAnimationEditorViewportClient::GetEditedKeyFrameData() const
{
	if (AnimatedRenderComponent.IsValid())
	{
		if (!AnimatedRenderComponent->IsPlaying())
		{
			return AnimatedRenderComponent->GetKeyframeDataAtCachedIndex();
		}
	}
	return nullptr;
}


 FReply FMeshSwapAnimationEditorViewportClient::OnCopySocketName()
{
	 FPlatformApplicationMisc::ClipboardCopy(*SocketNameToCopy.ToString());
	 FSlateApplication::Get().DismissAllMenus();
	 return FReply::Handled();
 }

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
