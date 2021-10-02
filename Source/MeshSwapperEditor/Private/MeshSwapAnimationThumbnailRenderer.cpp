//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapAnimationThumbnailRenderer.h"
#include "Misc/App.h"
#include "CanvasItem.h"
#include "Engine/Engine.h"
#include "EngineGlobals.h"
#include "ShowFlags.h"
#include "SceneView.h"
#include "ThumbnailHelpers.h"
#include "Engine/StaticMesh.h"
#include "RendererInterface.h"
#include "EngineModule.h"

#include "MeshSwapAnimation.h"
#include "Engine/StaticMesh.h"


//////////////////////////////////////////////////////////////////////////
// UMeshSwapAnimationThumbnailRenderer

UMeshSwapAnimationThumbnailRenderer::UMeshSwapAnimationThumbnailRenderer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
, ThumbnailScene(nullptr)
{

}

void UMeshSwapAnimationThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	if (UMeshSwapAnimation* MeshSwapAnimation = Cast<UMeshSwapAnimation>(Object))
	{
		const double DeltaTime = FApp::GetCurrentTime() - GStartTime;
		const float TotalDuration = MeshSwapAnimation->GetTotalDuration();
		const float PlayTime = (TotalDuration > 0.0f) ? FMath::Fmod(DeltaTime, TotalDuration) : 0.0f;

		UStaticMesh* StaticMesh = MeshSwapAnimation->GetStaticMeshAtTime(PlayTime);

		if (StaticMesh != nullptr)
		{

			if (ThumbnailScene == nullptr)
			{
				ThumbnailScene = new FStaticMeshThumbnailScene();
			}

			ThumbnailScene->SetStaticMesh(StaticMesh);
			ThumbnailScene->GetScene()->UpdateSpeedTreeWind(0.0);

			FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(RenderTarget, ThumbnailScene->GetScene(), FEngineShowFlags(ESFIM_Game))
				.SetWorldTimes(DeltaTime, FApp::GetDeltaTime(), DeltaTime));

			ViewFamily.EngineShowFlags.DisableAdvancedFeatures();
			ViewFamily.EngineShowFlags.MotionBlur = 0;
			ViewFamily.EngineShowFlags.LOD = 0;

			ThumbnailScene->GetView(&ViewFamily, X, Y, Width, Height);
			RenderViewFamily(Canvas, &ViewFamily);
			ThumbnailScene->SetStaticMesh(nullptr);
			ThumbnailScene->SetOverrideMaterials(TArray<class UMaterialInterface*>());

			return;
		}


		if (TotalDuration == 0.0f)
		{
			// Warning text for no frames
			const FText ErrorText = NSLOCTEXT("MeshSwapAnimationEditorApp", "ThumbnailWarningNoFrames", "No frames");
			FCanvasTextItem TextItem(FVector2D(5.0f, 5.0f), ErrorText, GEngine->GetLargeFont(), FLinearColor::Red);
			TextItem.EnableShadow(FLinearColor::Black);
			TextItem.Scale = FVector2D(Width / 128.0f, Height / 128.0f);
			TextItem.Draw(Canvas);
		}
	}
}

bool UMeshSwapAnimationThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	UMeshSwapAnimation* FoliageType = Cast<UMeshSwapAnimation>(Object);
	return FoliageType && FoliageType->GetStaticMeshAtFrame(0);
}

void UMeshSwapAnimationThumbnailRenderer::BeginDestroy()
{
	if (ThumbnailScene != nullptr)
	{
		delete ThumbnailScene;
		ThumbnailScene = nullptr;
	}

	Super::BeginDestroy();
}
