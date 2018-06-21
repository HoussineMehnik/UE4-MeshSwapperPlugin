// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorViewportClient.h"
#include "PreviewScene.h"
#include "AdvancedPreviewScene.h"

//////////////////////////////////////////////////////////////////////////
// FMeshSwapperViewportClient


enum class EEditMode :uint8
{
	None,
	RelativeTransform,
};


class SWidget;

class FMeshSwapperViewportClient : public FEditorViewportClient, public TSharedFromThis<FMeshSwapperViewportClient>
{
public:
	/** Constructor */
	explicit FMeshSwapperViewportClient(const TWeakPtr<class SEditorViewport>& InEditorViewportWidget = nullptr);
	~FMeshSwapperViewportClient();

	// FViewportClient interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
	virtual void Draw(FViewport* Viewport, FCanvas* Canvas) override;
	virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.f, bool bGamepad = false) override;
	virtual void ProcessClick(FSceneView& View, HHitProxy* HitProxy, FKey Key, EInputEvent Event, uint32 HitX, uint32 HitY) override;
	virtual FVector GetWidgetLocation() const override;
	virtual FMatrix GetWidgetCoordSystem() const override;
	virtual bool InputWidgetDelta(FViewport* InViewport, EAxisList::Type CurrentAxis, FVector& Drag, FRotator& Rot, FVector& Scale) override;
	void TrackingStarted(const struct FInputEventState& InInputState, bool bIsDragging, bool bNudge) override;
	void TrackingStopped() override;
	// End of FViewportClient interface

	void BeginTransaction(const FText& SessionName);
	void MarkTransactionAsDirty();
	void EndTransaction();

	// FSerializableObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	// End of FSerializableObject interface


	virtual class UPrimitiveComponent* GetRenderedComponent() const;
	virtual struct FMeshKeyFrameData* GetEditedKeyFrameData() const;
	virtual class UObject* GetEditedAsset() const;

	bool HasValidKeyFrameAsset() const;

public:

	void ToggleShowPivot() { bShowPivot = !bShowPivot; Invalidate(); }
	bool IsShowPivotChecked() const { return bShowPivot; }

	void ToggleShowSockets() { bShowSockets = !bShowSockets; Invalidate(); }
	bool IsShowSocketsChecked() const { return bShowSockets; }

	void ToggleShowParticles() { bShowParticles = !bShowParticles; Invalidate(); }
	bool IsShowParticlesChecked() const { return bShowParticles; }

	void TogglePlaySounds() { bPlaySounds = !bPlaySounds; Invalidate(); }
	bool IsPlaySoundsChecked() const { return bPlaySounds; }

protected:
	// The preview scene
	FAdvancedPreviewScene OwnedPreviewScene;

	TSharedPtr<class SEditorViewport> CurrentViewportWidget;



	bool bShowBoxes;
	bool bShowPivot;

	bool bShowParticles;
	bool bPlaySounds;

	// Should we show sockets?
	bool bShowSockets;

	bool bForceInitialFocus;

	// The current transaction for undo/redo
	class FScopedTransaction* ScopedTransaction;

	bool bManipulatingTransform;
};

