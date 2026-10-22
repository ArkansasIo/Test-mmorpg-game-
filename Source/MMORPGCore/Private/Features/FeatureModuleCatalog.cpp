#include "Features/FeatureModuleCatalog.h"

TArray<FFeatureModuleDefinition> UFeatureModuleCatalog::GetCoreModules()
{
    TArray<FFeatureModuleDefinition> Modules;

    const auto Add = [&Modules](const TCHAR* Id, EMMORPGFeatureDomain Domain, const TCHAR* Name, const TCHAR* Description, EFeatureModuleState State = EFeatureModuleState::Prototype, std::initializer_list<const TCHAR*> Dependencies = {})
    {
        FFeatureModuleDefinition Module;
        Module.ModuleId = FName(Id);
        Module.Domain = Domain;
        Module.DisplayName = FText::FromString(Name);
        Module.Description = FText::FromString(Description);
        Module.State = State;
        for (const TCHAR* Dependency : Dependencies)
        {
            Module.Dependencies.Add(FName(Dependency));
        }
        Modules.Add(MoveTemp(Module));
    };

    Add(TEXT("World"), EMMORPGFeatureDomain::World, TEXT("World Runtime"), TEXT("Persistent continents, zones, streaming, environment and world state."));
    Add(TEXT("World.Navigation"), EMMORPGFeatureDomain::World, TEXT("Navigation"), TEXT("Navigation meshes, traversal links and world-cell connections."), EFeatureModuleState::Prototype, {TEXT("World")});
    Add(TEXT("World.Events"), EMMORPGFeatureDomain::World, TEXT("World Events"), TEXT("Dynamic encounters, invasions, bosses and regional events."), EFeatureModuleState::Prototype, {TEXT("World")});
    Add(TEXT("Character"), EMMORPGFeatureDomain::Character, TEXT("Character"), TEXT("Identity, creation, appearance and lifecycle."));
    Add(TEXT("Races"), EMMORPGFeatureDomain::Character, TEXT("Races"), TEXT("Playable race definitions and racial rules."), EFeatureModuleState::Prototype, {TEXT("Character")});
    Add(TEXT("Classes"), EMMORPGFeatureDomain::Character, TEXT("Classes"), TEXT("Classes, specializations, roles and class rules."), EFeatureModuleState::Prototype, {TEXT("Character")});
    Add(TEXT("Stats"), EMMORPGFeatureDomain::Progression, TEXT("Stats"), TEXT("Primary, secondary, resource and derived statistics."), EFeatureModuleState::Prototype, {TEXT("Character")});
    Add(TEXT("Combat"), EMMORPGFeatureDomain::Combat, TEXT("Combat"), TEXT("Action combat, targeting, damage, mitigation, threat and status effects."), EFeatureModuleState::Prototype, {TEXT("Stats"), TEXT("Classes")});
    Add(TEXT("Abilities"), EMMORPGFeatureDomain::Combat, TEXT("Abilities"), TEXT("Skills, spells, cooldowns, resources, combos and effects."), EFeatureModuleState::Prototype, {TEXT("Combat")});
    Add(TEXT("Items"), EMMORPGFeatureDomain::Item, TEXT("Items"), TEXT("Item definitions, rarity, affixes, upgrades and rewards."));
    Add(TEXT("Inventory"), EMMORPGFeatureDomain::Item, TEXT("Inventory"), TEXT("Bags, stacks, currencies and item containers."), EFeatureModuleState::Prototype, {TEXT("Items"), TEXT("Character")});
    Add(TEXT("Equipment"), EMMORPGFeatureDomain::Item, TEXT("Equipment"), TEXT("Equipment slots, loadouts, stats and appearance."), EFeatureModuleState::Prototype, {TEXT("Items"), TEXT("Stats")});
    Add(TEXT("Quests"), EMMORPGFeatureDomain::Quest, TEXT("Quests"), TEXT("Campaign, side quests, objectives, rewards and quest state."), EFeatureModuleState::Prototype, {TEXT("Character"), TEXT("World")});
    Add(TEXT("NPC"), EMMORPGFeatureDomain::NPC, TEXT("NPC Runtime"), TEXT("NPC definitions, schedules, vendors, trainers and interactions."), EFeatureModuleState::Prototype, {TEXT("World")});
    Add(TEXT("AI"), EMMORPGFeatureDomain::NPC, TEXT("AI"), TEXT("Creature behavior, perception, combat AI, groups and encounters."), EFeatureModuleState::Prototype, {TEXT("NPC"), TEXT("Combat")});
    Add(TEXT("Dungeons"), EMMORPGFeatureDomain::Dungeon, TEXT("Dungeons"), TEXT("Four-player instanced dungeon lifecycle and encounters."), EFeatureModuleState::Prototype, {TEXT("World"), TEXT("Combat"), TEXT("Quests")});
    Add(TEXT("Trials"), EMMORPGFeatureDomain::Dungeon, TEXT("Trials"), TEXT("Six-player challenge activities and boss mechanics."), EFeatureModuleState::Prototype, {TEXT("Combat"), TEXT("Dungeons")});
    Add(TEXT("Raids"), EMMORPGFeatureDomain::Raid, TEXT("Raids"), TEXT("Twelve-player raid lifecycle, wings and multi-phase bosses."), EFeatureModuleState::Prototype, {TEXT("Combat"), TEXT("Trials")});
    Add(TEXT("Professions"), EMMORPGFeatureDomain::Profession, TEXT("Professions"), TEXT("Gathering, crafting, recipes, specialization and production."), EFeatureModuleState::Prototype, {TEXT("Items"), TEXT("Economy")});
    Add(TEXT("Social"), EMMORPGFeatureDomain::Social, TEXT("Social"), TEXT("Friends, party, chat, groups and player interaction."), EFeatureModuleState::Prototype, {TEXT("Character")});
    Add(TEXT("Guilds"), EMMORPGFeatureDomain::Social, TEXT("Guilds"), TEXT("Guild membership, ranks, bank, progression and activities."), EFeatureModuleState::Prototype, {TEXT("Social"), TEXT("Economy")});
    Add(TEXT("PvP"), EMMORPGFeatureDomain::PvP, TEXT("PvP"), TEXT("Duels, battlegrounds, arenas, factions and world PvP."), EFeatureModuleState::Prototype, {TEXT("Combat"), TEXT("Social")});
    Add(TEXT("Economy"), EMMORPGFeatureDomain::Economy, TEXT("Economy"), TEXT("Currencies, vendors, trading, marketplace and auction systems."), EFeatureModuleState::Prototype, {TEXT("Items")});
    Add(TEXT("Progression"), EMMORPGFeatureDomain::Progression, TEXT("Progression"), TEXT("Levels, talents, achievements, collections and long-term progression."), EFeatureModuleState::Prototype, {TEXT("Character"), TEXT("Stats")});
    Add(TEXT("Cinematic"), EMMORPGFeatureDomain::Cinematic, TEXT("Cinematic"), TEXT("Story sequences, camera choreography, dialogue and presentation."), EFeatureModuleState::Prototype, {TEXT("World"), TEXT("Character")});
    Add(TEXT("Traversal"), EMMORPGFeatureDomain::Traversal, TEXT("Traversal"), TEXT("Movement, climbing, swimming, mounts and traversal interactions."), EFeatureModuleState::Prototype, {TEXT("World")});
    Add(TEXT("UI"), EMMORPGFeatureDomain::UI, TEXT("UI"), TEXT("HUD, menus, mobile controls, controller and responsive layouts."), EFeatureModuleState::Prototype, {TEXT("Character"), TEXT("World")});
    Add(TEXT("Networking"), EMMORPGFeatureDomain::Networking, TEXT("Networking"), TEXT("Replication, authority, sessions, relevancy and host migration."), EFeatureModuleState::Prototype, {TEXT("World"), TEXT("Character")});
    Add(TEXT("Persistence"), EMMORPGFeatureDomain::Persistence, TEXT("Persistence"), TEXT("Characters, inventory, quests, world state and realm persistence."), EFeatureModuleState::Prototype, {TEXT("Character"), TEXT("Items"), TEXT("Quests")});
    Add(TEXT("Lua"), EMMORPGFeatureDomain::Scripting, TEXT("Lua Runtime"), TEXT("Data-driven gameplay scripts, event hooks and safe scripting API."), EFeatureModuleState::Prototype, {TEXT("World"), TEXT("Combat"), TEXT("Quests")});

    return Modules;
}
