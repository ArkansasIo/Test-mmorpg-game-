# Platform SDK Architecture

## Objective

Provide one engine-facing interface for PlayStation, Xbox, PC, Switch 2, iPhone/iPad, and Android without copying proprietary first-party SDKs into the project.

## Layers

```text
Game / MMORPGCore
        |
Aethernal Platform API
        |
Platform Adapter Interfaces
        |
+------+------+------+------+------+------+
| PS | Xbox | PC | Nintendo | Apple | Android |
+------+------+------+------+------+------+
        |
Official Platform SDK
```

## Engine Interfaces

Recommended interfaces:

- `IAethernalPlatformIdentity`
- `IAethernalPlatformAuth`
- `IAethernalPlatformEntitlements`
- `IAethernalPlatformFriends`
- `IAethernalPlatformAchievements`
- `IAethernalPlatformInput`
- `IAethernalPlatformLifecycle`
- `IAethernalPlatformCommerce`

## Build Configuration

Platform adapters are selected at compile time and registered at runtime. Unsupported services return explicit capability results rather than silently failing.

Example conceptual configuration:

```text
AET_PLATFORM_PC=1
AET_PLATFORM_PLAYSTATION=0/1
AET_PLATFORM_XBOX=0/1
AET_PLATFORM_NINTENDO=0/1
AET_PLATFORM_APPLE=0/1
AET_PLATFORM_ANDROID=0/1
```

Actual console/mobile builds must use the platform's approved Unreal integration and SDK package.

## PC

PC supports keyboard/mouse, gamepad, graphics configuration, display settings, input remapping, and PC platform identity adapters.

## Console

Console implementations isolate platform account authentication, achievements/trophies, entitlement checks, controller APIs, suspend/resume, and platform-specific networking requirements.

## Mobile

iPhone/iPad and Android implementations isolate touch input, controller support where available, mobile lifecycle, background/foreground transitions, device capability detection, graphics presets, resolution/scaling, battery/performance policy, and platform authentication.

## Switch 2

Nintendo-specific APIs remain in the Nintendo adapter and are supplied only through the authorized developer SDK environment.

## Rendering and Hardware Detection

The engine exposes a normalized capability structure:

```text
CPU vendor / family / logical cores
GPU vendor / feature level / memory class
RAM class
Display resolution
Refresh rate
HDR capability
Storage capability
Controller capabilities
Touch capability
Network capability
```

The quality manager converts those capabilities into a scalable profile rather than hard-coding one configuration per device.
