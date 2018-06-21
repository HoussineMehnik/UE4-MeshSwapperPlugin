// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/WeakObjectPtr.h"
#include "UnrealWidget.h"

class FCanvas;
class FPrimitiveDrawInterface;
class FSceneView;
class FViewport;
class UPrimitiveComponent;


//////////////////////////////////////////////////////////////////////////
// FSocketEditingHelper

class FSocketEditingHelper
{
public:
	static void DrawSockets(UPrimitiveComponent* PreviewComponent, const FSceneView* View, FPrimitiveDrawInterface* PDI);
	static void DrawSocketNames( UPrimitiveComponent* PreviewComponent, FViewport& Viewport, FSceneView& View, FCanvas& Canvas);
};
