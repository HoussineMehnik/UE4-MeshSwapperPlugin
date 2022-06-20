//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

namespace UnrealBuildTool.Rules
{
	public class MeshSwapperEditor : ModuleRules
	{
		public MeshSwapperEditor(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;   /*PCHUsage = ModuleRules.PCHUsageMode.NoPCHs; bUseUnity = false;*/

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
				"EditorFramework",
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
}