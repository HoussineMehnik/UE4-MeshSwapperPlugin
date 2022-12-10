//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapperStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateTypes.h"
#include "Styling/CoreStyle.h"
#include "EditorStyleSet.h"
#include "Interfaces/IPluginManager.h"
#include "SlateOptMacros.h"


#define IMAGE_PLUGIN_BRUSH( RelativePath, ... ) FSlateImageBrush( FMeshSwapperStyle::InContent( RelativePath, ".png" ), __VA_ARGS__ )
#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(StyleSet->RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)
#define BOX_BRUSH(RelativePath, ...) FSlateBoxBrush(StyleSet->RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)
#define DEFAULT_FONT(...) FCoreStyle::GetDefaultFontStyle(__VA_ARGS__)

FString FMeshSwapperStyle::InContent(const FString& RelativePath, const ANSICHAR* Extension)
{
	static FString ContentDir = IPluginManager::Get().FindPlugin(TEXT("MeshSwapper"))->GetContentDir();
	return (ContentDir / RelativePath) + Extension;
}

TSharedPtr< FSlateStyleSet > FMeshSwapperStyle::StyleSet = nullptr;
TSharedPtr< class ISlateStyle > FMeshSwapperStyle::Get() { return StyleSet; }

FName FMeshSwapperStyle::GetAppStyleSetName()
{
	static FName MeshSwapperStyleName(TEXT("MeshSwapperStyle"));
	return MeshSwapperStyleName;
}

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void FMeshSwapperStyle::Initialize()
{
	// Const icon sizes
	const FVector2D Icon8x8(8.0f, 8.0f);
	const FVector2D Icon16x16(16.0f, 16.0f);
	const FVector2D Icon20x20(20.0f, 20.0f);
	const FVector2D Icon40x40(40.0f, 40.0f);
	const FVector2D Icon128x128(128.0f, 128.0f);

	// Only register once
	if (StyleSet.IsValid())
	{
		return;
	}

	StyleSet = MakeShareable(new FSlateStyleSet(GetAppStyleSetName()));
	StyleSet->SetContentRoot(FPaths::EngineContentDir() / TEXT("Editor/Slate"));
	StyleSet->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

	const FTextBlockStyle& NormalText = FAppStyle::Get().GetWidgetStyle<FTextBlockStyle>("NormalText");

	// Shared editors
	{
		StyleSet->Set("MeshSwapper.Common.ViewportZoomTextStyle", FTextBlockStyle(NormalText)
			.SetFont(DEFAULT_FONT("BoldCondensed", 16))
			);

		StyleSet->Set("MeshSwapper.Common.ViewportTitleTextStyle", FTextBlockStyle(NormalText)
			.SetFont(DEFAULT_FONT("Regular", 18))
			.SetColorAndOpacity(FLinearColor(1.0, 1.0f, 1.0f, 0.5f))
			);

		StyleSet->Set("MeshSwapper.Common.ViewportTitleBackground", new BOX_BRUSH("Old/Graph/GraphTitleBackground", FMargin(0)));
	}

	// Class Thumbnails
	{
		StyleSet->Set("ClassIcon.MeshKeyFrame", new IMAGE_PLUGIN_BRUSH("Icons/icon_MeshKeyFrame_128x", Icon16x16));
		StyleSet->Set("ClassThumbnail.MeshKeyFrame", new IMAGE_PLUGIN_BRUSH("Icons/icon_MeshKeyFrame_128x", Icon128x128));

		StyleSet->Set("ClassIcon.MeshSwapAnimation", new IMAGE_PLUGIN_BRUSH("Icons/icon_MeshSwapAnimation_128x", Icon16x16));
		StyleSet->Set("ClassThumbnail.MeshSwapAnimation", new IMAGE_PLUGIN_BRUSH("Icons/icon_MeshSwapAnimation_128x", Icon128x128));

		StyleSet->Set("ClassIcon.MeshSwapperComponent", new IMAGE_PLUGIN_BRUSH("Icons/icon_MeshSwapperComponent_40x", Icon16x16));
		StyleSet->Set("ClassThumbnail.MeshSwapperComponent", new IMAGE_PLUGIN_BRUSH("Icons/icon_MeshSwapperComponent_40x", Icon128x128));

		
	}


	// MeshSwapAnimationEditor editor
	{


		StyleSet->Set("MeshSwapAnimationEditor.SetShowGrid", new IMAGE_BRUSH(TEXT("Icons/icon_MatEd_Grid_40x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.SetShowGrid.Small", new IMAGE_BRUSH(TEXT("Icons/icon_MatEd_Grid_40x"), Icon20x20));
		StyleSet->Set("MeshSwapAnimationEditor.SetShowBounds", new IMAGE_BRUSH(TEXT("Icons/icon_StaticMeshEd_Bounds_40x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.SetShowBounds.Small", new IMAGE_BRUSH(TEXT("Icons/icon_StaticMeshEd_Bounds_40x"), Icon20x20));
		StyleSet->Set("MeshSwapAnimationEditor.SetShowCollision", new IMAGE_BRUSH(TEXT("Icons/icon_StaticMeshEd_Collision_40x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.SetShowCollision.Small", new IMAGE_BRUSH(TEXT("Icons/icon_StaticMeshEd_Collision_40x"), Icon20x20));
		StyleSet->Set("MeshSwapAnimationEditor.SetShowPivot", new IMAGE_BRUSH(TEXT("Icons/icon_StaticMeshEd_ShowPivot_40x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.SetShowPivot.Small", new IMAGE_BRUSH(TEXT("Icons/icon_StaticMeshEd_ShowPivot_40x"), Icon20x20));
		StyleSet->Set("MeshSwapAnimationEditor.SetShowSockets", new IMAGE_BRUSH(TEXT("Icons/icon_StaticMeshEd_ShowSockets_40x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.SetShowSockets.Small", new IMAGE_BRUSH(TEXT("Icons/icon_StaticMeshEd_ShowSockets_40x"), Icon20x20));

		StyleSet->Set("MeshSwapAnimationEditor.AddKeyFrame", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_Flipbook_AddKey_40x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.AddKeyFrame.Small", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_Flipbook_AddKey_40x"), Icon20x20));

		StyleSet->Set("MeshSwapAnimationEditor.ToggleParticles", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_ParticleSystem_On_64x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.ToggleParticles.Small", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_ParticleSystem_On_64x"), Icon20x20));

		StyleSet->Set("MeshSwapAnimationEditor.ToggleSounds", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_Sound_On_64x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.ToggleSounds.Small", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_Sound_On_64x"), Icon20x20));

		StyleSet->Set("MeshSwapAnimationEditor.ToggleSockets", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_Sound_On_64x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.ToggleSockets.Small", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_Sound_On_64x"), Icon20x20));

		StyleSet->Set("MeshSwapAnimationEditor.ResetTransform", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_ResetToDefault_40x"), Icon40x40));
		StyleSet->Set("MeshSwapAnimationEditor.ResetTransform.Small", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/MeshSwapAnimationEditor/icon_ResetToDefault_40x"), Icon20x20));


		StyleSet->Set("MeshSwapAnimationEditor.RegionGrabHandle", new BOX_BRUSH("Sequencer/ScrubHandleWhole", FMargin(6.f / 13.f, 10 / 24.f, 6 / 13.f, 10 / 24.f)));
		StyleSet->Set("MeshSwapAnimationEditor.RegionBody", new BOX_BRUSH("Common/Scrollbar_Thumb", FMargin(4.f / 16.f)));
		StyleSet->Set("MeshSwapAnimationEditor.RegionBorder", new BOX_BRUSH("Common/CurrentCellBorder", FMargin(4.f / 16.f), FLinearColor(1.0f, 1.0f, 1.0f, 1.0f)));
	}


	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
};

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef IMAGE_PLUGIN_BRUSH
#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef DEFAULT_FONT

void FMeshSwapperStyle::Shutdown()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}
