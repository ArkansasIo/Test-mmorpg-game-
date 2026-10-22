# Greenward Frontier — 3D Gray-Box Blockout

## Purpose

Greenward Frontier is the first playable human starter zone for the MMORPG. It is a fully 3D, third-person, mobile-first environment inspired by the density and traversal philosophy of cinematic action RPGs while using original world design, assets, names, and implementation.

## Target

- Approximate footprint: 4 km²
- Persistent realm: yes
- Open-world capacity: 64 players
- Camera: third-person
- Mobile: portrait menus + landscape gameplay HUD
- PC: keyboard/mouse + controller
- Rendering: UE5 World Partition, scalable for mobile

## Gray-box map

```text
                              NORTH
                                ^
                                |
                    +-----------------------+
                    |     HIGHSTONE RIDGE   |
                    | cliffs / ruins / cave |
                    +-----------+-----------+
                                |
              +-----------------+-----------------+
              |                                   |
       +------+-------+                    +------+------+
       |  OLD         |                    | WATCHER'S   |
       |  PINEWOOD    |                    | ROAD        |
       |  FOREST      |                    |             |
       +------+-------+                    +------+------+
              |                                   |
              |                           +-------+-------+
              |                           | OLD WATCHTOWER |
              |                           +-------+-------+
              |                                   |
      +-------+---------+                 +-------+-------+
      | GREENWARD       |-----------------| FRONTIER ROAD |
      | VILLAGE         |                 +-------+-------+
      +---+---------+---+                         |
          |         |                      +------+------+
          |         +----------------------|  FARMLANDS  |
          |                                +------+------+
      +---+----+                                  |
      | RIVER  |                           +------+------+
      +---+----+                           | SOUTH GATE |
          |                                +------+------+
          |                                       |
          +-------------------- WORLD ------------+
```

## Asset philosophy

Use gray-box geometry first. Every major asset has a collision-valid blockout before production art.

### Environment kit

- landscape tiles
- cliffs
- rock blocks
- trees
- shrubs
- grass cards
- logs
- fences
- roads
- bridges
- river pieces
- waterfall blockouts
- caves
- ruins
- tower
- village buildings
- modular walls
- roofs
- doors
- windows
- stairs
- props

### Village kit

Town hall, inn, blacksmith, general store, shrine, stable, guard house, training yard, houses, barns, well, mill, carts, stalls, fences, lamps and signs.

### Gameplay spaces

- player spawn
- training yard
- quest hubs
- creature camps
- resource fields
- forest paths
- hidden paths
- cave entrance
- Hollowroot Caverns entrance
- world-event clearing
- Old Watchtower encounter

## Blockout rules

1. Gray geometry before detailed meshes.
2. Gameplay routes must be readable without UI markers.
3. Every major landmark should be visible from at least one adjacent traversal route.
4. Avoid long empty travel corridors.
5. Maintain multiple traversal choices where practical.
6. Keep combat arenas naturally integrated into terrain.
7. Use World Partition cells for streaming and simulation relevance.

## Production pass

After the blockout is playable, replace gray geometry with modular production assets while preserving collision, navigation, quest coordinates and gameplay volumes.
