// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MeshSwapper/Public/MeshSwapperComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMeshSwapperComponent() {}
// Cross Module References
	MESHSWAPPER_API UFunction* Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_MeshSwapper();
	MESHSWAPPER_API UFunction* Z_Construct_UDelegateFunction_MeshSwapper_AnimationFinishedPlaySignature__DelegateSignature();
	MESHSWAPPER_API UClass* Z_Construct_UClass_UMeshSwapperComponent_NoRegister();
	MESHSWAPPER_API UClass* Z_Construct_UClass_UMeshSwapperComponent();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent();
	MESHSWAPPER_API UClass* Z_Construct_UClass_UMeshSwapAnimation_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBodySetup_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics
	{
		struct _Script_MeshSwapper_eventKeyframeNotifyEvent_Parms
		{
			FString NotifyTag;
			int32 FrameIndex;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NotifyTag;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FrameIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::NewProp_NotifyTag = { "NotifyTag", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_MeshSwapper_eventKeyframeNotifyEvent_Parms, NotifyTag), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::NewProp_FrameIndex = { "FrameIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_MeshSwapper_eventKeyframeNotifyEvent_Parms, FrameIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::NewProp_NotifyTag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::NewProp_FrameIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/* Keyframe Notify Event Delegate  */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Keyframe Notify Event Delegate" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MeshSwapper, nullptr, "KeyframeNotifyEvent__DelegateSignature", nullptr, nullptr, sizeof(_Script_MeshSwapper_eventKeyframeNotifyEvent_Parms), Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_MeshSwapper_AnimationFinishedPlaySignature__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MeshSwapper_AnimationFinishedPlaySignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Event for a non-looping animation finishing play\n" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Event for a non-looping animation finishing play" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MeshSwapper_AnimationFinishedPlaySignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MeshSwapper, nullptr, "AnimationFinishedPlaySignature__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MeshSwapper_AnimationFinishedPlaySignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MeshSwapper_AnimationFinishedPlaySignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MeshSwapper_AnimationFinishedPlaySignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_MeshSwapper_AnimationFinishedPlaySignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execOnRep_SourceAnimation)
	{
		P_GET_OBJECT(UMeshSwapAnimation,Z_Param_OldAnimation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_SourceAnimation(Z_Param_OldAnimation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execGetAnimationFramerate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetAnimationFramerate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execGetAnimationLengthInFrames)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetAnimationLengthInFrames();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execGetAnimationLength)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetAnimationLength();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execSetNewTime)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewTime);
		P_GET_UBOOL(Z_Param_bFireEvents);
		P_GET_UBOOL(Z_Param_bSpawnParticles);
		P_GET_UBOOL(Z_Param_bPlaySounds);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetNewTime(Z_Param_NewTime,Z_Param_bFireEvents,Z_Param_bSpawnParticles,Z_Param_bPlaySounds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execGetPlayRate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPlayRate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execSetPlayRate)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewRate);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPlayRate(Z_Param_NewRate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execIsLooping)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsLooping();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execSetLooping)
	{
		P_GET_UBOOL(Z_Param_bNewLooping);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLooping(Z_Param_bNewLooping);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execGetPlaybackPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPlaybackPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execSetPlaybackPosition)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewPosition);
		P_GET_UBOOL(Z_Param_bFireEvents);
		P_GET_UBOOL(Z_Param_bSpawnParticles);
		P_GET_UBOOL(Z_Param_bPlaySounds);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPlaybackPosition(Z_Param_NewPosition,Z_Param_bFireEvents,Z_Param_bSpawnParticles,Z_Param_bPlaySounds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execGetPlaybackPositionInFrames)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetPlaybackPositionInFrames();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execSetPlaybackPositionInFrames)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NewFramePosition);
		P_GET_UBOOL(Z_Param_bFireEvents);
		P_GET_UBOOL(Z_Param_bSpawnParticles);
		P_GET_UBOOL(Z_Param_bPlaySounds);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPlaybackPositionInFrames(Z_Param_NewFramePosition,Z_Param_bFireEvents,Z_Param_bSpawnParticles,Z_Param_bPlaySounds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execIsReversing)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsReversing();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execIsPlaying)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsPlaying();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execReverseFromEnd)
	{
		P_GET_UBOOL(Z_Param_bFireEvents);
		P_GET_UBOOL(Z_Param_bSpawnParticles);
		P_GET_UBOOL(Z_Param_bPlaySounds);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReverseFromEnd(Z_Param_bFireEvents,Z_Param_bSpawnParticles,Z_Param_bPlaySounds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execReverse)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Reverse();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execPlayFromStart)
	{
		P_GET_UBOOL(Z_Param_bFireEvents);
		P_GET_UBOOL(Z_Param_bSpawnParticles);
		P_GET_UBOOL(Z_Param_bPlaySounds);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlayFromStart(Z_Param_bFireEvents,Z_Param_bSpawnParticles,Z_Param_bPlaySounds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execPlay)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Play();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execGetAnimation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UMeshSwapAnimation**)Z_Param__Result=P_THIS->GetAnimation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshSwapperComponent::execSetAnimation)
	{
		P_GET_OBJECT(UMeshSwapAnimation,Z_Param_NewAnimation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetAnimation(Z_Param_NewAnimation);
		P_NATIVE_END;
	}
	void UMeshSwapperComponent::StaticRegisterNativesUMeshSwapperComponent()
	{
		UClass* Class = UMeshSwapperComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAnimation", &UMeshSwapperComponent::execGetAnimation },
			{ "GetAnimationFramerate", &UMeshSwapperComponent::execGetAnimationFramerate },
			{ "GetAnimationLength", &UMeshSwapperComponent::execGetAnimationLength },
			{ "GetAnimationLengthInFrames", &UMeshSwapperComponent::execGetAnimationLengthInFrames },
			{ "GetPlaybackPosition", &UMeshSwapperComponent::execGetPlaybackPosition },
			{ "GetPlaybackPositionInFrames", &UMeshSwapperComponent::execGetPlaybackPositionInFrames },
			{ "GetPlayRate", &UMeshSwapperComponent::execGetPlayRate },
			{ "IsLooping", &UMeshSwapperComponent::execIsLooping },
			{ "IsPlaying", &UMeshSwapperComponent::execIsPlaying },
			{ "IsReversing", &UMeshSwapperComponent::execIsReversing },
			{ "OnRep_SourceAnimation", &UMeshSwapperComponent::execOnRep_SourceAnimation },
			{ "Play", &UMeshSwapperComponent::execPlay },
			{ "PlayFromStart", &UMeshSwapperComponent::execPlayFromStart },
			{ "Reverse", &UMeshSwapperComponent::execReverse },
			{ "ReverseFromEnd", &UMeshSwapperComponent::execReverseFromEnd },
			{ "SetAnimation", &UMeshSwapperComponent::execSetAnimation },
			{ "SetLooping", &UMeshSwapperComponent::execSetLooping },
			{ "SetNewTime", &UMeshSwapperComponent::execSetNewTime },
			{ "SetPlaybackPosition", &UMeshSwapperComponent::execSetPlaybackPosition },
			{ "SetPlaybackPositionInFrames", &UMeshSwapperComponent::execSetPlaybackPositionInFrames },
			{ "SetPlayRate", &UMeshSwapperComponent::execSetPlayRate },
			{ "Stop", &UMeshSwapperComponent::execStop },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics
	{
		struct MeshSwapperComponent_eventGetAnimation_Parms
		{
			UMeshSwapAnimation* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventGetAnimation_Parms, ReturnValue), Z_Construct_UClass_UMeshSwapAnimation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "/** Gets the Animation used by this instance. */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Gets the Animation used by this instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "GetAnimation", nullptr, nullptr, sizeof(MeshSwapperComponent_eventGetAnimation_Parms), Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics
	{
		struct MeshSwapperComponent_eventGetAnimationFramerate_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventGetAnimationFramerate_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Get the nominal framerate that the Animation will be played back at (ignoring PlayRate), in frames per second */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Get the nominal framerate that the Animation will be played back at (ignoring PlayRate), in frames per second" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "GetAnimationFramerate", nullptr, nullptr, sizeof(MeshSwapperComponent_eventGetAnimationFramerate_Parms), Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics
	{
		struct MeshSwapperComponent_eventGetAnimationLength_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventGetAnimationLength_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Get length of the Animation (in seconds) */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Get length of the Animation (in seconds)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "GetAnimationLength", nullptr, nullptr, sizeof(MeshSwapperComponent_eventGetAnimationLength_Parms), Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics
	{
		struct MeshSwapperComponent_eventGetAnimationLengthInFrames_Parms
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
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventGetAnimationLengthInFrames_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Get length of the Animation (in frames) */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Get length of the Animation (in frames)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "GetAnimationLengthInFrames", nullptr, nullptr, sizeof(MeshSwapperComponent_eventGetAnimationLengthInFrames_Parms), Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics
	{
		struct MeshSwapperComponent_eventGetPlaybackPosition_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventGetPlaybackPosition_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Get the current playback position (in seconds) of the Animation */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Get the current playback position (in seconds) of the Animation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "GetPlaybackPosition", nullptr, nullptr, sizeof(MeshSwapperComponent_eventGetPlaybackPosition_Parms), Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics
	{
		struct MeshSwapperComponent_eventGetPlaybackPositionInFrames_Parms
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
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventGetPlaybackPositionInFrames_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Get the current playback position (in frames) of the Animation */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Get the current playback position (in frames) of the Animation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "GetPlaybackPositionInFrames", nullptr, nullptr, sizeof(MeshSwapperComponent_eventGetPlaybackPositionInFrames_Parms), Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics
	{
		struct MeshSwapperComponent_eventGetPlayRate_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventGetPlayRate_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Get the current play rate for this Animation */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Get the current play rate for this Animation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "GetPlayRate", nullptr, nullptr, sizeof(MeshSwapperComponent_eventGetPlayRate_Parms), Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics
	{
		struct MeshSwapperComponent_eventIsLooping_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventIsLooping_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventIsLooping_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Get whether we are looping or not */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Get whether we are looping or not" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "IsLooping", nullptr, nullptr, sizeof(MeshSwapperComponent_eventIsLooping_Parms), Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_IsLooping()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_IsLooping_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics
	{
		struct MeshSwapperComponent_eventIsPlaying_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventIsPlaying_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventIsPlaying_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Get whether this Animation is playing or not. */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Get whether this Animation is playing or not." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "IsPlaying", nullptr, nullptr, sizeof(MeshSwapperComponent_eventIsPlaying_Parms), Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics
	{
		struct MeshSwapperComponent_eventIsReversing_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventIsReversing_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventIsReversing_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Get whether we are reversing or not */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Get whether we are reversing or not" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "IsReversing", nullptr, nullptr, sizeof(MeshSwapperComponent_eventIsReversing_Parms), Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_IsReversing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_IsReversing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics
	{
		struct MeshSwapperComponent_eventOnRep_SourceAnimation_Parms
		{
			UMeshSwapAnimation* OldAnimation;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OldAnimation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::NewProp_OldAnimation = { "OldAnimation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventOnRep_SourceAnimation_Parms, OldAnimation), Z_Construct_UClass_UMeshSwapAnimation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::NewProp_OldAnimation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "OnRep_SourceAnimation", nullptr, nullptr, sizeof(MeshSwapperComponent_eventOnRep_SourceAnimation_Parms), Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_Play_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_Play_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Start playback of Animation */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Start playback of Animation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_Play_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "Play", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_Play_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_Play_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_Play()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_Play_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics
	{
		struct MeshSwapperComponent_eventPlayFromStart_Parms
		{
			bool bFireEvents;
			bool bSpawnParticles;
			bool bPlaySounds;
		};
		static void NewProp_bFireEvents_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFireEvents;
		static void NewProp_bSpawnParticles_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSpawnParticles;
		static void NewProp_bPlaySounds_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPlaySounds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bFireEvents_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventPlayFromStart_Parms*)Obj)->bFireEvents = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bFireEvents = { "bFireEvents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventPlayFromStart_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bFireEvents_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bSpawnParticles_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventPlayFromStart_Parms*)Obj)->bSpawnParticles = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bSpawnParticles = { "bSpawnParticles", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventPlayFromStart_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bSpawnParticles_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bPlaySounds_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventPlayFromStart_Parms*)Obj)->bPlaySounds = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bPlaySounds = { "bPlaySounds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventPlayFromStart_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bPlaySounds_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bFireEvents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bSpawnParticles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::NewProp_bPlaySounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Start playback of Animation from the start */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Start playback of Animation from the start" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "PlayFromStart", nullptr, nullptr, sizeof(MeshSwapperComponent_eventPlayFromStart_Parms), Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_Reverse_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_Reverse_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Start playback of Animation in reverse */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Start playback of Animation in reverse" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_Reverse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "Reverse", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_Reverse_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_Reverse_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_Reverse()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_Reverse_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics
	{
		struct MeshSwapperComponent_eventReverseFromEnd_Parms
		{
			bool bFireEvents;
			bool bSpawnParticles;
			bool bPlaySounds;
		};
		static void NewProp_bFireEvents_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFireEvents;
		static void NewProp_bSpawnParticles_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSpawnParticles;
		static void NewProp_bPlaySounds_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPlaySounds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bFireEvents_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventReverseFromEnd_Parms*)Obj)->bFireEvents = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bFireEvents = { "bFireEvents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventReverseFromEnd_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bFireEvents_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bSpawnParticles_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventReverseFromEnd_Parms*)Obj)->bSpawnParticles = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bSpawnParticles = { "bSpawnParticles", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventReverseFromEnd_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bSpawnParticles_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bPlaySounds_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventReverseFromEnd_Parms*)Obj)->bPlaySounds = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bPlaySounds = { "bPlaySounds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventReverseFromEnd_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bPlaySounds_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bFireEvents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bSpawnParticles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::NewProp_bPlaySounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Start playback of Animation in reverse from the end */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Start playback of Animation in reverse from the end" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "ReverseFromEnd", nullptr, nullptr, sizeof(MeshSwapperComponent_eventReverseFromEnd_Parms), Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics
	{
		struct MeshSwapperComponent_eventSetAnimation_Parms
		{
			UMeshSwapAnimation* NewAnimation;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewAnimation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::NewProp_NewAnimation = { "NewAnimation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventSetAnimation_Parms, NewAnimation), Z_Construct_UClass_UMeshSwapAnimation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetAnimation_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetAnimation_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::NewProp_NewAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "/** Change the Animation used by this instance (will reset the play time to 0 if it is a new Animation). */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Change the Animation used by this instance (will reset the play time to 0 if it is a new Animation)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "SetAnimation", nullptr, nullptr, sizeof(MeshSwapperComponent_eventSetAnimation_Parms), Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics
	{
		struct MeshSwapperComponent_eventSetLooping_Parms
		{
			bool bNewLooping;
		};
		static void NewProp_bNewLooping_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNewLooping;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::NewProp_bNewLooping_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetLooping_Parms*)Obj)->bNewLooping = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::NewProp_bNewLooping = { "bNewLooping", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetLooping_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::NewProp_bNewLooping_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::NewProp_bNewLooping,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** true means we should loop, false means we should not. */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "true means we should loop, false means we should not." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "SetLooping", nullptr, nullptr, sizeof(MeshSwapperComponent_eventSetLooping_Parms), Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_SetLooping()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_SetLooping_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics
	{
		struct MeshSwapperComponent_eventSetNewTime_Parms
		{
			float NewTime;
			bool bFireEvents;
			bool bSpawnParticles;
			bool bPlaySounds;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewTime;
		static void NewProp_bFireEvents_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFireEvents;
		static void NewProp_bSpawnParticles_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSpawnParticles;
		static void NewProp_bPlaySounds_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPlaySounds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_NewTime = { "NewTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventSetNewTime_Parms, NewTime), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bFireEvents_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetNewTime_Parms*)Obj)->bFireEvents = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bFireEvents = { "bFireEvents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetNewTime_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bFireEvents_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bSpawnParticles_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetNewTime_Parms*)Obj)->bSpawnParticles = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bSpawnParticles = { "bSpawnParticles", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetNewTime_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bSpawnParticles_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bPlaySounds_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetNewTime_Parms*)Obj)->bPlaySounds = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bPlaySounds = { "bPlaySounds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetNewTime_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bPlaySounds_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_NewTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bFireEvents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bSpawnParticles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::NewProp_bPlaySounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Set the new playback position time to use */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Set the new playback position time to use" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "SetNewTime", nullptr, nullptr, sizeof(MeshSwapperComponent_eventSetNewTime_Parms), Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics
	{
		struct MeshSwapperComponent_eventSetPlaybackPosition_Parms
		{
			float NewPosition;
			bool bFireEvents;
			bool bSpawnParticles;
			bool bPlaySounds;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewPosition;
		static void NewProp_bFireEvents_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFireEvents;
		static void NewProp_bSpawnParticles_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSpawnParticles;
		static void NewProp_bPlaySounds_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPlaySounds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_NewPosition = { "NewPosition", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventSetPlaybackPosition_Parms, NewPosition), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bFireEvents_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetPlaybackPosition_Parms*)Obj)->bFireEvents = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bFireEvents = { "bFireEvents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetPlaybackPosition_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bFireEvents_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bSpawnParticles_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetPlaybackPosition_Parms*)Obj)->bSpawnParticles = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bSpawnParticles = { "bSpawnParticles", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetPlaybackPosition_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bSpawnParticles_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bPlaySounds_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetPlaybackPosition_Parms*)Obj)->bPlaySounds = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bPlaySounds = { "bPlaySounds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetPlaybackPosition_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bPlaySounds_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_NewPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bFireEvents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bSpawnParticles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::NewProp_bPlaySounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Jump to a position in the Animation (expressed in seconds). */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Jump to a position in the Animation (expressed in seconds)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "SetPlaybackPosition", nullptr, nullptr, sizeof(MeshSwapperComponent_eventSetPlaybackPosition_Parms), Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics
	{
		struct MeshSwapperComponent_eventSetPlaybackPositionInFrames_Parms
		{
			int32 NewFramePosition;
			bool bFireEvents;
			bool bSpawnParticles;
			bool bPlaySounds;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NewFramePosition;
		static void NewProp_bFireEvents_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFireEvents;
		static void NewProp_bSpawnParticles_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSpawnParticles;
		static void NewProp_bPlaySounds_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPlaySounds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_NewFramePosition = { "NewFramePosition", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventSetPlaybackPositionInFrames_Parms, NewFramePosition), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bFireEvents_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetPlaybackPositionInFrames_Parms*)Obj)->bFireEvents = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bFireEvents = { "bFireEvents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetPlaybackPositionInFrames_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bFireEvents_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bSpawnParticles_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetPlaybackPositionInFrames_Parms*)Obj)->bSpawnParticles = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bSpawnParticles = { "bSpawnParticles", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetPlaybackPositionInFrames_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bSpawnParticles_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bPlaySounds_SetBit(void* Obj)
	{
		((MeshSwapperComponent_eventSetPlaybackPositionInFrames_Parms*)Obj)->bPlaySounds = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bPlaySounds = { "bPlaySounds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshSwapperComponent_eventSetPlaybackPositionInFrames_Parms), &Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bPlaySounds_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_NewFramePosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bFireEvents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bSpawnParticles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::NewProp_bPlaySounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Jump to a position in the Animation (expressed in frames). */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Jump to a position in the Animation (expressed in frames)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "SetPlaybackPositionInFrames", nullptr, nullptr, sizeof(MeshSwapperComponent_eventSetPlaybackPositionInFrames_Parms), Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics
	{
		struct MeshSwapperComponent_eventSetPlayRate_Parms
		{
			float NewRate;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewRate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::NewProp_NewRate = { "NewRate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshSwapperComponent_eventSetPlayRate_Parms, NewRate), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::NewProp_NewRate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Sets the new play rate for this Animation */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Sets the new play rate for this Animation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "SetPlayRate", nullptr, nullptr, sizeof(MeshSwapperComponent_eventSetPlayRate_Parms), Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshSwapperComponent_Stop_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshSwapperComponent_Stop_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|MeshSwapAnimation" },
		{ "Comment", "/** Stop playback of Animation */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Stop playback of Animation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshSwapperComponent_Stop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshSwapperComponent, nullptr, "Stop", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshSwapperComponent_Stop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshSwapperComponent_Stop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshSwapperComponent_Stop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshSwapperComponent_Stop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMeshSwapperComponent_NoRegister()
	{
		return UMeshSwapperComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMeshSwapperComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SourceAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SourceAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLooping_MetaData[];
#endif
		static void NewProp_bLooping_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLooping;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bReversePlayback_MetaData[];
#endif
		static void NewProp_bReversePlayback_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bReversePlayback;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bPlaying_MetaData[];
#endif
		static void NewProp_bPlaying_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPlaying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AccumulatedTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AccumulatedTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CachedFrameIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CachedFrameIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CachedBodySetup_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CachedBodySetup;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnFinishedPlaying_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFinishedPlaying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnAnimationNotifyEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAnimationNotifyEvent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMeshSwapperComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UStaticMeshComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MeshSwapper,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMeshSwapperComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMeshSwapperComponent_GetAnimation, "GetAnimation" }, // 2467329641
		{ &Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationFramerate, "GetAnimationFramerate" }, // 2106079791
		{ &Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLength, "GetAnimationLength" }, // 2737600261
		{ &Z_Construct_UFunction_UMeshSwapperComponent_GetAnimationLengthInFrames, "GetAnimationLengthInFrames" }, // 2800527130
		{ &Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPosition, "GetPlaybackPosition" }, // 1952017494
		{ &Z_Construct_UFunction_UMeshSwapperComponent_GetPlaybackPositionInFrames, "GetPlaybackPositionInFrames" }, // 2999753842
		{ &Z_Construct_UFunction_UMeshSwapperComponent_GetPlayRate, "GetPlayRate" }, // 2725356145
		{ &Z_Construct_UFunction_UMeshSwapperComponent_IsLooping, "IsLooping" }, // 2512881519
		{ &Z_Construct_UFunction_UMeshSwapperComponent_IsPlaying, "IsPlaying" }, // 1711366398
		{ &Z_Construct_UFunction_UMeshSwapperComponent_IsReversing, "IsReversing" }, // 604292114
		{ &Z_Construct_UFunction_UMeshSwapperComponent_OnRep_SourceAnimation, "OnRep_SourceAnimation" }, // 4151614028
		{ &Z_Construct_UFunction_UMeshSwapperComponent_Play, "Play" }, // 2883275110
		{ &Z_Construct_UFunction_UMeshSwapperComponent_PlayFromStart, "PlayFromStart" }, // 3417716849
		{ &Z_Construct_UFunction_UMeshSwapperComponent_Reverse, "Reverse" }, // 3051386050
		{ &Z_Construct_UFunction_UMeshSwapperComponent_ReverseFromEnd, "ReverseFromEnd" }, // 1129720884
		{ &Z_Construct_UFunction_UMeshSwapperComponent_SetAnimation, "SetAnimation" }, // 967348973
		{ &Z_Construct_UFunction_UMeshSwapperComponent_SetLooping, "SetLooping" }, // 2278608869
		{ &Z_Construct_UFunction_UMeshSwapperComponent_SetNewTime, "SetNewTime" }, // 1554858087
		{ &Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPosition, "SetPlaybackPosition" }, // 573988649
		{ &Z_Construct_UFunction_UMeshSwapperComponent_SetPlaybackPositionInFrames, "SetPlaybackPositionInFrames" }, // 1768130753
		{ &Z_Construct_UFunction_UMeshSwapperComponent_SetPlayRate, "SetPlayRate" }, // 1400087323
		{ &Z_Construct_UFunction_UMeshSwapperComponent_Stop, "Stop" }, // 2018817237
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Mesh Swapper" },
		{ "HideCategories", "Object Activation Components|Activation Trigger" },
		{ "IncludePath", "MeshSwapperComponent.h" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_SourceAnimation_MetaData[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "/** Animation currently being played */" },
		{ "DisplayThumbnail", "true" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Animation currently being played" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_SourceAnimation = { "SourceAnimation", "OnRep_SourceAnimation", (EPropertyFlags)0x0020080100000021, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapperComponent, SourceAnimation), Z_Construct_UClass_UMeshSwapAnimation_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_SourceAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_SourceAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_PlayRate_MetaData[] = {
		{ "Category", "MeshSwapAnimation" },
		{ "Comment", "/** Current play rate of the Animation */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Current play rate of the Animation" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0020080000000021, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapperComponent, PlayRate), METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_PlayRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_PlayRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bLooping_MetaData[] = {
		{ "Comment", "/** Whether the Animation should loop when it reaches the end, or stop */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Whether the Animation should loop when it reaches the end, or stop" },
	};
#endif
	void Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bLooping_SetBit(void* Obj)
	{
		((UMeshSwapperComponent*)Obj)->bLooping = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bLooping = { "bLooping", nullptr, (EPropertyFlags)0x0020080000000020, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(UMeshSwapperComponent), &Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bLooping_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bLooping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bLooping_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bReversePlayback_MetaData[] = {
		{ "Comment", "/** If playback should move the current position backwards instead of forwards */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "If playback should move the current position backwards instead of forwards" },
	};
#endif
	void Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bReversePlayback_SetBit(void* Obj)
	{
		((UMeshSwapperComponent*)Obj)->bReversePlayback = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bReversePlayback = { "bReversePlayback", nullptr, (EPropertyFlags)0x0020080000000020, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(UMeshSwapperComponent), &Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bReversePlayback_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bReversePlayback_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bReversePlayback_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bPlaying_MetaData[] = {
		{ "Comment", "/** Are we currently playing (moving Position) */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Are we currently playing (moving Position)" },
	};
#endif
	void Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bPlaying_SetBit(void* Obj)
	{
		((UMeshSwapperComponent*)Obj)->bPlaying = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bPlaying = { "bPlaying", nullptr, (EPropertyFlags)0x0020080000000020, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(UMeshSwapperComponent), &Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bPlaying_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bPlaying_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bPlaying_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_AccumulatedTime_MetaData[] = {
		{ "Comment", "/** Current position in the timeline */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Current position in the timeline" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_AccumulatedTime = { "AccumulatedTime", nullptr, (EPropertyFlags)0x0020080000000020, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapperComponent, AccumulatedTime), METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_AccumulatedTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_AccumulatedTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedFrameIndex_MetaData[] = {
		{ "Comment", "/** Last frame index calculated */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Last frame index calculated" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedFrameIndex = { "CachedFrameIndex", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapperComponent, CachedFrameIndex), METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedFrameIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedFrameIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedBodySetup_MetaData[] = {
		{ "Comment", "/** The cached body setup */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "The cached body setup" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedBodySetup = { "CachedBodySetup", nullptr, (EPropertyFlags)0x0020080000002000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapperComponent, CachedBodySetup), Z_Construct_UClass_UBodySetup_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedBodySetup_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedBodySetup_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnFinishedPlaying_MetaData[] = {
		{ "Comment", "/** Event called whenever a non-looping Animation finishes playing (either reaching the beginning or the end, depending on the play direction) */" },
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
		{ "ToolTip", "Event called whenever a non-looping Animation finishes playing (either reaching the beginning or the end, depending on the play direction)" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnFinishedPlaying = { "OnFinishedPlaying", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapperComponent, OnFinishedPlaying), Z_Construct_UDelegateFunction_MeshSwapper_AnimationFinishedPlaySignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnFinishedPlaying_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnFinishedPlaying_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnAnimationNotifyEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/MeshSwapperComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnAnimationNotifyEvent = { "OnAnimationNotifyEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMeshSwapperComponent, OnAnimationNotifyEvent), Z_Construct_UDelegateFunction_MeshSwapper_KeyframeNotifyEvent__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnAnimationNotifyEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnAnimationNotifyEvent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMeshSwapperComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_SourceAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_PlayRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bLooping,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bReversePlayback,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_bPlaying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_AccumulatedTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedFrameIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_CachedBodySetup,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnFinishedPlaying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeshSwapperComponent_Statics::NewProp_OnAnimationNotifyEvent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMeshSwapperComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMeshSwapperComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMeshSwapperComponent_Statics::ClassParams = {
		&UMeshSwapperComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMeshSwapperComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::PropPointers),
		0,
		0x00B010A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMeshSwapperComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshSwapperComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMeshSwapperComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMeshSwapperComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMeshSwapperComponent, 1277746385);
	template<> MESHSWAPPER_API UClass* StaticClass<UMeshSwapperComponent>()
	{
		return UMeshSwapperComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMeshSwapperComponent(Z_Construct_UClass_UMeshSwapperComponent, &UMeshSwapperComponent::StaticClass, TEXT("/Script/MeshSwapper"), TEXT("UMeshSwapperComponent"), false, nullptr, nullptr, nullptr);

	void UMeshSwapperComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_SourceAnimation(TEXT("SourceAnimation"));
		static const FName Name_PlayRate(TEXT("PlayRate"));
		static const FName Name_bLooping(TEXT("bLooping"));
		static const FName Name_bReversePlayback(TEXT("bReversePlayback"));
		static const FName Name_bPlaying(TEXT("bPlaying"));
		static const FName Name_AccumulatedTime(TEXT("AccumulatedTime"));

		const bool bIsValid = true
			&& Name_SourceAnimation == ClassReps[(int32)ENetFields_Private::SourceAnimation].Property->GetFName()
			&& Name_PlayRate == ClassReps[(int32)ENetFields_Private::PlayRate].Property->GetFName()
			&& Name_bLooping == ClassReps[(int32)ENetFields_Private::bLooping].Property->GetFName()
			&& Name_bReversePlayback == ClassReps[(int32)ENetFields_Private::bReversePlayback].Property->GetFName()
			&& Name_bPlaying == ClassReps[(int32)ENetFields_Private::bPlaying].Property->GetFName()
			&& Name_AccumulatedTime == ClassReps[(int32)ENetFields_Private::AccumulatedTime].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UMeshSwapperComponent"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMeshSwapperComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
