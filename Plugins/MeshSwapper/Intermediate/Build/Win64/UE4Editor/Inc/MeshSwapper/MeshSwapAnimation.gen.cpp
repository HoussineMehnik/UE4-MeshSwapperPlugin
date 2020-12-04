// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MeshSwapper/Public/MeshSwapAnimation.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMeshSwapAnimation() {}
// Cross Module References
	MESHSWAPPER_API UEnum* Z_Construct_UEnum_MeshSwapper_EMeshAnimCollisionMode();
	UPackage* Z_Construct_UPackage__Script_MeshSwapper();
	MESHSWAPPER_API UScriptStruct* Z_Construct_UScriptStruct_FMeshKeyFrameData();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	MESHSWAPPER_API UScriptStruct* Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData();
	MESHSWAPPER_API UScriptStruct* Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData();
	MESHSWAPPER_API UScriptStruct* Z_Construct_UScriptStruct_FKeyframeRelativeTransform();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	MESHSWAPPER_API UClass* Z_Construct_UClass_UMeshSwapAnimation_NoRegister();
	MESHSWAPPER_API UClass* Z_Construct_UClass_UMeshSwapAnimation();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
	static UEnum* EMeshAnimCollisionMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_MeshSwapper_EMeshAnimCollisionMode, Z_Construct_UPackage__Script_MeshSwapper(), TEXT("EMeshAnimCollisionMode"));
		}
		return Singleton;
	}
	template<> MESHSWAPPER_API UEnum* StaticEnum<EMeshAnimCollisionMode::Type>()
	{
		return EMeshAnimCollisionMode_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EMeshAnimCollisionMode(EMeshAnimCollisionMode_StaticEnum, TEXT("/Script/MeshSwapper"), TEXT("EMeshAnimCollisionMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_MeshSwapper_EMeshAnimCollisionMode_Hash() { return 1917490960U; }
	UEnum* Z_Construct_UEnum_MeshSwapper_EMeshAnimCollisionMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_MeshSwapper();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EMeshAnimCollisionMode"), 0, Get_Z_Construct_UEnum_MeshSwapper_EMeshAnimCollisionMode_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EMeshAnimCollisionMode::NoCollision", (int64)EMeshAnimCollisionMode::NoCollision },
				{ "EMeshAnimCollisionMode::FirstFrameCollision", (int64)EMeshAnimCollisionMode::FirstFrameCollision },
				{ "EMeshAnimCollisionMode::EachFrameCollision", (int64)EMeshAnimCollisionMode::EachFrameCollision },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "EachFrameCollision.Comment", "/** the animation clip changes collision each frame based on the animation (Note: This setting is not recommended and is very expensive, recreating the physics state every frame) */" },
				{ "EachFrameCollision.Name", "EMeshAnimCollisionMode::EachFrameCollision" },
				{ "EachFrameCollision.ToolTip", "the animation clip changes collision each frame based on the animation (Note: This setting is not recommended and is very expensive, recreating the physics state every frame)" },
				{ "FirstFrameCollision.Comment", "/** the animation clip has non-animated collision based on the first frame of the animation */" },
				{ "FirstFrameCollision.Name", "EMeshAnimCollisionMode::FirstFrameCollision" },
				{ "FirstFrameCollision.ToolTip", "the animation clip has non-animated collision based on the first frame of the animation" },
				{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
				{ "NoCollision.Comment", "/** the animation clip has no collision */" },
				{ "NoCollision.Name", "EMeshAnimCollisionMode::NoCollision" },
				{ "NoCollision.ToolTip", "the animation clip has no collision" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_MeshSwapper,
				nullptr,
				"EMeshAnimCollisionMode",
				"EMeshAnimCollisionMode::Type",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Namespaced,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FMeshKeyFrameData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MESHSWAPPER_API uint32 Get_Z_Construct_UScriptStruct_FMeshKeyFrameData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMeshKeyFrameData, Z_Construct_UPackage__Script_MeshSwapper(), TEXT("MeshKeyFrameData"), sizeof(FMeshKeyFrameData), Get_Z_Construct_UScriptStruct_FMeshKeyFrameData_Hash());
	}
	return Singleton;
}
template<> MESHSWAPPER_API UScriptStruct* StaticStruct<FMeshKeyFrameData>()
{
	return FMeshKeyFrameData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMeshKeyFrameData(FMeshKeyFrameData::StaticStruct, TEXT("/Script/MeshSwapper"), TEXT("MeshKeyFrameData"), false, nullptr, nullptr);
static struct FScriptStruct_MeshSwapper_StaticRegisterNativesFMeshKeyFrameData
{
	FScriptStruct_MeshSwapper_StaticRegisterNativesFMeshKeyFrameData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MeshKeyFrameData")),new UScriptStruct::TCppStructOps<FMeshKeyFrameData>);
	}
} ScriptStruct_MeshSwapper_StaticRegisterNativesFMeshKeyFrameData;
	struct Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FrameRun_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FrameRun;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NotifyTag_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NotifyTag;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ParticleEffects_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParticleEffects_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ParticleEffects;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SoundEffects_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoundEffects_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SoundEffects;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RelativeTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RelativeTransform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSmoothTransformInterpolation_MetaData[];
