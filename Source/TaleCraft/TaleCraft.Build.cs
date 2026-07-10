// Copyright Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

public class TaleCraft : ModuleRules
{
	public TaleCraft(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"TaleCraft",
			"TaleCraft/Variant_Platforming",
			"TaleCraft/Variant_Platforming/Animation",
			"TaleCraft/Variant_Combat",
			"TaleCraft/Variant_Combat/AI",
			"TaleCraft/Variant_Combat/Animation",
			"TaleCraft/Variant_Combat/Gameplay",
			"TaleCraft/Variant_Combat/Interfaces",
			"TaleCraft/Variant_Combat/UI",
			"TaleCraft/Variant_SideScrolling",
			"TaleCraft/Variant_SideScrolling/AI",
			"TaleCraft/Variant_SideScrolling/Gameplay",
			"TaleCraft/Variant_SideScrolling/Interfaces",
			"TaleCraft/Variant_SideScrolling/UI"
		});

		AddSuds();
		
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
	
	private string PluginsPath
	{
		get { return Path.GetFullPath( Path.Combine( ModuleDirectory, "../../Plugins/" ) ); }
	}
	
	protected void AddSuds() {
		// Linker
		PrivateDependencyModuleNames.AddRange(new string[] { "SUDS" });
		// Headers
		PublicIncludePaths.Add(Path.Combine( PluginsPath, "SUDS", "Source", "SUDS", "Public"));
	}
}
