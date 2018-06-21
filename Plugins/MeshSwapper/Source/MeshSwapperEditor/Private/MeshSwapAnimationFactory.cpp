// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MeshSwapAnimationFactory.h"

#define LOCTEXT_NAMESPACE "MeshSwapAnimationFactory"

/////////////////////////////////////////////////////
// UMeshSwapAnimationFactory

UMeshSwapAnimationFactory::UMeshSwapAnimationFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UMeshSwapAnimation::StaticClass();
}

UObject* UMeshSwapAnimationFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UMeshSwapAnimation* NewMeshSwapAnimation = NewObject<UMeshSwapAnimation>(InParent, Class, Name, Flags | RF_Transactional);
	{
		FScopedMeshSwapAnimationMutator EditLock(NewMeshSwapAnimation);
		EditLock.KeyFrames = KeyFrames;
	}
	return NewMeshSwapAnimation;
}

#undef LOCTEXT_NAMESPACE
