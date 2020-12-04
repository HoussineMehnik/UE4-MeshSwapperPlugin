// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MeshSwapperEditor/Public/MeshSwapAnimationThumbnailRenderer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMeshSwapAnimationThumbnailRenderer() {}
// Cross Module References
	MESHSWAPPEREDITOR_API UClass* Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_NoRegister();
	MESHSWAPPEREDITOR_API UClass* Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer();
	UNREALED_API UClass* Z_Construct_UClass_UDefaultSizedThumbnailRenderer();
	UPackage* Z_Construct_UPackage__Script_MeshSwapperEditor();
// End Cross Module References
	void UMeshSwapAnimationThumbnailRenderer::StaticRegisterNativesUMeshSwapAnimationThumbnailRenderer()
	{
	}
	UClass* Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_NoRegister()
	{
		return UMeshSwapAnimationThumbnailRenderer::StaticClass();
	}
	struct Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDefaultSizedThumbnailRenderer,
		(UObject* (*)())Z_Construct_UPackage__Script_MeshSwapperEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MeshSwapAnimationThumbnailRenderer.h" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimationThumbnailRenderer.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMeshSwapAnimationThumbnailRenderer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_Statics::ClassParams = {
		&UMeshSwapAnimationThumbnailRenderer::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMeshSwapAnimationThumbnailRenderer, 3671373698);
	template<> MESHSWAPPEREDITOR_API UClass* StaticClass<UMeshSwapAnimationThumbnailRenderer>()
	{
		return UMeshSwapAnimationThumbnailRenderer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMeshSwapAnimationThumbnailRenderer(Z_Construct_UClass_UMeshSwapAnimationThumbnailRenderer, &UMeshSwapAnimationThumbnailRenderer::StaticClass, TEXT("/Script/MeshSwapperEditor"), TEXT("UMeshSwapAnimationThumbnailRenderer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMeshSwapAnimationThumbnailRenderer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
