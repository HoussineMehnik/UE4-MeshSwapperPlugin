// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FMeshKeyFrameData;
class UStaticMesh;
#ifdef MESHSWAPPER_MeshSwapAnimation_generated_h
#error "MeshSwapAnimation.generated.h already included, missing '#pragma once' in MeshSwapAnimation.h"
#endif
#define MESHSWAPPER_MeshSwapAnimation_generated_h

#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_138_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMeshKeyFrameData_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MESHSWAPPER_API UScriptStruct* StaticStruct<struct FMeshKeyFrameData>();

#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_96_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMeshKeyFrameParticleEffectData_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MESHSWAPPER_API UScriptStruct* StaticStruct<struct FMeshKeyFrameParticleEffectData>();

#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_57_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMeshKeyFrameSoundEffectData_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MESHSWAPPER_API UScriptStruct* StaticStruct<struct FMeshKeyFrameSoundEffectData>();

#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_19_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FKeyframeRelativeTransform_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MESHSWAPPER_API UScriptStruct* StaticStruct<struct FKeyframeRelativeTransform>();

#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_SPARSE_DATA
#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsValidKeyFrameIndex); \
	DECLARE_FUNCTION(execGetNumKeyFrames); \
	DECLARE_FUNCTION(execGetKeyFrameDataAtTime); \
	DECLARE_FUNCTION(execGetKeyFrameDataAtFrame); \
	DECLARE_FUNCTION(execGetStaticMeshAtFrame); \
	DECLARE_FUNCTION(execGetStaticMeshAtTime); \
	DECLARE_FUNCTION(execGetKeyFrameIndexAtTime); \
	DECLARE_FUNCTION(execGetPositionAtKeyframeIndex); \
	DECLARE_FUNCTION(execGetTotalDuration); \
	DECLARE_FUNCTION(execGetNumFrames);


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsValidKeyFrameIndex); \
	DECLARE_FUNCTION(execGetNumKeyFrames); \
	DECLARE_FUNCTION(execGetKeyFrameDataAtTime); \
	DECLARE_FUNCTION(execGetKeyFrameDataAtFrame); \
	DECLARE_FUNCTION(execGetStaticMeshAtFrame); \
	DECLARE_FUNCTION(execGetStaticMeshAtTime); \
	DECLARE_FUNCTION(execGetKeyFrameIndexAtTime); \
	DECLARE_FUNCTION(execGetPositionAtKeyframeIndex); \
	DECLARE_FUNCTION(execGetTotalDuration); \
	DECLARE_FUNCTION(execGetNumFrames);


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMeshSwapAnimation(); \
	friend struct Z_Construct_UClass_UMeshSwapAnimation_Statics; \
public: \
	DECLARE_CLASS(UMeshSwapAnimation, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MeshSwapper"), NO_API) \
	DECLARE_SERIALIZER(UMeshSwapAnimation)


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_INCLASS \
private: \
	static void StaticRegisterNativesUMeshSwapAnimation(); \
	friend struct Z_Construct_UClass_UMeshSwapAnimation_Statics; \
public: \
	DECLARE_CLASS(UMeshSwapAnimation, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MeshSwapper"), NO_API) \
	DECLARE_SERIALIZER(UMeshSwapAnimation)


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMeshSwapAnimation(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMeshSwapAnimation) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMeshSwapAnimation); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMeshSwapAnimation); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMeshSwapAnimation(UMeshSwapAnimation&&); \
	NO_API UMeshSwapAnimation(const UMeshSwapAnimation&); \
public:


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMeshSwapAnimation(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMeshSwapAnimation(UMeshSwapAnimation&&); \
	NO_API UMeshSwapAnimation(const UMeshSwapAnimation&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMeshSwapAnimation); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMeshSwapAnimation); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMeshSwapAnimation)


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionSource() { return STRUCT_OFFSET(UMeshSwapAnimation, CollisionSource); } \
	FORCEINLINE static uint32 __PPO__FramesPerSecond() { return STRUCT_OFFSET(UMeshSwapAnimation, FramesPerSecond); } \
	FORCEINLINE static uint32 __PPO__OutAnimation() { return STRUCT_OFFSET(UMeshSwapAnimation, OutAnimation); } \
	FORCEINLINE static uint32 __PPO__KeyFrames() { return STRUCT_OFFSET(UMeshSwapAnimation, KeyFrames); }


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_199_PROLOG
#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_PRIVATE_PROPERTY_OFFSET \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_SPARSE_DATA \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_RPC_WRAPPERS \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_INCLASS \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_PRIVATE_PROPERTY_OFFSET \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_SPARSE_DATA \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_RPC_WRAPPERS_NO_PURE_DECLS \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_INCLASS_NO_PURE_DECLS \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h_202_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class MeshSwapAnimation."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MESHSWAPPER_API UClass* StaticClass<class UMeshSwapAnimation>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapAnimation_h


#define FOREACH_ENUM_EMESHANIMCOLLISIONMODE(op) \
	op(EMeshAnimCollisionMode::NoCollision) \
	op(EMeshAnimCollisionMode::FirstFrameCollision) \
	op(EMeshAnimCollisionMode::EachFrameCollision) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
