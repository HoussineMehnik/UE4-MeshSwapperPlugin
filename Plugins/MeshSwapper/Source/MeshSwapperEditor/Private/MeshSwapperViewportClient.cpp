// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MeshSwapperViewportClient.h"
#include "AssetEditorModeManager.h"
#include "CanvasTypes.h"
#include "SEditorViewport.h"
#include "Components/PrimitiveComponent.h"
#include "Utils.h"
#include "SlateApplication.h"
#include "MultiBoxBuilder.h"
#include "SButton.h"
#include "MeshSwapperEditorShared/SocketEditing.h"
#include <ScopedTransaction.h>
#include "MeshSwapperComponent.h"




#define LOCTEXT_NAMESPACE "FMeshSwapperViewportClient"

//////////////////////////////////////////////////////////////////////////
// FMeshSwapperViewportClient

FMeshSwapperViewportClient::FMeshSwapperViewportClient(const TWeakPtr<SEditorViewport>& InEditorViewportWidget)
	: FEditorViewportClient(new FAssetEditorModeManager(), nullptr, InEditorViewportWidget)
	, OwnedPreviewScene(FPreviewScene::ConstructionValues())
	, bForceInitialFocus(true)
	, CurrentViewportWidget(InEditorViewportWidget.Pin())
{
	bOwnsModeTools = true;


	PreviewScene = &OwnedPreviewScene;

	SetRealtime(true);

	bShowPivot = true;
	bShowSockets = true;
	bShowBoxes = true;

	
	OwnedPreviewScene.SetFloorVisibility(false);
	OwnedPreviewScene.SetFloorOffset(-FLT_MAX);
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
}

FMeshSwapperViewportClient::~FMeshSwapperViewportClient()
{

}


void FMeshSwapperViewportClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);

	if (bForceInitialFocus)
	{
		if (GetRenderedComponent() != nullptr)
		{
			FocusViewportOnBox(GetRenderedComponent()->Bounds.GetBox(), true);
		}
		bForceInitialFocus = false;
	}

	bool bForceHide = false;
	if (UMeshSwapperComponent* MeshSwapperComp = Cast<UMeshSwapperComponent>(GetRenderedComponent()))
	{
		if (MeshSwapperComp->IsPlaying())
		{
			bForceHide = true;
		}
	}
	

	if (bForceHide && GetWidgetMode() != FWidget::WM_None)
	{
		SetWidgetMode(FWidget::WM_None);
	}
	else if (!bForceHide && GetWidgetMode() == FWidget::WM_None)
	{
		SetWidgetMode(FWidget::WM_Translate);
	}

}



void FMeshSwapperViewportClient::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEditorViewportClient::AddReferencedObjects(Collector);

}


void FMeshSwapperViewportClient::Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	

	UPrimitiveComponent* RendererComp = GetRenderedComponent();

	if (bShowPivot && RendererComp != nullptr)
	{
		FUnrealEdUtils::DrawWidget(View, PDI, FMatrix::Identity, 0, 0, EAxisList::Screen, EWidgetMovementMode::WMM_Translate);
	}

	if (bShowSockets &&  RendererComp != nullptr)
	{
		FSocketEditingHelper::DrawSockets(RendererComp, View, PDI);
	}



FEditorViewportClient::Draw(View, PDI);

}


void FMeshSwapperViewportClient::Draw(FViewport* Viewport, FCanvas* Canvas)
{


	FEditorViewportClient::Draw(Viewport, Canvas);

	
}

bool FMeshSwapperViewportClient::InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed /*= 1.f*/, bool bGamepad /*= false*/)
{

	if (Key == EKeys::LeftShift || Key == EKeys::RightShift)
	{
		Invalidate();
		return true;
	}


	if (Key == EKeys::F && Event == IE_Pressed)
	{
		if (GetRenderedComponent() != nullptr)
		{
			FocusViewportOnBox(GetRenderedComponent()->Bounds.GetBox(), true);
			return true;
		}
		return true;
	}


	return FEditorViewportClient::InputKey(Viewport, ControllerId, Key, Event, AmountDepressed, bGamepad);
}


void FMeshSwapperViewportClient::ProcessClick(FSceneView& View, HHitProxy* HitProxy, FKey Key, EInputEvent Event, uint32 HitX, uint32 HitY)
{
	

	FEditorViewportClient::ProcessClick(View, HitProxy, Key, Event, HitX, HitY);


}



