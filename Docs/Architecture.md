# MMORPG Architecture

## Realm
`FRealmServer` is a first-class subsystem inside the game executable. Each host device may create one persistent realm. The realm owns authoritative world state.

## Activity model
- Open World: 32–64 players target
- Dungeon: 4 players
- Trial: 6 players
- Raid: 12 players

Instances are children of the same realm, not separate realms. Players return to the same persistent character state after an instance.

## Authority
Client input is treated as a request. Server-side C++ validates movement, combat, inventory, economy, quest completion, rewards, and persistence.

## RPG layers
Character -> Race -> Class -> Specialization -> Level -> Talents -> Equipment -> Buffs/Debuffs -> Derived Stats -> Combat.

## Technology
UE5/Blueprints provide presentation and composition. C++23 provides authoritative simulation. Lua provides controlled gameplay scripting. MySQL-compatible storage provides persistence.

## Host migration
A production migration protocol should transfer a signed world snapshot under an authenticated lease and prevent split-brain hosts. The logical RealmID remains stable while the host changes.
