# Aethernal Aurelia — Build Matrix

| Target | Input | Graphics | Account | Multiplayer | Notes |
|---|---|---|---|---|---|
| PC | Keyboard/mouse + controller | Scalable PC tiers | Platform adapter | Cross-platform | Development baseline |
| PlayStation | Controller | Console profile | Platform adapter | Cross-platform | Official SDK required |
| Xbox | Controller | Console profile | Platform adapter | Cross-platform | Official SDK required |
| Switch 2 | Controller + supported input | Mobile/console profile | Platform adapter | Cross-platform | Official SDK required |
| iPhone | Touch + controller | Mobile profile | Apple adapter | Cross-platform | App Store requirements apply |
| iPad | Touch + controller | Tablet profile | Apple adapter | Cross-platform | Tablet UI scaling required |
| Android | Touch + controller | Device-tier profile | Google adapter | Cross-platform | Hardware fragmentation handled by capability tiers |

## Shared Systems

All targets use the same gameplay contracts, server protocol, account model, cross-save model, content IDs, character IDs, and authoritative realm services.

## Input

The input layer maps physical controls to actions rather than binding gameplay directly to keys/buttons. This permits keyboard/mouse, gamepad, touch, and remappable accessibility controls to share the same gameplay API.

## Resolution

The display manager supports dynamic resolution, fixed resolution, viewport scaling, aspect-ratio handling, UI scaling, and frame-rate targets appropriate to the device.

## Hardware Profiles

The runtime capability detector selects a conservative default profile based on CPU, GPU, memory, display, and platform capabilities. Users can override nonrestricted settings.
