# Test MMORPG Game — Embedded Realm MMORPG Framework

A UE5/C++23/Lua/Blueprint-oriented MMORPG scaffold built around a single persistent realm per host device.

## Core model
- Every game installation can host an authoritative realm inside the game executable.
- Internet multiplayer connects players directly to that realm host.
- One persistent open world supports 32–64 concurrent players as the initial design target.
- 4-player dungeons, 6-player trials, and 12-player raids are instanced activities inside the same realm.
- Character progression, inventory, quests, equipment, reputation, and economy persist across instances.
- The same realm server code can later run headless as a dedicated server.

## RPG framework
- Classes and specializations/subclasses
- Primary, secondary, derived, defensive, offensive, and resource stats
- Abilities, talents, cooldowns, buffs/debuffs, combat resolution
- Inventory, equipment, loot, crafting/professions
- Quests, achievements, factions, reputation, guilds
- NPC AI, threat, encounters, world events

## Technology layers
- UE5: rendering, world, networking integration, UMG/Blueprints
- C++23: authoritative simulation and rules
- Lua: data-driven gameplay scripting hooks
- MySQL-compatible persistence schema
- Blender: original source asset pipeline

This repository is a source framework scaffold, not a compiled UE5 executable. A UE5 toolchain is required to build the game.
