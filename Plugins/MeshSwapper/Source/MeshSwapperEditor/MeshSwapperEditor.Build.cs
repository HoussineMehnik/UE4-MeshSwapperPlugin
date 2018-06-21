// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MeshSwapperEditor : ModuleRules
{
	public MeshSwapperEditor(ReadOnlyTargetRules Target) : base(Target)
	{
        bFasterWithoutUnity = true;
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;


        //PublicIncludePaths.Add("MeshSwapperEditor/Public");
        PrivateIncludePaths.Add("MeshSwapperEditor/Private");
      

        PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"ApplicationCore",
				"Json",
				"Slate",
				"SlateCore",
				"Engine",
				"InputCore",
				"UnrealEd", // for FAssetEditorManager
				"KismetWidgets",
				"Kismet",  // for FWorkflowCentricApplication
				"PropertyEditor",
				"RenderCore",
				"MeshSwapper",
				"ContentBrowser",
				"WorkspaceMenuStructure",
				"EditorStyle",
				"MeshPaint",
				"EditorWidgets",
				"Projects",
                 "AdvancedPreviewScene",
                "GraphEditor",
            });

		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"Settings",
				"IntroTutorials",
				"AssetTools",
				"LevelEditor",

            });

		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				"AssetTools"
			});

	}
}
