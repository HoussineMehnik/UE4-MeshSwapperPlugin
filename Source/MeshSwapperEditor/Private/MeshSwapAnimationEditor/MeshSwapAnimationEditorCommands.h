//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MeshSwapperStyle.h"

class FMeshSwapAnimationEditorCommands : public TCommands<FMeshSwapAnimationEditorCommands>
{
public:
	FMeshSwapAnimationEditorCommands()
		: TCommands<FMeshSwapAnimationEditorCommands>(
			TEXT("MeshSwapAnimationEditor"), // Context name for fast lookup
			NSLOCTEXT("Contexts", "MeshSwapAnimationEditor", "MeshSwapAnimation Editor"), // Localized context name for displaying
			NAME_None, // Parent
			FMeshSwapperStyle::Get()->GetStyleSetName() // Icon Style Set
			)
	{
	}

	// TCommand<> interface
	virtual void RegisterCommands() override;
	// End of TCommand<> interface

public:
	TSharedPtr<FUICommandInfo> AddKeyFrame;
	TSharedPtr<FUICommandInfo> ToggleParticles;
	TSharedPtr<FUICommandInfo> ToggleSounds;

	TSharedPtr<FUICommandInfo> SetShowGrid;
	TSharedPtr<FUICommandInfo> SetShowBounds;
	TSharedPtr<FUICommandInfo> SetShowCollision;

	// View Menu Commands
	TSharedPtr<FUICommandInfo> SetShowPivot;
	TSharedPtr<FUICommandInfo> SetShowSockets;

	// Timeline commands
	TSharedPtr<FUICommandInfo> AddNewFrame;
	TSharedPtr<FUICommandInfo> AddNewFrameBefore;
	TSharedPtr<FUICommandInfo> AddNewFrameAfter;

	// Asset commands
	TSharedPtr<FUICommandInfo> PickNewStaticMesh;
	TSharedPtr<FUICommandInfo> EditStaticMesh;
	TSharedPtr<FUICommandInfo> ShowInContentBrowser;

	TSharedPtr<FUICommandInfo> ResetTransform;
	TSharedPtr<FUICommandInfo> SmoothTransformInterpolation;
	TSharedPtr<FUICommandInfo> SetCollisionEnabled;
};
