// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MeshSwapper : ModuleRules
{
	public MeshSwapper(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add("MeshSwapper/Public");
        PrivateIncludePaths.Add("MeshSwapper/Private");

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"ShaderCore",
				"RenderCore",
                "SlateCore",
                "Slate"
			}
		);
	}
}
