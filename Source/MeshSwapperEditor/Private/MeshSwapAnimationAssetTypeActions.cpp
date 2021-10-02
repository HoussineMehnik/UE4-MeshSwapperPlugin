//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapAnimationAssetTypeActions.h"
#include "MeshSwapAnimation.h"
#include "MeshSwapAnimationEditor/MeshSwapAnimationEditor.h"


#define LOCTEXT_NAMESPACE "MeshSwapAnimationAssetTypeActions"

//////////////////////////////////////////////////////////////////////////
// FMeshSwapAnimationAssetTypeActions

FMeshSwapAnimationAssetTypeActions::FMeshSwapAnimationAssetTypeActions(EAssetTypeCategories::Type InAssetCategory)
	: MyAssetCategory(InAssetCategory)
{
}

FText FMeshSwapAnimationAssetTypeActions::GetName() const
{
	return LOCTEXT("MeshSwapAnimationAssetTypeActionsName", "MeshSwap Animation");
}

FColor FMeshSwapAnimationAssetTypeActions::GetTypeColor() const
{
	return FColor::Yellow;
}

UClass* FMeshSwapAnimationAssetTypeActions::GetSupportedClass() const
{
	return UMeshSwapAnimation::StaticClass();
}

void FMeshSwapAnimationAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		if (UMeshSwapAnimation* MeshSwapAnimation = Cast<UMeshSwapAnimation>(*ObjIt))
		{
			TSharedRef<FMeshSwapAnimationEditor> NewMeshSwapAnimationEditor(new FMeshSwapAnimationEditor());
			NewMeshSwapAnimationEditor->InitMeshSwapAnimationEditor(Mode, EditWithinLevelEditor, MeshSwapAnimation);
		}
	}
}

uint32 FMeshSwapAnimationAssetTypeActions::GetCategories()
{
	return EAssetTypeCategories::Animation | MyAssetCategory;
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
