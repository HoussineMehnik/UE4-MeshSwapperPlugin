// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

// 
#include "MeshSwapperEditorModule.h"
#include "MeshSwapperEditorLog.h"
#include "Editor.h"
#include "EditorModeRegistry.h"
#include "Modules/ModuleManager.h"
#include "UObject/UObjectHash.h"
#include "UObject/UObjectIterator.h"
#include "ThumbnailRendering/ThumbnailManager.h"
#include "ISettingsModule.h"
#include "AssetToolsModule.h"
#include "PropertyEditorModule.h"
#include "ComponentAssetBroker.h"


// Content Browser
#include "MeshSwapperStyle.h"
#include "MeshSwapperCommands.h"
#include "MeshSwapAnimationAssetTypeActions.h"
#include "MeshSwapAnimationAssetBroker.h"
#include "MeshSwapperComponent.h"
#include "MeshSwapAnimationEditor/MeshSwapperComponentDetails.h"
#include "MeshSwapAnimationThumbnailRenderer.h"
#include "MeshSwapAnimationEditor/MeshSwapAnimationEditorSettings.h"
#include "Subsystems/ImportSubsystem.h"
#include "Editor/EditorEngine.h"







DEFINE_LOG_CATEGORY(LogMeshSwapperEditor);

#define LOCTEXT_NAMESPACE "MeshSwapperEditor"

//////////////////////////////////////////////////////////////////////////
// FMeshSwapperEditor

class FMeshSwapperEditor : public IMeshSwapperEditorModule
{
public:
	FMeshSwapperEditor()
		: MeshSwapperAssetCategoryBit(EAssetTypeCategories::Misc)
	{
	}

	// IMeshSwapperEditorModule interface

	virtual TSharedPtr<FExtensibilityManager> GetMeshSwapAnimationEditorMenuExtensibilityManager() override { return MeshSwapAnimationEditor_MenuExtensibilityManager; }
	virtual TSharedPtr<FExtensibilityManager> GetMeshSwapAnimationEditorToolBarExtensibilityManager() override { return MeshSwapAnimationEditor_ToolBarExtensibilityManager; }


	virtual uint32 GetMeshSwapperAssetCategory() const override { return MeshSwapperAssetCategoryBit; }
	// End of IMeshSwapperEditorModule

private:


	TSharedPtr<FExtensibilityManager> MeshSwapAnimationEditor_MenuExtensibilityManager;
	TSharedPtr<FExtensibilityManager> MeshSwapAnimationEditor_ToolBarExtensibilityManager;

	/** All created asset type actions.  Cached here so that we can unregister them during shutdown. */
	TArray< TSharedPtr<IAssetTypeActions> > CreatedAssetTypeActions;

	TSharedPtr<IComponentAssetBroker> MeshSwapAnimationBroker;

	FDelegateHandle OnPropertyChangedDelegateHandle;
	FDelegateHandle OnAssetReimportDelegateHandle;

	EAssetTypeCategories::Type MeshSwapperAssetCategoryBit;

public:
	virtual void StartupModule() override
	{
	
		MeshSwapAnimationEditor_MenuExtensibilityManager = MakeShareable(new FExtensibilityManager);
		MeshSwapAnimationEditor_ToolBarExtensibilityManager = MakeShareable(new FExtensibilityManager);

		// Register slate style overrides
		FMeshSwapperStyle::Initialize();

		// Register commands
		FMeshSwapperEditorCommands::Register();

		// Register asset types
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		MeshSwapperAssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("MeshSwapper")), LOCTEXT("MeshSwapperAssetCategory", "Mesh Swapper"));

		
	
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FMeshSwapAnimationAssetTypeActions(MeshSwapperAssetCategoryBit)));
	
		MeshSwapAnimationBroker = MakeShareable(new FMeshSwapAnimationAssetBroker);
		FComponentAssetBrokerage::RegisterBroker(MeshSwapAnimationBroker, UMeshSwapperComponent::StaticClass(), true, true);

		// Register the details customizations
		{
			FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
			
			PropertyModule.RegisterCustomClassLayout(UMeshSwapperComponent::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FFMeshSwapperComponentDetailsCustomization::MakeInstance));
		

			PropertyModule.NotifyCustomizationModuleChanged();
		}

		// Register to be notified when properties are edited
		OnPropertyChangedDelegateHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.AddRaw(this, &FMeshSwapperEditor::OnPropertyChanged);

		// Register to be notified when an asset is reimported
		OnAssetReimportDelegateHandle = GEditor->GetEditorSubsystem<UImportSubsystem>()->OnAssetReimport.AddRaw(this, &FMeshSwapperEditor::OnObjectReimported);
		
		//

		UThumbnailManager::Get().RegisterCustomRenderer(UMeshSwapAnimation::StaticClass(), UMeshSwapAnimationThumbnailRenderer::StaticClass());


		//
		RegisterSettings();
	}

	virtual void ShutdownModule() override
	{

		MeshSwapAnimationEditor_MenuExtensibilityManager.Reset();
		MeshSwapAnimationEditor_ToolBarExtensibilityManager.Reset();

		if (UObjectInitialized())
		{
			UnregisterSettings();

			FComponentAssetBrokerage::UnregisterBroker(MeshSwapAnimationBroker);


			
			// Unregister the thumbnail renderers
			UThumbnailManager::Get().UnregisterCustomRenderer(UMeshSwapAnimation::StaticClass());

			// Unregister the property modification handler
			FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(OnPropertyChangedDelegateHandle);

			// Unregister the asset reimport handler
			GEditor->GetEditorSubsystem<UImportSubsystem>()->OnAssetReimport.Remove(OnAssetReimportDelegateHandle);
		}

		// Unregister the details customization
		//@TODO: Unregister them

		// Unregister all the asset types that we registered
		if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
		{
			IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
			for (int32 Index = 0; Index < CreatedAssetTypeActions.Num(); ++Index)
			{
				AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[Index].ToSharedRef());
			}
		}
		CreatedAssetTypeActions.Empty();

		// Unregister commands
		FMeshSwapperEditorCommands::Unregister();

		// Unregister slate style overrides
		FMeshSwapperStyle::Shutdown();
	}
private:
	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
	{
		AssetTools.RegisterAssetTypeActions(Action);
		CreatedAssetTypeActions.Add(Action);
	}

	// Called when a property on the specified object is modified
	void OnPropertyChanged(UObject* ObjectBeingModified, FPropertyChangedEvent& PropertyChangedEvent)
	{
	
	}

	void OnObjectReimported(UObject* InObject)
	{
	
	}

	void RegisterSettings()
	{
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{	
			SettingsModule->RegisterSettings("Editor", "ContentEditors", "MeshSwapAnimationEditor",
				LOCTEXT("MeshSwapAnimationEditorSettingsName", "MeshSwap Animation Editor"),
				LOCTEXT("MeshSwapAnimationEditorSettingsDescription", "Configure the look and feel of the MeshSwap Animation Editor."),
				GetMutableDefault<UMeshSwapAnimationEditorSettings>());
		}
	}

	void UnregisterSettings()
	{
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->UnregisterSettings("Editor", "ContentEditors", "MeshSwapAnimationEditor");
		}
	}
};

//////////////////////////////////////////////////////////////////////////

IMPLEMENT_MODULE(FMeshSwapperEditor, MeshSwapperEditor);

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
