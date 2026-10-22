# Greenward Frontier — Gray-Scale Asset Manifest

The first pass intentionally uses primitive meshes, gray materials, simple line drawings and basic renders. Production art is a later replacement pass.

## Environment

| Category | Gray-box assets |
|---|---:|
| Landscape/cliff modules | 20 |
| Rock modules | 25 |
| Tree prototypes | 15 |
| Vegetation prototypes | 30 |
| Fence modules | 10 |
| Road/path modules | 15 |
| Bridge modules | 4 |
| Water/river modules | 6 |
| Cave modules | 4 |
| Ruin modules | 20 |
| Watchtower modules | 8 |
| Village building modules | 30 |
| Small props | 100 |

## Character blockouts

- Human player male/female base meshes
- Guard
- Farmer
- Merchant
- Blacksmith
- Innkeeper
- Healer
- Trainer
- Scout
- Commander
- Bandit
- Wolf
- Boar
- Raven
- Spider
- Hound
- Briarback boss

## Technical rule

Every asset begins as a collision-valid gray mesh with a simple material. Gameplay, navigation, camera framing, interaction distance and network relevance are tested before detailed meshes, textures, materials and VFX are added.

## Blender source organization

```text
Blender/
└── Greenward/
    ├── Environment/
    ├── Buildings/
    ├── Props/
    ├── Characters/
    ├── Creatures/
    ├── Dungeon/
    └── Blockout/
```

## UE5 destination

```text
Content/World/Greenward/
├── Maps/
├── Environment/
├── Buildings/
├── Props/
├── Characters/
├── Creatures/
├── Dungeon/
├── Materials/
├── VFX/
└── Data/
```
