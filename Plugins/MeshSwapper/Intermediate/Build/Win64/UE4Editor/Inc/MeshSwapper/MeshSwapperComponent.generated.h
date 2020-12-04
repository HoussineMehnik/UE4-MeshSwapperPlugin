// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMeshSwapAnimation;
#ifdef MESHSWAPPER_MeshSwapperComponent_generated_h
#error "MeshSwapperComponent.generated.h already included, missing '#pragma once' in MeshSwapperComponent.h"
#endif
#define MESHSWAPPER_MeshSwapperComponent_generated_h

#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_25_DELEGATE \
struct _Script_MeshSwapper_eventKeyframeNotifyEvent_Parms \
{ \
	FString NotifyTag; \
	int32 FrameIndex; \
}; \
static inline void FKeyframeNotifyEvent_DelegateWrapper(const FMulticastScriptDelegate& KeyframeNotifyEvent, const FString& NotifyTag, int32 FrameIndex) \
{ \
	_Script_MeshSwapper_eventKeyframeNotifyEvent_Parms Parms; \
	Parms.NotifyTag=NotifyTag; \
	Parms.FrameIndex=FrameIndex; \
	KeyframeNotifyEvent.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_22_DELEGATE \
static inline void FAnimationFinishedPlaySignature_DelegateWrapper(const FMulticastScriptDelegate& AnimationFinishedPlaySignature) \
{ \
	AnimationFinishedPlaySignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_SPARSE_DATA
#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnRep_SourceAnimation); \
	DECLARE_FUNCTION(execGetAnimationFramerate); \
	DECLARE_FUNCTION(execGetAnimationLengthInFrames); \
	DECLARE_FUNCTION(execGetAnimationLength); \
	DECLARE_FUNCTION(execSetNewTime); \
	DECLARE_FUNCTION(execGetPlayRate); \
	DECLARE_FUNCTION(execSetPlayRate); \
	DECLARE_FUNCTION(execIsLooping); \
	DECLARE_FUNCTION(execSetLooping); \
	DECLARE_FUNCTION(execGetPlaybackPosition); \
	DECLARE_FUNCTION(execSetPlaybackPosition); \
	DECLARE_FUNCTION(execGetPlaybackPositionInFrames); \
	DECLARE_FUNCTION(execSetPlaybackPositionInFrames); \
	DECLARE_FUNCTION(execIsReversing); \
	DECLARE_FUNCTION(execIsPlaying); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execReverseFromEnd); \
	DECLARE_FUNCTION(execReverse); \
	DECLARE_FUNCTION(execPlayFromStart); \
	DECLARE_FUNCTION(execPlay); \
	DECLARE_FUNCTION(execGetAnimation); \
	DECLARE_FUNCTION(execSetAnimation);


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRep_SourceAnimation); \
	DECLARE_FUNCTION(execGetAnimationFramerate); \
	DECLARE_FUNCTION(execGetAnimationLengthInFrames); \
	DECLARE_FUNCTION(execGetAnimationLength); \
	DECLARE_FUNCTION(execSetNewTime); \
	DECLARE_FUNCTION(execGetPlayRate); \
	DECLARE_FUNCTION(execSetPlayRate); \
	DECLARE_FUNCTION(execIsLooping); \
	DECLARE_FUNCTION(execSetLooping); \
	DECLARE_FUNCTION(execGetPlaybackPosition); \
	DECLARE_FUNCTION(execSetPlaybackPosition); \
	DECLARE_FUNCTION(execGetPlaybackPositionInFrames); \
	DECLARE_FUNCTION(execSetPlaybackPositionInFrames); \
	DECLARE_FUNCTION(execIsReversing); \
	DECLARE_FUNCTION(execIsPlaying); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execReverseFromEnd); \
	DECLARE_FUNCTION(execReverse); \
	DECLARE_FUNCTION(execPlayFromStart); \
	DECLARE_FUNCTION(execPlay); \
	DECLARE_FUNCTION(execGetAnimation); \
	DECLARE_FUNCTION(execSetAnimation);


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMeshSwapperComponent(); \
	friend struct Z_Construct_UClass_UMeshSwapperComponent_Statics; \
public: \
	DECLARE_CLASS(UMeshSwapperComponent, UStaticMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MeshSwapper"), NO_API) \
	DECLARE_SERIALIZER(UMeshSwapperComponent) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		SourceAnimation=NETFIELD_REP_START, \
		PlayRate, \
		bLooping, \
		bReversePlayback, \
		bPlaying, \
		AccumulatedTime, \
		NETFIELD_REP_END=AccumulatedTime	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_INCLASS \
private: \
	static void StaticRegisterNativesUMeshSwapperComponent(); \
	friend struct Z_Construct_UClass_UMeshSwapperComponent_Statics; \
public: \
	DECLARE_CLASS(UMeshSwapperComponent, UStaticMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MeshSwapper"), NO_API) \
	DECLARE_SERIALIZER(UMeshSwapperComponent) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		SourceAnimation=NETFIELD_REP_START, \
		PlayRate, \
		bLooping, \
		bReversePlayback, \
		bPlaying, \
		AccumulatedTime, \
		NETFIELD_REP_END=AccumulatedTime	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMeshSwapperComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMeshSwapperComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMeshSwapperComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMeshSwapperComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMeshSwapperComponent(UMeshSwapperComponent&&); \
	NO_API UMeshSwapperComponent(const UMeshSwapperComponent&); \
public:


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMeshSwapperComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMeshSwapperComponent(UMeshSwapperComponent&&); \
	NO_API UMeshSwapperComponent(const UMeshSwapperComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMeshSwapperComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMeshSwapperComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMeshSwapperComponent)


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SourceAnimation() { return STRUCT_OFFSET(UMeshSwapperComponent, SourceAnimation); } \
	FORCEINLINE static uint32 __PPO__PlayRate() { return STRUCT_OFFSET(UMeshSwapperComponent, PlayRate); } \
	FORCEINLINE static uint32 __PPO__AccumulatedTime() { return STRUCT_OFFSET(UMeshSwapperComponent, AccumulatedTime); } \
	FORCEINLINE static uint32 __PPO__CachedFrameIndex() { return STRUCT_OFFSET(UMeshSwapperComponent, CachedFrameIndex); } \
	FORCEINLINE static uint32 __PPO__CachedBodySetup() { return STRUCT_OFFSET(UMeshSwapperComponent, CachedBodySetup); }


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_28_PROLOG
#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_PRIVATE_PROPERTY_OFFSET \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_SPARSE_DATA \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_RPC_WRAPPERS \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_INCLASS \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_PRIVATE_PROPERTY_OFFSET \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_SPARSE_DATA \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_INCLASS_NO_PURE_DECLS \
	Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h_31_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class MeshSwapperComponent."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MESHSWAPPER_API UClass* StaticClass<class UMeshSwapperComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Mesh_Swapper_4_26_Plugins_MeshSwapper_Source_MeshSwapper_Public_MeshSwapperComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
