# Aethernal Aurelia — Game Development Guide

## 1. Purpose

This document defines the engineering workflow for building Aethernal Aurelia as a cross-platform persistent-world MMORPG and cinematic third-person action RPG.

Primary implementation targets are Unreal Engine 5.7, C++23-compatible native code, Blueprint/UMG, data-driven assets, Lua-like gameplay scripting, and a server-authoritative backend.

## 2. Development Principles

1. Keep gameplay state authoritative on the server.
2. Keep platform APIs behind adapters.
3. Keep content data-driven whenever practical.
4. Keep rendering, input, networking, persistence, and gameplay domains separated.
5. Prefer deterministic server simulation for competitive state.
6. Never trust a client-provided inventory, currency, damage result, quest completion, or progression value.
7. Use versioned schemas and save revisions.
8. Build a playable vertical slice before scaling the world.

## 3. Source Layout

```text
Source/MMORPGCore/Public/   public gameplay APIs
Source/MMORPGCore/Private/  implementations
Blueprints/                  Blueprint-facing content
Content/                     Unreal assets
Data/                        authoritative content definitions
Lua/                         sandboxed gameplay scripts
Server/                      realm and service code
Database/MySQL/              persistence schema and migrations
Tests/                       automated tests
Tools/                       generators and validators
Docs/                        engineering and design documentation
```

## 4. How to Write a Feature

For every feature:

1. Define its domain and public API.
2. Define persistent data requirements.
3. Define replication requirements.
4. Define client presentation.
5. Define validation and failure cases.
6. Implement the C++ runtime layer.
7. Expose only stable operations to Blueprint.
8. Add data definitions.
9. Add Lua hooks only where scripting is appropriate.
10. Add unit and integration tests.
11. Document the feature and dependencies.

## 5. Runtime Flow

```text
Input -> Intent -> Validation -> Server Gameplay System -> State Mutation
      -> Replication -> Client Presentation -> UI/VFX/Audio
```

A client may request an action, but the server determines whether that action is legal and what state change occurs.

## 6. Character Flow

```text
Account
  -> Platform Identity
  -> Character
  -> Race/Class/Spec
  -> Stats
  -> Equipment/Inventory
  -> Quest/Progression State
  -> World State
```

## 7. Cross-Save

Every persistent character state has a monotonically increasing revision. A save operation writes a complete validated snapshot or an atomic transaction. Devices never become the canonical source of truth.

Recommended save record fields:

- account_id
- character_id
- revision
- schema_version
- payload_hash
- created_at
- updated_at
- source_platform
- server_region

Conflicts must be resolved on the service side. Never silently overwrite a newer revision with an older device snapshot.

## 8. Cross-Platform Multiplayer

All gameplay uses platform-neutral IDs. Platform-specific identities are linked to one Aethernal account. Matchmaking, party, guild, chat, presence, and realm services operate on Aethernal IDs.

Platform SDKs are accessed through adapter interfaces. Proprietary first-party SDK binaries and credentials are supplied separately by their platform developer programs.

## 9. Server Development

Start with a local authoritative realm server, then introduce authentication, persistence, sessions, matchmaking, replication, monitoring, and dedicated-server deployment.

Minimum server services:

- Authentication
- Account/identity linking
- Character service
- Save service
- Realm/session service
- World state service
- Inventory/economy service
- Quest/progression service
- Matchmaking
- Social/guild service
- Telemetry/audit service

## 10. Testing Strategy

Unit tests cover formulas and isolated systems. Integration tests cover persistence and service boundaries. Gameplay tests cover combat, quests, inventory, progression, and world events. Networking tests cover authority, replication, reconnect, and migration. Performance tests measure server tick cost, replication bandwidth, memory, and database latency.

## 11. Development Order

### Phase 1 — Foundation

Project, modules, build configuration, logging, configuration, IDs, serialization, feature catalog, and test framework.

### Phase 2 — Playable Slice

Greenward Village, character creation, movement, camera, combat, inventory, quests, NPCs, one dungeon, progression, save/load.

### Phase 3 — Multiplayer

Authoritative realm, sessions, replication, party, chat, cross-platform identity, cross-save, reconnect, and host migration.

### Phase 4 — MMO Systems

Guilds, professions, economy, marketplace, world events, PvP, trials, raids, achievements, collections, and live-service operations.

### Phase 5 — Production

Dedicated infrastructure, observability, deployment automation, certification work, scalability, security review, accessibility, localization, content pipelines, and platform compliance.

## 12. Security

Never place secrets in source control. Never trust client-side economy or combat calculations. Validate every authenticated request, enforce authorization server-side, rate-limit service endpoints, audit sensitive mutations, and isolate administrative operations.

## 13. Definition of Done

A feature is not complete merely because its files exist. It is complete when its runtime implementation, data, UI, networking behavior, persistence behavior, tests, documentation, and failure handling are implemented and verified for its intended scope.