#endif
		static void NewProp_bSmoothTransformInterpolation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSmoothTransformInterpolation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEnableCollision_MetaData[];
#endif
		static void NewProp_bEnableCollision_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnableCollision;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMeshKeyFrameData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "KeyFrame" },
		{ "DisplayThumbnail", "true" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameData, StaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_StaticMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_StaticMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_FrameRun_MetaData[] = {
		{ "Category", "KeyFrame" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_FrameRun = { "FrameRun", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameData, FrameRun), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_FrameRun_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_FrameRun_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_NotifyTag_MetaData[] = {
		{ "Category", "KeyFrame" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_NotifyTag = { "NotifyTag", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameData, NotifyTag), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_NotifyTag_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_NotifyTag_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_ParticleEffects_Inner = { "ParticleEffects", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_ParticleEffects_MetaData[] = {
		{ "Category", "KeyFrame" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_ParticleEffects = { "ParticleEffects", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameData, ParticleEffects), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_ParticleEffects_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_ParticleEffects_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_SoundEffects_Inner = { "SoundEffects", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_SoundEffects_MetaData[] = {
		{ "Category", "KeyFrame" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_SoundEffects = { "SoundEffects", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameData, SoundEffects), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_SoundEffects_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_SoundEffects_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_RelativeTransform_MetaData[] = {
		{ "Category", "KeyFrame" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_RelativeTransform = { "RelativeTransform", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameData, RelativeTransform), Z_Construct_UScriptStruct_FKeyframeRelativeTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_RelativeTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_RelativeTransform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bSmoothTransformInterpolation_MetaData[] = {
		{ "Category", "KeyFrame" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bSmoothTransformInterpolation_SetBit(void* Obj)
	{
		((FMeshKeyFrameData*)Obj)->bSmoothTransformInterpolation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bSmoothTransformInterpolation = { "bSmoothTransformInterpolation", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FMeshKeyFrameData), &Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bSmoothTransformInterpolation_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bSmoothTransformInterpolation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bSmoothTransformInterpolation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bEnableCollision_MetaData[] = {
		{ "Category", "KeyFrame" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bEnableCollision_SetBit(void* Obj)
	{
		((FMeshKeyFrameData*)Obj)->bEnableCollision = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bEnableCollision = { "bEnableCollision", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FMeshKeyFrameData), &Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bEnableCollision_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bEnableCollision_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bEnableCollision_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_StaticMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_FrameRun,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_NotifyTag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_ParticleEffects_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_ParticleEffects,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_SoundEffects_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_SoundEffects,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_RelativeTransform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bSmoothTransformInterpolation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::NewProp_bEnableCollision,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MeshSwapper,
		nullptr,
		&NewStructOps,
		"MeshKeyFrameData",
		sizeof(FMeshKeyFrameData),
		alignof(FMeshKeyFrameData),
		Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMeshKeyFrameData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMeshKeyFrameData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MeshSwapper();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MeshKeyFrameData"), sizeof(FMeshKeyFrameData), Get_Z_Construct_UScriptStruct_FMeshKeyFrameData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMeshKeyFrameData_Hash() { return 1036204465U; }
class UScriptStruct* FMeshKeyFrameParticleEffectData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MESHSWAPPER_API uint32 Get_Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData, Z_Construct_UPackage__Script_MeshSwapper(), TEXT("MeshKeyFrameParticleEffectData"), sizeof(FMeshKeyFrameParticleEffectData), Get_Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Hash());
	}
	return Singleton;
}
template<> MESHSWAPPER_API UScriptStruct* StaticStruct<FMeshKeyFrameParticleEffectData>()
{
	return FMeshKeyFrameParticleEffectData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMeshKeyFrameParticleEffectData(FMeshKeyFrameParticleEffectData::StaticStruct, TEXT("/Script/MeshSwapper"), TEXT("MeshKeyFrameParticleEffectData"), false, nullptr, nullptr);
static struct FScriptStruct_MeshSwapper_StaticRegisterNativesFMeshKeyFrameParticleEffectData
{
	FScriptStruct_MeshSwapper_StaticRegisterNativesFMeshKeyFrameParticleEffectData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MeshKeyFrameParticleEffectData")),new UScriptStruct::TCppStructOps<FMeshKeyFrameParticleEffectData>);
	}
} ScriptStruct_MeshSwapper_StaticRegisterNativesFMeshKeyFrameParticleEffectData;
	struct Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PSTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PSTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SocketName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_SocketName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocationOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LocationOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotationOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RotationOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAutoDestroy_MetaData[];
#endif
		static void NewProp_bAutoDestroy_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAutoDestroy;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMeshKeyFrameParticleEffectData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_PSTemplate_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "The particle system to spawn for the notify state" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_PSTemplate = { "PSTemplate", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameParticleEffectData, PSTemplate), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_PSTemplate_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_PSTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_SocketName_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "The socket or bone to attach the system to" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_SocketName = { "SocketName", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameParticleEffectData, SocketName), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_SocketName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_SocketName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_LocationOffset_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Offset from the socket or bone to place the particle system" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_LocationOffset = { "LocationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameParticleEffectData, LocationOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_LocationOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_LocationOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_RotationOffset_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Rotation offset from the socket or bone for the particle system" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_RotationOffset = { "RotationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameParticleEffectData, RotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_RotationOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_RotationOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_bAutoDestroy_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "DisplayName", "Destroy Immediately" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Whether the particle system should be immediately destroyed at the end of the notify state or be allowed to finish" },
	};
#endif
	void Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_bAutoDestroy_SetBit(void* Obj)
	{
		((FMeshKeyFrameParticleEffectData*)Obj)->bAutoDestroy = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_bAutoDestroy = { "bAutoDestroy", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FMeshKeyFrameParticleEffectData), &Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_bAutoDestroy_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_bAutoDestroy_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_bAutoDestroy_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_PSTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_SocketName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_LocationOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_RotationOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::NewProp_bAutoDestroy,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MeshSwapper,
		nullptr,
		&NewStructOps,
		"MeshKeyFrameParticleEffectData",
		sizeof(FMeshKeyFrameParticleEffectData),
		alignof(FMeshKeyFrameParticleEffectData),
		Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MeshSwapper();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MeshKeyFrameParticleEffectData"), sizeof(FMeshKeyFrameParticleEffectData), Get_Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Hash() { return 2903734760U; }
class UScriptStruct* FMeshKeyFrameSoundEffectData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MESHSWAPPER_API uint32 Get_Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData, Z_Construct_UPackage__Script_MeshSwapper(), TEXT("MeshKeyFrameSoundEffectData"), sizeof(FMeshKeyFrameSoundEffectData), Get_Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Hash());
	}
	return Singleton;
}
template<> MESHSWAPPER_API UScriptStruct* StaticStruct<FMeshKeyFrameSoundEffectData>()
{
	return FMeshKeyFrameSoundEffectData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMeshKeyFrameSoundEffectData(FMeshKeyFrameSoundEffectData::StaticStruct, TEXT("/Script/MeshSwapper"), TEXT("MeshKeyFrameSoundEffectData"), false, nullptr, nullptr);
static struct FScriptStruct_MeshSwapper_StaticRegisterNativesFMeshKeyFrameSoundEffectData
{
	FScriptStruct_MeshSwapper_StaticRegisterNativesFMeshKeyFrameSoundEffectData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MeshKeyFrameSoundEffectData")),new UScriptStruct::TCppStructOps<FMeshKeyFrameSoundEffectData>);
	}
} ScriptStruct_MeshSwapper_StaticRegisterNativesFMeshKeyFrameSoundEffectData;
	struct Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VolumeMultiplier_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PitchMultiplier_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bFollow_MetaData[];
#endif
		static void NewProp_bFollow_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFollow;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_AttachName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMeshKeyFrameSoundEffectData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_Sound_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "Comment", "// Sound to Play\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Sound to Play" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameSoundEffectData, Sound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_Sound_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_Sound_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_VolumeMultiplier_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "Comment", "// Volume Multiplier\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Volume Multiplier" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameSoundEffectData, VolumeMultiplier), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_VolumeMultiplier_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_VolumeMultiplier_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_PitchMultiplier_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "Comment", "// Pitch Multiplier\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Pitch Multiplier" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameSoundEffectData, PitchMultiplier), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_PitchMultiplier_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_PitchMultiplier_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_bFollow_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "Comment", "// If this sound should follow its owner\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "If this sound should follow its owner" },
	};
#endif
	void Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_bFollow_SetBit(void* Obj)
	{
		((FMeshKeyFrameSoundEffectData*)Obj)->bFollow = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_bFollow = { "bFollow", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FMeshKeyFrameSoundEffectData), &Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_bFollow_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_bFollow_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_bFollow_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_AttachName_MetaData[] = {
		{ "Category", "MeshAnimNotify" },
		{ "Comment", "// Socket or bone name to attach sound to\n" },
		{ "EditCondition", "bFollow" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Socket or bone name to attach sound to" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_AttachName = { "AttachName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshKeyFrameSoundEffectData, AttachName), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_AttachName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_AttachName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_Sound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_VolumeMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_PitchMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_bFollow,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::NewProp_AttachName,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MeshSwapper,
		nullptr,
		&NewStructOps,
		"MeshKeyFrameSoundEffectData",
		sizeof(FMeshKeyFrameSoundEffectData),
		alignof(FMeshKeyFrameSoundEffectData),
		Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MeshSwapper();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MeshKeyFrameSoundEffectData"), sizeof(FMeshKeyFrameSoundEffectData), Get_Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Hash() { return 49007758U; }
class UScriptStruct* FKeyframeRelativeTransform::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MESHSWAPPER_API uint32 Get_Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FKeyframeRelativeTransform, Z_Construct_UPackage__Script_MeshSwapper(), TEXT("KeyframeRelativeTransform"), sizeof(FKeyframeRelativeTransform), Get_Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Hash());
	}
	return Singleton;
}
template<> MESHSWAPPER_API UScriptStruct* StaticStruct<FKeyframeRelativeTransform>()
{
	return FKeyframeRelativeTransform::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FKeyframeRelativeTransform(FKeyframeRelativeTransform::StaticStruct, TEXT("/Script/MeshSwapper"), TEXT("KeyframeRelativeTransform"), false, nullptr, nullptr);
static struct FScriptStruct_MeshSwapper_StaticRegisterNativesFKeyframeRelativeTransform
{
	FScriptStruct_MeshSwapper_StaticRegisterNativesFKeyframeRelativeTransform()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("KeyframeRelativeTransform")),new UScriptStruct::TCppStructOps<FKeyframeRelativeTransform>);
	}
} ScriptStruct_MeshSwapper_StaticRegisterNativesFKeyframeRelativeTransform;
	struct Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Scale;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FKeyframeRelativeTransform>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Location_MetaData[] = {
		{ "Category", "Mesh Keyframe" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FKeyframeRelativeTransform, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Rotation_MetaData[] = {
		{ "Category", "Mesh Keyframe" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FKeyframeRelativeTransform, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Rotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Rotation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Scale_MetaData[] = {
		{ "Category", "Mesh Keyframe" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FKeyframeRelativeTransform, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Scale_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Scale_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Rotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::NewProp_Scale,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MeshSwapper,
		nullptr,
		&NewStructOps,
		"KeyframeRelativeTransform",
		sizeof(FKeyframeRelativeTransform),
		alignof(FKeyframeRelativeTransform),
		Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FKeyframeRelativeTransform()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MeshSwapper();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("KeyframeRelativeTransform"), sizeof(FKeyframeRelativeTransform), Get_Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Hash() { return 3889155161U; }
	DEFINE_FUNCTION(UMeshSwapAnimation::execIsValidKeyFrameIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsValidKeyFrameIndex(Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapAnimation::execGetNumKeyFrames)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumKeyFrames();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapAnimation::execGetKeyFrameDataAtTime)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
		P_GET_STRUCT_REF(FMeshKeyFrameData,Z_Param_Out_OutKeyframeData);
		P_GET_UBOOL(Z_Param_bClampToEnds);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetKeyFrameDataAtTime(Z_Param_Time,Z_Param_Out_OutKeyframeData,Z_Param_bClampToEnds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapAnimation::execGetKeyFrameDataAtFrame)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_FrameIndex);
		P_GET_STRUCT_REF(FMeshKeyFrameData,Z_Param_Out_OutKeyframeData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetKeyFrameDataAtFrame(Z_Param_FrameIndex,Z_Param_Out_OutKeyframeData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapAnimation::execGetStaticMeshAtFrame)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_FrameIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UStaticMesh**)Z_Param__Result=P_THIS->GetStaticMeshAtFrame(Z_Param_FrameIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapAnimation::execGetStaticMeshAtTime)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
		P_GET_UBOOL(Z_Param_bClampToEnds);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UStaticMesh**)Z_Param__Result=P_THIS->GetStaticMeshAtTime(Z_Param_Time,Z_Param_bClampToEnds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapAnimation::execGetKeyFrameIndexAtTime)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
		P_GET_UBOOL(Z_Param_bClampToEnds);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetKeyFrameIndexAtTime(Z_Param_Time,Z_Param_bClampToEnds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapAnimation::execGetPositionAtKeyframeIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_KeyframeIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPositionAtKeyframeIndex(Z_Param_KeyframeIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapAnimation::execGetTotalDuration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetTotalDuration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapAnimation::execGetNumFrames)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumFrames();
		P_NATIVE_END;
	}
	void UMeshSwapAnimation::StaticRegisterNativesUMeshSwapAnimation()
	{
		UClass* Class = UMeshSwapAnimation::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetKeyFrameDataAtFrame", &UMeshSwapAnimation::execGetKeyFrameDataAtFrame },
			{ "GetKeyFrameDataAtTime", &UMeshSwapAnimation::execGetKeyFrameDataAtTime },
			{ "GetKeyFrameIndexAtTime", &UMeshSwapAnimation::execGetKeyFrameIndexAtTime },
			{ "GetNumFrames", &UMeshSwapAnimation::execGetNumFrames },
			{ "GetNumKeyFrames", &UMeshSwapAnimation::execGetNumKeyFrames },
			{ "GetPositionAtKeyframeIndex", &UMeshSwapAnimation::execGetPositionAtKeyframeIndex },
			{ "GetStaticMeshAtFrame", &UMeshSwapAnimation::execGetStaticMeshAtFrame },
			{ "GetStaticMeshAtTime", &UMeshSwapAnimation::execGetStaticMeshAtTime },
			{ "GetTotalDuration", &UMeshSwapAnimation::execGetTotalDuration },
			{ "IsValidKeyFrameIndex", &UMeshSwapAnimation::execIsValidKeyFrameIndex },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics
	{
		struct MeshSwapAnimation_eventGetKeyFrameDataAtFrame_Parms
		{
			int32 FrameIndex;
			FMeshKeyFrameData OutKeyframeData;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FrameIndex;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutKeyframeData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::NewProp_FrameIndex = { "FrameIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetKeyFrameDataAtFrame_Parms, FrameIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::NewProp_OutKeyframeData = { "OutKeyframeData", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetKeyFrameDataAtFrame_Parms, OutKeyframeData), Z_Construct_UScriptStruct_FMeshKeyFrameData, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MeshSwapAnimation_eventGetKeyFrameDataAtFrame_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapAnimation_eventGetKeyFrameDataAtFrame_Parms), &Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::NewProp_FrameIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::NewProp_OutKeyframeData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Returns the key data at the specified keyframe index\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Returns the key data at the specified keyframe index" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "GetKeyFrameDataAtFrame", nullptr, nullptr, sizeof(MeshSwapAnimation_eventGetKeyFrameDataAtFrame_Parms), Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics
	{
		struct MeshSwapAnimation_eventGetKeyFrameDataAtTime_Parms
		{
			float Time;
			FMeshKeyFrameData OutKeyframeData;
			bool bClampToEnds;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Time;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutKeyframeData;
		static void NewProp_bClampToEnds_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bClampToEnds;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetKeyFrameDataAtTime_Parms, Time), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_OutKeyframeData = { "OutKeyframeData", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetKeyFrameDataAtTime_Parms, OutKeyframeData), Z_Construct_UScriptStruct_FMeshKeyFrameData, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_bClampToEnds_SetBit(void* Obj)
	{
		((MeshSwapAnimation_eventGetKeyFrameDataAtTime_Parms*)Obj)->bClampToEnds = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_bClampToEnds = { "bClampToEnds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapAnimation_eventGetKeyFrameDataAtTime_Parms), &Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_bClampToEnds_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MeshSwapAnimation_eventGetKeyFrameDataAtTime_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapAnimation_eventGetKeyFrameDataAtTime_Parms), &Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_Time,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_OutKeyframeData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_bClampToEnds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Returns the key data at the specified time (in seconds),\n// When bClampToEnds is true, it will choose the first or last key if the time is out of range.\n" },
		{ "CPP_Default_bClampToEnds", "false" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Returns the key data at the specified time (in seconds),\nWhen bClampToEnds is true, it will choose the first or last key if the time is out of range." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "GetKeyFrameDataAtTime", nullptr, nullptr, sizeof(MeshSwapAnimation_eventGetKeyFrameDataAtTime_Parms), Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics
	{
		struct MeshSwapAnimation_eventGetKeyFrameIndexAtTime_Parms
		{
			float Time;
			bool bClampToEnds;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Time;
		static void NewProp_bClampToEnds_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bClampToEnds;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetKeyFrameIndexAtTime_Parms, Time), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::NewProp_bClampToEnds_SetBit(void* Obj)
	{
		((MeshSwapAnimation_eventGetKeyFrameIndexAtTime_Parms*)Obj)->bClampToEnds = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::NewProp_bClampToEnds = { "bClampToEnds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapAnimation_eventGetKeyFrameIndexAtTime_Parms), &Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::NewProp_bClampToEnds_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetKeyFrameIndexAtTime_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::NewProp_Time,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::NewProp_bClampToEnds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Returns the keyframe index that covers the specified time (in seconds), or INDEX_NONE if none exists.\n// When bClampToEnds is true, it will choose the first or last keyframe if the time is out of range.\n" },
		{ "CPP_Default_bClampToEnds", "false" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Returns the keyframe index that covers the specified time (in seconds), or INDEX_NONE if none exists.\nWhen bClampToEnds is true, it will choose the first or last keyframe if the time is out of range." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "GetKeyFrameIndexAtTime", nullptr, nullptr, sizeof(MeshSwapAnimation_eventGetKeyFrameIndexAtTime_Parms), Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics
	{
		struct MeshSwapAnimation_eventGetNumFrames_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetNumFrames_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Returns the total number of frames\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Returns the total number of frames" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "GetNumFrames", nullptr, nullptr, sizeof(MeshSwapAnimation_eventGetNumFrames_Parms), Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics
	{
		struct MeshSwapAnimation_eventGetNumKeyFrames_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetNumKeyFrames_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Returns the number of key frames\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Returns the number of key frames" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "GetNumKeyFrames", nullptr, nullptr, sizeof(MeshSwapAnimation_eventGetNumKeyFrames_Parms), Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics
	{
		struct MeshSwapAnimation_eventGetPositionAtKeyframeIndex_Parms
		{
			int32 KeyframeIndex;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_KeyframeIndex;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::NewProp_KeyframeIndex = { "KeyframeIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetPositionAtKeyframeIndex_Parms, KeyframeIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetPositionAtKeyframeIndex_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::NewProp_KeyframeIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "GetPositionAtKeyframeIndex", nullptr, nullptr, sizeof(MeshSwapAnimation_eventGetPositionAtKeyframeIndex_Parms), Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics
	{
		struct MeshSwapAnimation_eventGetStaticMeshAtFrame_Parms
		{
			int32 FrameIndex;
			UStaticMesh* ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FrameIndex;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::NewProp_FrameIndex = { "FrameIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetStaticMeshAtFrame_Parms, FrameIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetStaticMeshAtFrame_Parms, ReturnValue), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::NewProp_FrameIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Returns the key at the specified keyframe index, or nullptr if none exists\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Returns the key at the specified keyframe index, or nullptr if none exists" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "GetStaticMeshAtFrame", nullptr, nullptr, sizeof(MeshSwapAnimation_eventGetStaticMeshAtFrame_Parms), Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics
	{
		struct MeshSwapAnimation_eventGetStaticMeshAtTime_Parms
		{
			float Time;
			bool bClampToEnds;
			UStaticMesh* ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Time;
		static void NewProp_bClampToEnds_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bClampToEnds;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetStaticMeshAtTime_Parms, Time), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::NewProp_bClampToEnds_SetBit(void* Obj)
	{
		((MeshSwapAnimation_eventGetStaticMeshAtTime_Parms*)Obj)->bClampToEnds = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::NewProp_bClampToEnds = { "bClampToEnds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapAnimation_eventGetStaticMeshAtTime_Parms), &Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::NewProp_bClampToEnds_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetStaticMeshAtTime_Parms, ReturnValue), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::NewProp_Time,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::NewProp_bClampToEnds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Returns the key at the specified time (in seconds), or nullptr if none exists.\n// When bClampToEnds is true, it will choose the first or last key if the time is out of range.\n" },
		{ "CPP_Default_bClampToEnds", "false" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Returns the key at the specified time (in seconds), or nullptr if none exists.\nWhen bClampToEnds is true, it will choose the first or last key if the time is out of range." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "GetStaticMeshAtTime", nullptr, nullptr, sizeof(MeshSwapAnimation_eventGetStaticMeshAtTime_Parms), Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics
	{
		struct MeshSwapAnimation_eventGetTotalDuration_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventGetTotalDuration_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Returns the total duration in seconds\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Returns the total duration in seconds" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "GetTotalDuration", nullptr, nullptr, sizeof(MeshSwapAnimation_eventGetTotalDuration_Parms), Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics
	{
		struct MeshSwapAnimation_eventIsValidKeyFrameIndex_Parms
		{
			int32 Index;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapAnimation_eventIsValidKeyFrameIndex_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MeshSwapAnimation_eventIsValidKeyFrameIndex_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapAnimation_eventIsValidKeyFrameIndex_Parms), &Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Is the specified Index within the valid range of key frames?\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Is the specified Index within the valid range of key frames?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapAnimation, nullptr, "IsValidKeyFrameIndex", nullptr, nullptr, sizeof(MeshSwapAnimation_eventIsValidKeyFrameIndex_Parms), Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMeshSwapAnimation_NoRegister()
	{
		return UMeshSwapAnimation::StaticClass();
	}
	struct Z_Construct_UClass_UMeshSwapAnimation_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionSource_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CollisionSource;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FramesPerSecond_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FramesPerSecond;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OutAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OutAnimation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_KeyFrames_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_KeyFrames_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_KeyFrames;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InitialTransform;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMeshSwapAnimation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_MeshSwapper,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMeshSwapAnimation_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtFrame, "GetKeyFrameDataAtFrame" }, // 492332624
		{ &Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameDataAtTime, "GetKeyFrameDataAtTime" }, // 2353480865
		{ &Z_Construct_UFunction_UMeshSwapAnimation_GetKeyFrameIndexAtTime, "GetKeyFrameIndexAtTime" }, // 2632509581
		{ &Z_Construct_UFunction_UMeshSwapAnimation_GetNumFrames, "GetNumFrames" }, // 919593997
		{ &Z_Construct_UFunction_UMeshSwapAnimation_GetNumKeyFrames, "GetNumKeyFrames" }, // 3399839868
		{ &Z_Construct_UFunction_UMeshSwapAnimation_GetPositionAtKeyframeIndex, "GetPositionAtKeyframeIndex" }, // 3805127643
		{ &Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtFrame, "GetStaticMeshAtFrame" }, // 1161449615
		{ &Z_Construct_UFunction_UMeshSwapAnimation_GetStaticMeshAtTime, "GetStaticMeshAtTime" }, // 2368921500
		{ &Z_Construct_UFunction_UMeshSwapAnimation_GetTotalDuration, "GetTotalDuration" }, // 3697961274
		{ &Z_Construct_UFunction_UMeshSwapAnimation_IsValidKeyFrameIndex, "IsValidKeyFrameIndex" }, // 3390218282
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimation_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Contains an animation sequence of static mesh frames\n */" },
		{ "DisplayThumbnail", "true" },
		{ "IncludePath", "MeshSwapAnimation.h" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Contains an animation sequence of static mesh frames" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_CollisionSource_MetaData[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// Collision source\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "Collision source" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_CollisionSource = { "CollisionSource", nullptr, (EPropertyFlags)0x0020080000000015, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapAnimation, CollisionSource), Z_Construct_UEnum_MeshSwapper_EMeshAnimCollisionMode, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_CollisionSource_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_CollisionSource_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_FramesPerSecond_MetaData[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "ClampMax", "1000" },
		{ "ClampMin", "0" },
		{ "Comment", "// The nominal frame rate to play this animation clip back at\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "The nominal frame rate to play this animation clip back at" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_FramesPerSecond = { "FramesPerSecond", nullptr, (EPropertyFlags)0x0020080000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapAnimation, FramesPerSecond), METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_FramesPerSecond_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_FramesPerSecond_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_OutAnimation_MetaData[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_OutAnimation = { "OutAnimation", nullptr, (EPropertyFlags)0x0020080000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapAnimation, OutAnimation), Z_Construct_UClass_UMeshSwapAnimation_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_OutAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_OutAnimation_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_KeyFrames_Inner = { "KeyFrames", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FMeshKeyFrameData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_KeyFrames_MetaData[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "// The set of key frames for this animation clip\n" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
		{ "ToolTip", "The set of key frames for this animation clip" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_KeyFrames = { "KeyFrames", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapAnimation, KeyFrames), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_KeyFrames_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_KeyFrames_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_InitialTransform_MetaData[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "ModuleRelativePath", "Public/MeshSwapAnimation.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_InitialTransform = { "InitialTransform", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapAnimation, InitialTransform), Z_Construct_UScriptStruct_FKeyframeRelativeTransform, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_InitialTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_InitialTransform_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMeshSwapAnimation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_CollisionSource,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_FramesPerSecond,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_OutAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_KeyFrames_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_KeyFrames,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapAnimation_Statics::NewProp_InitialTransform,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMeshSwapAnimation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMeshSwapAnimation>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMeshSwapAnimation_Statics::ClassParams = {
		&UMeshSwapAnimation::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMeshSwapAnimation_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimation_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMeshSwapAnimation_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapAnimation_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMeshSwapAnimation()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMeshSwapAnimation_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMeshSwapAnimation, 1661476036);
	template<> MESHSWAPPER_API UClass* StaticClass<UMeshSwapAnimation>()
	{
		return UMeshSwapAnimation::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMeshSwapAnimation(Z_Construct_UClass_UMeshSwapAnimation, &UMeshSwapAnimation::StaticClass, TEXT("/Script/MeshSwapper"), TEXT("UMeshSwapAnimation"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMeshSwapAnimation);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
