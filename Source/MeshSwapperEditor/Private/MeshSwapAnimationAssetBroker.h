//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once

#include "CoreMinimal.h"
#include "ComponentAssetBroker.h"
#include "MeshSwapperComponent.h"
#include "MeshSwapAnimation.h"

//////////////////////////////////////////////////////////////////////////
// FMeshSwapAnimationAssetBroker

class FMeshSwapAnimationAssetBroker : public IComponentAssetBroker
{
public:
	UClass* GetSupportedAssetClass() override
	{
		return UMeshSwapAnimation::StaticClass();
	}

	virtual bool AssignAssetToComponent(UActorComponent* InComponent, UObject* InAsset) override
	{
		if (UMeshSwapperComponent* RenderComp = Cast<UMeshSwapperComponent>(InComponent))
		{
			UMeshSwapAnimation* MeshSwapAnimation = Cast<UMeshSwapAnimation>(InAsset);

			if ((MeshSwapAnimation != nullptr) || (InAsset == nullptr))
			{
				RenderComp->SetAnimation(MeshSwapAnimation, false, false, false);
				return true;
			}
		}

		return false;
	}

	virtual UObject* GetAssetFromComponent(UActorComponent* InComponent) override
	{
		if (UMeshSwapperComponent* RenderComp = Cast<UMeshSwapperComponent>(InComponent))
		{
			return RenderComp->GetAnimation();
		}
		return nullptr;
	}
};

