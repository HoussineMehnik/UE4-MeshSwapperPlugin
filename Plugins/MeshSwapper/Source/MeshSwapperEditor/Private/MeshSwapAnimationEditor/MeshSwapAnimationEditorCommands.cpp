// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MeshSwapAnimationEditor/MeshSwapAnimationEditorCommands.h"

//////////////////////////////////////////////////////////////////////////
// FMeshSwapAnimationEditorCommands

#define LOCTEXT_NAMESPACE "MeshSwapAnimationEditorCommands"

void FMeshSwapAnimationEditorCommands::RegisterCommands()
{
	UI_COMMAND(AddKeyFrame, "Add Key Frame", "Inserts a new key frame at the current time", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ToggleParticles, "Particles", "Inserts a new key frame at the current time", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(ToggleSounds, "Sounds", "Inserts a new key frame at the current time", EUserInterfaceActionType::ToggleButton, FInputChord());

	UI_COMMAND(SetShowGrid, "Grid", "Displays the viewport grid.", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(SetShowBounds, "Bounds", "Toggles display of the bounds of the static mesh.", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(SetShowCollision, "Collision", "Toggles display of the simplified collision mesh of the static mesh, if one has been assigned.", EUserInterfaceActionType::ToggleButton, FInputChord(EKeys::C, EModifierKey::Alt));

	UI_COMMAND(SetShowPivot, "Show Pivot", "Display the pivot location of the static mesh.", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(SetShowSockets, "Sockets", "Displays the MeshSwapAnimation sockets.", EUserInterfaceActionType::ToggleButton, FInputChord());

	UI_COMMAND(AddNewFrame, "Add Key Frame", "Adds a new key frame to the MeshSwapAnimation.", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(AddNewFrameBefore, "Insert Key Frame Before", "Adds a new key frame to the MeshSwapAnimation before the selection.", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(AddNewFrameAfter, "Insert Key Frame After", "Adds a new key frame to the MeshSwapAnimation after the selection.", EUserInterfaceActionType::Button, FInputChord());

	UI_COMMAND(PickNewStaticMesh, "Pick New Static Mesh", "Picks a new mesh keygrame for this key frame.", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(EditStaticMesh, "Edit Static Mesh", "Opens the mesh keygrame for this key frame in the MeshKeyFrame Editor.", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ShowInContentBrowser, "Show in Content Browser", "Shows the mesh keygrame for this key frame in the Content Browser.", EUserInterfaceActionType::Button, FInputChord());

	UI_COMMAND(ResetTransform, "Reset Transform", "Picks a new mesh keygrame for this key frame.", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(SmoothTransformInterpolation, "Smooth Transform Interpolation", "Picks a new mesh keygrame for this key frame.", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(SetCollisionEnabled, "Collision Enbabled", "Picks a new mesh keygrame for this key frame.", EUserInterfaceActionType::ToggleButton, FInputChord());

}

#undef LOCTEXT_NAMESPACE
