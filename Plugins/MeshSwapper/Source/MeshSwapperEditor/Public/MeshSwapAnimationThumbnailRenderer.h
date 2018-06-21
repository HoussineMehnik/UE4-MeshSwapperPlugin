#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "ThumbnailRendering/DefaultSizedThumbnailRenderer.h"
#include "MeshSwapAnimationThumbnailRenderer.generated.h"

class FCanvas;
class FRenderTarget;

UCLASS(CustomConstructor, Config = Editor)
class UMeshSwapAnimationThumbnailRenderer : public UDefaultSizedThumbnailRenderer
{
	GENERATED_UCLASS_BODY()

		UMeshSwapAnimationThumbnailRenderer(const FObjectInitializer& ObjectInitializer);

	// UThumbnailRenderer interface
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget*, FCanvas* Canvas) override;
	// End of UThumbnailRenderer interface

	virtual bool CanVisualizeAsset(UObject* Object) override;


	virtual void BeginDestroy() override;

private:
	class FStaticMeshThumbnailScene* ThumbnailScene;
};
