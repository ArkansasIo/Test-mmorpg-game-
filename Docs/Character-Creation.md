# Character Creation

## Starter character

The first playable character flow is a **female third-person fantasy adventurer**. The initial creation screen exposes five race choices and the full requested D&D-style class catalog.

### Five race choices

1. Human
2. Elf
3. Dwarf
4. Halfling
5. Orc

These are used as the initial fantasy archetypes. The implementation should use original descriptions, names, models, textures, animations, and lore rather than copying another game's assets.

### Class catalog

The standard D&D 5e Player's Handbook has 12 core classes, so the source catalog contains all 12:

1. Barbarian
2. Bard
3. Cleric
4. Druid
5. Fighter
6. Monk
7. Paladin
8. Ranger
9. Rogue
10. Sorcerer
11. Warlock
12. Wizard

The character-selection UI can expose nine classes for the first prototype build while the backend retains the complete 12-class catalog. This keeps the requested nine-class starter presentation without throwing away the other core classes.

## Creation flow

```text
Character Creation
  -> Female body preset
  -> Race
  -> Class
  -> Appearance
  -> Name
  -> Preview
  -> Validate
  -> Spawn at Greenward Village
```

## Appearance modules

```text
FemaleCharacter
├── Body
├── Face
├── Skin
├── Hair
├── Eyes
├── Brows
├── Scars / markings
├── Voice profile
├── Starting outfit
└── Animation profile
```

## First prototype classes shown

The initial nine-button UI can present:

- Fighter
- Barbarian
- Ranger
- Rogue
- Cleric
- Paladin
- Druid
- Wizard
- Sorcerer

Bard, Monk, Warlock remain implemented in the catalog for subsequent UI expansion.

## Spawn

After creation, the character enters the persistent realm at the Greenward Frontier starter village. The first tutorial objectives teach movement, camera control, interaction, basic combat, dodge/block, inventory, quest tracking, and the transition from village to wilderness.
