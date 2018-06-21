// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MeshSwapperStyle.h"

class FMeshSwapperEditorCommands : public TCommands<FMeshSwapperEditorCommands>
{
public:
	FMeshSwapperEditorCommands()
		: TCommands<FMeshSwapperEditorCommands>(
			TEXT("MeshSwapper"), // Context name for fast lookup
			NSLOCTEXT("Contexts", "MeshSwapperEditor", "MeshSwapper Editor"), // Localized context name for displaying
			NAME_None, // Parent
			FMeshSwapperStyle::Get()->GetStyleSetName() // Icon Style Set
			)
	{
	}

	// TCommand<> interface
	virtual void RegisterCommands() override;
	// End of TCommand<> interface

public:

};
