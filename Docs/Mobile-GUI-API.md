# Mobile GUI API

The first UI API is `UMobileUIApi`, a Blueprint-callable C++ interface intended to be the common contract for the iOS and Android GUI.

## API

- `GetDefaultHUDLayout(Mode)` returns the default portrait or landscape HUD configuration.
- `GetActivityPlayerLimit(ActivityType)` exposes the shared realm limits: 64 open-world, 4 dungeon, 6 trial, 12 raid.
- `IsTouchAction(Action)` identifies actions handled directly by touch input.

## UI layers

```text
MobileUIRoot
├── HUD
│   ├── HealthResource
│   ├── Minimap
│   ├── QuestTracker
│   ├── TargetFrame
│   └── AbilityBar
├── TouchControls
│   ├── VirtualJoystick
│   ├── LookPad
│   ├── ActionButtons
│   └── ContextAction
├── Character
├── Inventory
├── Equipment
├── Abilities
├── Talents
├── Quests
├── Map
├── Party
├── Raid
├── Guild
└── Realm
```

## Design rule

The GUI is a client presentation layer. Character state, combat validation, inventory ownership, quest progression, and realm authority remain server-authoritative in the shared C++ simulation.

## Next API layers

1. `UCharacterUIApi`
2. `UCombatUIApi`
3. `UInventoryUIApi`
4. `UQuestUIApi`
5. `UPartyUIApi`
6. `UGuildUIApi`
7. `URealmUIApi`
8. `UMobileInputApi`
9. `UAccessibilityUIApi`
10. `UNavigationUIApi`
