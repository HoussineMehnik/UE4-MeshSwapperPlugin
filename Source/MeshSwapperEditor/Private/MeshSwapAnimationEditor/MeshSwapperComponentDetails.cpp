//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

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
	DetailBuilder.EditCategory("MeshSwapAnimation", FText::GetEmpty(), ECategoryPriority::Important);
	DetailBuilder.HideCategory("StaticMesh");
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
