// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MeshSwapperEditor/Private/MeshSwapAnimationEditor/MeshSwapAnimationEditorSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMeshSwapAnimationEditorSettings() {}
// Cross Module References
	MESHSWAPPEREDITOR_API UClass* Z_Construct_UClass_UMeshSwapAnimationEditorSettings_NoRegister();
	MESHSWAPPEREDITOR_API UClass* Z_Construct_UClass_UMeshSwapAnimationEditorSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_MeshSwapperEditor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
// End Cross Module References
	void UMeshSwapAnimationEditorSettings::StaticRegisterNativesUMeshSwapAnimationEditorSettings()
	{
	}
	UClass* Z_Construct_UClass_UMeshSwapAnimationEditorSettings_NoRegister()
	{
		return UMeshSwapAnimationEditorSettings::StaticClass();
	}
	struct Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BackgroundColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BackgroundColor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowGridByDefault_MetaData[];
#endif
		static void NewProp_bShowGridByDefault_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowGridByDefault;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_MeshSwapperEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// Settings for the MeshSwapAnimation editor\n" },
		{ "IncludePath", "MeshSwapAnimationEditor/MeshSwapAnimationEditorSettings.h" },
		{ "ModuleRelativePath", "Private/MeshSwapAnimationEditor/MeshSwapAnimationEditorSettings.h" },
		{ "ToolTip", "Settings for the MeshSwapAnimation editor" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_BackgroundColor_MetaData[] = {
		{ "Category", "Background" },
		{ "Comment", "/** Background color in the MeshSwapAnimation editor */" },
		{ "HideAlphaChannel", "" },
		{ "ModuleRelativePath", "Private/MeshSwapAnimationEditor/MeshSwapAnimationEditorSettings.h" },
		{ "ToolTip", "Background color in the MeshSwapAnimation editor" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_BackgroundColor = { "BackgroundColor", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapAnimationEditorSettings, BackgroundColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_BackgroundColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_BackgroundColor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_bShowGridByDefault_MetaData[] = {
		{ "Category", "Background" },
		{ "Comment", "/** Should the grid be shown by default when the editor is opened? */" },
		{ "ModuleRelativePath", "Private/MeshSwapAnimationEditor/MeshSwapAnimationEditorSettings.h" },
		{ "ToolTip", "Should the grid be shown by default when the editor is opened?" },
	};
#endif
	void Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_bShowGridByDefault_SetBit(void* Obj)
	{
		((UMeshSwapAnimationEditorSettings*)Obj)->bShowGridByDefault = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_bShowGridByDefault = { "bShowGridByDefault", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UMeshSwapAnimationEditorSettings), &Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_bShowGridByDefault_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_bShowGridByDefault_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_bShowGridByDefault_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_BackgroundColor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::NewProp_bShowGridByDefault,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMeshSwapAnimationEditorSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::ClassParams = {
		&UMeshSwapAnimationEditorSettings::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::PropPointers),
		0,
		0x000000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMeshSwapAnimationEditorSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMeshSwapAnimationEditorSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMeshSwapAnimationEditorSettings, 1283092200);
	template<> MESHSWAPPEREDITOR_API UClass* StaticClass<UMeshSwapAnimationEditorSettings>()
	{
		return UMeshSwapAnimationEditorSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMeshSwapAnimationEditorSettings(Z_Construct_UClass_UMeshSwapAnimationEditorSettings, &UMeshSwapAnimationEditorSettings::StaticClass, TEXT("/Script/MeshSwapperEditor"), TEXT("UMeshSwapAnimationEditorSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMeshSwapAnimationEditorSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
