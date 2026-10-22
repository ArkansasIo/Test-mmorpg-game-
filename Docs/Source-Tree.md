# MMORPG Source Tree

## Greenward Frontier starter implementation

```text
Source/
└── MMORPGCore/
    ├── Public/
    │   ├── Realm/
    │   ├── World/
    │   │   └── Zones/
    │   │       └── Greenward/
    │   │           ├── GreenwardZone.h
    │   │           ├── GreenwardTypes.h
    │   │           ├── GreenwardLandmarks.h
    │   │           └── GreenwardEncounters.h
    │   ├── Characters/
    │   │   ├── CharacterTypes.h
    │   │   ├── CharacterDefinition.h
    │   │   ├── CharacterCreationComponent.h
    │   │   ├── FemaleCharacter.h
    │   │   └── RaceClassRules.h
    │   ├── Classes/
    │   │   ├── ClassTypes.h
    │   │   ├── ClassDefinition.h
    │   │   └── Dnd5eClassCatalog.h
    │   ├── Races/
    │   │   ├── RaceTypes.h
    │   │   ├── RaceDefinition.h
    │   │   └── Dnd5eRaceCatalog.h
    │   ├── Stats/
    │   ├── Combat/
    │   ├── Abilities/
    │   ├── Items/
    │   ├── Inventory/
    │   ├── Equipment/
    │   ├── Quests/
    │   ├── NPC/
    │   ├── AI/
    │   ├── Instances/
    │   ├── Dungeons/
    │   ├── Trials/
    │   ├── Raids/
    │   ├── UI/
    │   ├── Networking/
    │   ├── Persistence/
    │   └── Lua/
    └── Private/
        └── matching module implementations

Data/
├── Characters/
├── Classes/
├── Races/
├── Specializations/
├── Stats/
├── Abilities/
├── Items/
├── Quests/
└── Zones/Greenward/

UI/
├── HUD/
├── CharacterCreation/
├── Character/
├── Inventory/
├── Quests/
├── Map/
├── Party/
├── Guild/
└── Realm/

Blender/
├── Characters/FemaleHuman/
├── Environment/Greenward/
├── Creatures/
├── Buildings/
└── Scripts/

Lua/
├── Character/
├── Classes/
├── Races/
├── Quests/
├── NPC/
└── World/Greenward/

Docs/
├── Source-Tree.md
├── Character-Creation.md
├── DND5E-Adaptation.md
└── Greenward-Asset-Pipeline.md
```

The repository uses original game code and assets. D&D 5e is treated as a rules reference for the requested class/race structure; proprietary game assets and text are not copied.
