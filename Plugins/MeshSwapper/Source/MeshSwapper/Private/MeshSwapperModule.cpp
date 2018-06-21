// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MeshSwapperModule.h"
#include "Misc/ConfigCacheIni.h"
#include "Modules/ModuleManager.h"

//////////////////////////////////////////////////////////////////////////
// FMeshSwapperModule

class FMeshSwapperModule : public IMeshSwapperModuleInterface
{
public:
	virtual void StartupModule() override
	{
		
	}

	virtual void ShutdownModule() override
	{
	}
};

//////////////////////////////////////////////////////////////////////////

IMPLEMENT_MODULE(FMeshSwapperModule, MeshSwapper);

