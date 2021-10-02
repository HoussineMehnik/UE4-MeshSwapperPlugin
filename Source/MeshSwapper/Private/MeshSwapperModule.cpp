//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

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

