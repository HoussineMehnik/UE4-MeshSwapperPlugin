//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Factories/Factory.h"
#include "MeshSwapAnimation.h"
#include "MeshSwapAnimationFactory.generated.h"


/**
 * Factory for MeshSwapAnimation
 */

UCLASS()
class MESHSWAPPEREDITOR_API UMeshSwapAnimationFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	TArray<FMeshKeyFrameData> KeyFrames;

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	// End of UFactory interface
};
