//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "MeshSwapAnimationEditorSettings.generated.h"

// Settings for the MeshSwapAnimation editor
UCLASS(config=EditorPerProjectUserSettings)
class UMeshSwapAnimationEditorSettings : public UObject
{
	GENERATED_BODY()

public:
	UMeshSwapAnimationEditorSettings();

	/** Background color in the MeshSwapAnimation editor */
	UPROPERTY(config, EditAnywhere, Category=Background, meta=(HideAlphaChannel))
	FColor BackgroundColor;

	/** Should the grid be shown by default when the editor is opened? */
	UPROPERTY(config, EditAnywhere, Category=Background)
	bool bShowGridByDefault;
};
