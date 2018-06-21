// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Attribute.h"
#include "InputCoreTypes.h"
#include "EditorViewportClient.h"
#include "PreviewScene.h"
#include "AdvancedPreviewScene.h"

class FCanvas;
class UMeshSwapperComponent;
class UMeshSwapAnimation;
struct FMeshKeyFrameData;

//////////////////////////////////////////////////////////////////////////
// FMeshSwapAnimationEditorViewportClient

class FMeshSwapAnimationEditorViewportClient :public FEditorViewportClient, public TSharedFromThis<FMeshSwapAnimationEditorViewportClient>
{
public:
	/** Constructor */
	FMeshSwapAnimationEditorViewportClient(const TAttribute<class UMeshSwapAnimation*>& InMeshSwapAnimationBeingEdited, const TWeakPtr<SEditorViewport>& InEditorViewportWidget);
	~FMeshSwapAnimationEditorViewportClient();
	// FViewportClient interface
	virtual FLinearColor GetBackgroundColor() const override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void DrawCanvas(FViewport& InViewport, FSceneView& View, FCanvas& Canvas) override;
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


	TSharedRef<SWidget> GenerateContextMenu(const FName& SocketName);


	// FSerializableObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	// End of FSerializableObject interface

	FMeshKeyFrameData* GetEditedKeyFrameData() const;
	UMeshSwapperComponent* GetPreviewComponent() const
	{
		return AnimatedRenderComponent.Get();
	}

	FReply OnCopySocketName();

	void ToggleShowPivot() { bShowPivot = !bShowPivot; Invalidate(); }
	bool IsShowPivotChecked() const { return bShowPivot; }

	void ToggleShowSockets() { bShowSockets = !bShowSockets; Invalidate(); }
	bool IsShowSocketsChecked() const { return bShowSockets; }

	void ToggleShowParticles() { bShowParticles = !bShowParticles; Invalidate(); }
	bool IsShowParticlesChecked() const { return bShowParticles; }

	void TogglePlaySounds() { bPlaySounds = !bPlaySounds; Invalidate(); }
	bool IsPlaySoundsChecked() const { return bPlaySounds; }


private:

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

	FName SocketNameToCopy;

protected:
	// The preview scene
	FAdvancedPreviewScene OwnedPreviewScene;

	TSharedPtr<class SEditorViewport> CurrentViewportWidget;

	// The MeshSwapAnimation being displayed in this client
	TAttribute<class UMeshSwapAnimation*> MeshSwapAnimationBeingEdited;

	// A cached pointer to the MeshSwapAnimation that was being edited last frame. Used for invalidation reasons.
	TWeakObjectPtr<class UMeshSwapAnimation> MeshSwapAnimationBeingEditedLastFrame;

	// Render component for the mesh keyframe being edited
	TWeakObjectPtr<UMeshSwapperComponent> AnimatedRenderComponent;

};
