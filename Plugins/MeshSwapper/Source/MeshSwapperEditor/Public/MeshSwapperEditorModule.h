// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "Modules/ModuleInterface.h"


//////////////////////////////////////////////////////////////////////////
// IMeshSwapperEditorModule

class IMeshSwapperEditorModule : public IModuleInterface
{
public:
	
	virtual TSharedPtr<class FExtensibilityManager> GetMeshSwapAnimationEditorMenuExtensibilityManager() { return nullptr; }
	virtual TSharedPtr<class FExtensibilityManager> GetMeshSwapAnimationEditorToolBarExtensibilityManager() { return nullptr; }

	virtual uint32 GetMeshSwapperAssetCategory() const = 0;
};

