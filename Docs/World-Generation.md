# World Generation Plan

The initial world target is five original continents totaling approximately 100 km² of explorable terrain.

| Continent | Area target | Initial zones |
|---|---:|---|
| Aurelia | 25 km² | Greenward Frontier, Aurelian Heartlands, Watcher Coast |
| Varkhora | 20 km² | Frostmarch, Highstone Expanse, Ironwind Valley |
| Elyndra | 20 km² | Elderwood, Moonlit Vale, Silvergrove |
| Drakor | 20 km² | Ashen Reach, Red Dune Sea, Emberfall |
| Nyxara | 15 km² | Veiled Frontier, Nightsea, Starfall Wastes |

## Streaming hierarchy

```text
Persistent Realm
  -> World
    -> Continent
      -> Region
        -> Zone
          -> World Partition Cell
            -> Actors / NPCs / Creatures / Events / Resources
```

## Production order

1. Aurelia / Greenward Frontier: starter-zone production template.
2. Aurelia expansion zones.
3. Varkhora.
4. Elyndra.
5. Drakor.
6. Nyxara.

All continents use the same C++ world interfaces and data-driven zone definitions. Individual zones may override environment, navigation, weather, encounters, quests, factions, and asset sets.

## Gray-box phase

Every new zone begins with:

- terrain blockout
- roads and traversal paths
- major landmarks
- settlement footprints
- dungeon entrances
- encounter volumes
- spawn points
- navigation data
- streaming boundaries
- mobile performance budget

Detailed meshes, materials, animation polish, VFX, audio, and final lighting are added only after traversal and gameplay are validated.
