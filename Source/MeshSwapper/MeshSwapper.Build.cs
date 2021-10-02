//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

using UnrealBuildTool;

public class MeshSwapper : ModuleRules
{
	public MeshSwapper(ReadOnlyTargetRules Target) : base(Target)
	{
		/*PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;*/   PCHUsage = ModuleRules.PCHUsageMode.NoPCHs; bUseUnity = false;

		PrivateIncludePaths.Add("MeshSwapper/Private");

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"RenderCore",
                "SlateCore",
                "Slate"
			}
		);
	}
}
