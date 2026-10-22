# Mobile MMORPG UI Architecture

The interface uses an original, data-driven MMORPG presentation inspired by the usability patterns of classic PC MMORPGs while avoiding copied proprietary artwork, icons, terminology, or layouts.

## UI layers

1. `HUD` — persistent gameplay information.
2. `Navigation` — main menu, tabs, breadcrumbs, back/close behavior.
3. `Panels` — character, inventory, equipment, quests, map, abilities, professions, guild, party, raid, collections, achievements, settings, realm.
4. `Context` — NPC dialogue, vendors, loot, crafting, quest interaction, group finder, social actions.
5. `Modal` — confirmation, error, reconnect, migration, matchmaking, rewards.
6. `Notification` — combat feedback, quest updates, loot, social messages, system notices.

## Responsive modes

- Portrait: one primary panel at a time with bottom navigation.
- Landscape: HUD-first presentation with docked panels and expanded information density.
- Tablet: split-panel layouts where screen size permits.
- Controller/keyboard: focus navigation and hotkey routing.

## Core menu tree

- Character
  - Overview
  - Equipment
  - Attributes
  - Combat Stats
  - Talents
  - Specialization
  - Abilities
- Inventory
  - Bags
  - Equipment
  - Quest Items
  - Materials
  - Consumables
- Quests
  - Active
  - Available
  - Completed
  - Objectives
  - Rewards
- World
  - Map
  - Local Map
  - World Map
  - Locations
  - Dungeon Finder
  - Trial Finder
  - Raid Finder
- Social
  - Friends
  - Party
  - Raid
  - Guild
  - Factions
  - Chat
- Progression
  - Professions
  - Collections
  - Achievements
  - Titles
- Realm
  - Realm Status
  - Players
  - Activities
  - Host/Migration Status
  - Network
- Settings
  - Controls
  - Graphics
  - Audio
  - Interface
  - Accessibility
  - Account

All panels consume typed C++ API data and can be implemented as UMG widgets or Blueprint subclasses without duplicating game rules.