FVector FMeshSwapperViewportClient::GetWidgetLocation() const
{
	if (HasValidKeyFrameAsset())
	{
		FMeshKeyFrameData* Keyframe = GetEditedKeyFrameData();
		if(GetRenderedComponent() != nullptr)
		{
			return GetRenderedComponent()->GetComponentLocation();
		}
	}

	return FVector::ZeroVector;
}


FMatrix FMeshSwapperViewportClient::GetWidgetCoordSystem() const
{
	/*if (GetWidgetCoordSystemSpace() == COORD_Local || GetWidgetMode() == FWidget::WM_Rotate)
	{
	return FRotationMatrix::Make(AnimatedRenderComponent->GetComponentQuat());
	}*/
	return FEditorViewportClient::GetWidgetCoordSystem();
}


bool FMeshSwapperViewportClient::InputWidgetDelta(FViewport* InViewport, EAxisList::Type CurrentAxis, FVector& Drag, FRotator& Rot, FVector& Scale)
{



	if (CurrentAxis != EAxisList::None)
	{

		bool bHandled = false;
		if (HasValidKeyFrameAsset())
		{
			FMeshKeyFrameData* Keyframe = GetEditedKeyFrameData();

			if (CurrentAxis != EAxisList::None && Keyframe != nullptr)
			{

				bool bHandled = false;
				if (!Drag.IsNearlyZero())
				{
					Keyframe->RelativeTransform.Location += Drag;
					bHandled = true;
					bManipulatingTransform = true;
				}

				if (!Rot.IsNearlyZero())
				{
					Keyframe->RelativeTransform.Rotation += Rot;
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

				if (bHandled && GetRenderedComponent() != nullptr)
				{
					GetRenderedComponent()->SetRelativeTransform(Keyframe->RelativeTransform.ToTransform());
				}

				return bHandled;
			}

		}
		return bHandled;
	}

	return FEditorViewportClient::InputWidgetDelta(InViewport, CurrentAxis, Drag, Rot, Scale);
}



void FMeshSwapperViewportClient::TrackingStarted(const struct FInputEventState& InInputState, bool bIsDragging, bool bNudge)
{
	//@TODO: Should push this into FEditorViewportClient
	// Begin transacting.  Give the current editor mode an opportunity to do the transacting.
	const bool bTrackingHandledExternally = ModeTools->StartTracking(this, Viewport);

	if (bIsDragging && !bTrackingHandledExternally)
	{
		BeginTransaction(LOCTEXT("ModificationInViewport", "Modification in Viewport"));
	}
}

void FMeshSwapperViewportClient::TrackingStopped()
{
	// Stop transacting.  Give the current editor mode an opportunity to do the transacting.
	const bool bTransactingHandledByEditorMode = ModeTools->EndTracking(this, Viewport);

	if (!bTransactingHandledByEditorMode)
	{
		EndTransaction();
	}
}


void FMeshSwapperViewportClient::BeginTransaction(const FText& SessionName)
{
	if (ScopedTransaction == nullptr)
	{
		ScopedTransaction = new FScopedTransaction(SessionName);

		if (UMeshSwapAnimation* AnimAsset = Cast<UMeshSwapAnimation>(GetEditedAsset()))
		{
			AnimAsset->Modify();
		}
	}
}

void FMeshSwapperViewportClient::MarkTransactionAsDirty()
{
	Invalidate();
	if (UMeshSwapAnimation* AnimAsset = Cast<UMeshSwapAnimation>(GetEditedAsset()))
	{
		AnimAsset->PostEditChange();
	}
}

void FMeshSwapperViewportClient::EndTransaction()
{
	if (ScopedTransaction != nullptr)
	{
		if (bManipulatingTransform)
		{
			if (UMeshSwapAnimation* AnimAsset = Cast<UMeshSwapAnimation>(GetEditedAsset()))
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



class UPrimitiveComponent* FMeshSwapperViewportClient::GetRenderedComponent() const
{
	return nullptr;
}

struct FMeshKeyFrameData* FMeshSwapperViewportClient::GetEditedKeyFrameData() const
{
	return nullptr;
}


class UObject* FMeshSwapperViewportClient::GetEditedAsset() const
{
	return nullptr;
}

bool FMeshSwapperViewportClient::HasValidKeyFrameAsset() const
{
	const FMeshKeyFrameData* Keyframe = GetEditedKeyFrameData();
	return (Keyframe != nullptr);
}






#undef LOCTEXT_NAMESPACE
