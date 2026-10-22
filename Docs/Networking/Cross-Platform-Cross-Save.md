# Cross-Platform and Cross-Save Specification

## Account Model

```text
Aethernal Account
  ├── PlayStation Identity
  ├── Xbox Identity
  ├── PC Identity
  ├── Nintendo Identity
  ├── Apple Identity
  └── Google Identity
```

All identities resolve to one server-side Aethernal Account ID after the platform authentication flow and explicit account-linking rules are satisfied.

## Save Model

```text
Account -> Character -> SaveRevision[n]
```

A save revision contains a schema version, revision number, source platform, timestamp, integrity hash, and validated character state.

The service rejects stale revisions and prevents a device from replacing newer authoritative state.

## Multiplayer Model

```text
Platform Client
      |
Platform Adapter
      |
Authentication
      |
Aethernal Session
      |
Authoritative Realm
      |
Replication / Matchmaking / Social
```

Gameplay identity is platform-neutral. Platform APIs remain isolated inside adapters.

## Platform Adapter Contract

Each adapter should provide equivalent abstractions for:

- Authentication
- Identity linking
- Entitlements
- Friends/presence where available
- Achievements/trophies where available
- Commerce receipt validation where applicable
- Controller/input capabilities
- Platform lifecycle events

Proprietary platform SDK headers, libraries, certificates, credentials, and platform-specific implementation details are not included in this repository.

## Reconnect

A disconnected client reconnects using its authenticated session and receives the latest authoritative state. Duplicate sessions are resolved by the session service according to account and character policy.

## Host Migration

For peer-assisted or player-hosted development modes, host migration must preserve authoritative realm state. Production MMO operation should prefer dedicated authoritative servers.

## Security Rules

Never trust a client for:

- Currency balances
- Inventory ownership
- Item creation
- Damage results
- Quest completion
- Experience awards
- Entitlements
- Account ownership
- Administrative privileges

Every sensitive operation is authenticated, authorized, validated, persisted, and audited.
