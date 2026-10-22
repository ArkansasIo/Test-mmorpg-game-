# Aethernal Aurelia — Game Design Document

## 1. Vision

Aethernal Aurelia is an original persistent-world MMORPG combined with a cinematic third-person action RPG. Players explore a connected fantasy world, develop characters through race, class, specialization, talents, equipment, professions, and relationships, and participate in cooperative and competitive activities.

## 2. Design Pillars

- Exploration: a world designed around discovery, traversal, secrets, events, and meaningful locations.
- Action: responsive melee, ranged, magical, defensive, and movement systems.
- RPG depth: statistics, abilities, talents, equipment, professions, reputation, and collections.
- Social persistence: parties, guilds, communication, trading, and shared activities.
- Persistent world: world events and player progression survive sessions.
- Cross-platform continuity: one account, cross-save, and cross-platform multiplayer.

## 3. World

The first continent is Aurelia. Initial development centers on the Greenward Frontier and Greenward Village. Planned continents are Aurelia, Varkhora, Elyndra, Drakor, and Nyxara.

The world hierarchy is:

```text
Continent -> Region -> Zone -> Location -> Encounter -> World Object/NPC
```

## 4. Character

Players create characters from supported races and classes. Initial races are Human, Elf, Dwarf, Halfling, and Orc. The class catalog includes Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue, Sorcerer, Warlock, and Wizard.

Core statistics:

- Strength
- Dexterity
- Constitution
- Intelligence
- Wisdom
- Charisma

Derived combat values include attack power, spell power, armor, magic resistance, critical rating, haste, mastery, versatility, accuracy, dodge, parry, and block.

## 5. Combat

Combat supports melee, ranged, and magical actions; targeting; combos; dodge; block; parry; interrupts; status effects; threat; stagger; finishers; and encounter mechanics.

The combat pipeline is:

```text
Input -> Intent -> Ability -> Validation -> Hit/Effect Resolution
-> Damage/Healing -> Threat/Status -> Replication -> Presentation
```

## 6. Progression

Characters gain experience, levels, talents, abilities, equipment, achievements, reputation, titles, mounts, companions, and collections.

## 7. Items and Professions

Items support weapons, armor, jewelry, consumables, materials, rarity, affixes, sockets, gems, enchantments, and upgrades.

Professions include mining, herbalism, forestry/woodworking, blacksmithing, armoring, weaponsmithing, leatherworking, tailoring, alchemy, enchanting, jewelcrafting, cooking, and scribing.

## 8. PvE

The game supports open-world encounters, dungeons, trials, raids, world bosses, scripted encounters, dynamic events, and exploration challenges.

## 9. Social

Social systems include friends, party, raid groups, chat, mail, trade, guilds, guild ranks, guild banks, guild progression, and achievements.

## 10. PvP

Planned PvP modes include duels, open-world PvP, battlegrounds, arenas, ratings, and objective-based encounters.

## 11. Platforms and Input

The game architecture targets PC, current console platforms, Switch 2, iPhone/iPad, and current Android devices through platform-specific build and SDK adapters.

Input abstractions support keyboard/mouse, gamepad, touch, controller remapping, aim/sensitivity settings, accessibility options, and platform-specific controls.

## 12. Graphics and Performance

The renderer is designed to scale across quality tiers. Settings include resolution, display mode, frame-rate target, scalability, textures, shadows, effects, post-processing, view distance, foliage, anti-aliasing/upscaling, motion blur, depth of field, audio quality, and accessibility presentation options.

GPU and CPU capabilities are detected at runtime and mapped to conservative quality presets. Manual overrides remain available where supported.

## 13. Multiplayer

Aethernal uses authoritative servers. Cross-platform players share the same account and realm architecture. Matchmaking and gameplay services operate on platform-neutral IDs.

## 14. Cross-Save

Character progression is stored in server-side persistent storage. A player may authenticate from another supported platform and continue from the latest valid character revision, subject to platform entitlement and account-linking rules.

## 15. Monetization and Entitlements

Any commercial entitlement system must be server-validated and platform-compliant. Platform purchases are represented as entitlements rather than trusted client flags.

## 16. Accessibility

The settings architecture supports text scaling, subtitles, color/contrast options, controller remapping, aim sensitivity, vibration, hold/toggle preferences, UI scale, audio channels, and reduced-motion options.

## 17. Content Production

Content is authored through Unreal assets, data definitions, procedural tools, Blender pipelines, and validated JSON/CSV/database seed data where appropriate. Generators should produce deterministic output from explicit seeds.

## 18. Vertical Slice

The first complete slice should include character creation, Greenward Village, traversal, one combat loop, NPC interaction, quest completion, item acquisition, inventory/equipment, progression, save/load, and a small multiplayer encounter.
