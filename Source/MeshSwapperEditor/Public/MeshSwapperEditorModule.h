//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

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

