// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MeshSwapAnimationEditor/MeshSwapperComponentDetails.h"
#include "DetailLayoutBuilder.h"

#define LOCTEXT_NAMESPACE "MeshSwapperComponentDetailsCustomization"

//////////////////////////////////////////////////////////////////////////
// FMeshSwapperComponentDetailsCustomization

TSharedRef<IDetailCustomization> FFMeshSwapperComponentDetailsCustomization::MakeInstance()
{
	return MakeShareable(new FFMeshSwapperComponentDetailsCustomization);
}

void FFMeshSwapperComponentDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	// Create a category so this is displayed early in the properties
	DetailBuilder.EditCategory("MeshKeyFrame", FText::GetEmpty(), ECategoryPriority::Important);
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
