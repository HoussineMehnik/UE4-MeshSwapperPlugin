// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MeshSwapperEditor/Public/MeshSwapAnimationFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMeshSwapAnimationFactory() {}
// Cross Module References
	MESHSWAPPEREDITOR_API UClass* Z_Construct_UClass_UMeshSwapAnimationFactory_NoRegister();
	MESHSWAPPEREDITOR_API UClass* Z_Construct_UClass_UMeshSwapAnimationFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_MeshSwapperEditor();
// End Cross Module References
	void UMeshSwapAnimationFactory::StaticRegisterNativesUMeshSwapAnimationFactory()
	{
	}
	UClass* Z_Construct_UClass_UMeshSwapAnimationFactory_NoRegister()
	{
		return UMeshSwapAnimationFactory::StaticClass();
	}
	struct Z_Construct_UClass_UMeshSwapAnimationFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMeshSwapAnimationFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_MeshSwapperEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimationFactory_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Factory for MeshSwapAnimation\n */" },
		{ "IncludePath", "MeshSwapAnimationFactory.h" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimationFactory.h" },
		{ "ToolTip", "Factory for MeshSwapAnimation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMeshSwapAnimationFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMeshSwapAnimationFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMeshSwapAnimationFactory_Statics::ClassParams = {
		&UMeshSwapAnimationFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimationFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimationFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMeshSwapAnimationFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMeshSwapAnimationFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMeshSwapAnimationFactory, 3776521308);
	template<> MESHSWAPPEREDITOR_API UClass* StaticClass<UMeshSwapAnimationFactory>()
	{
		return UMeshSwapAnimationFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMeshSwapAnimationFactory(Z_Construct_UClass_UMeshSwapAnimationFactory, &UMeshSwapAnimationFactory::StaticClass, TEXT("/Script/MeshSwapperEditor"), TEXT("UMeshSwapAnimationFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMeshSwapAnimationFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
