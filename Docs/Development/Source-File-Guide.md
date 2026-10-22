# Source File Development Guide

## C++ Header

Use headers for public contracts, reflected properties, enums, structs, interfaces, and class declarations.

```cpp
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ExampleSubsystem.generated.h"

UCLASS()
class MMORPGCORE_API UExampleSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="Aethernal|Example")
    bool ExecuteAction(FName ActionId);
};
```

## C++ Implementation

Keep implementation details in the `.cpp`. Validate inputs at the server boundary and log actionable failures.

## Blueprint

Blueprints should orchestrate presentation and content behavior while stable gameplay contracts remain in C++. Avoid duplicating authoritative calculations in Blueprint and C++.

## Data

Use DataAssets/DataTables for tunable content. Use JSON/SQL for pipeline and persistence data where appropriate. Version externally authored schemas.

## Lua-like Scripting

Scripts should call sandboxed engine APIs. Scripts must not directly mutate protected database state or bypass authority validation.

## Naming

Use clear domain prefixes for public runtime classes. Avoid generic subsystem class names that can collide across modules.

## Dependency Rules

Lower-level modules must not depend on UI. Platform adapters must not contain gameplay rules. Persistence must not contain presentation logic. Shared contracts should live in stable API modules.

## Error Handling

Return explicit failure states for invalid actions. Use structured logs for server diagnostics. Never use client UI messages as the sole validation mechanism.

## Testing

Every nontrivial formula, state transition, serialization format, and security boundary should have automated tests.

## Review Checklist

- Does the class have one clear responsibility?
- Is the public API minimal?
- Is the operation authoritative?
- Is replication defined?
- Is persistence defined?
- Are failure cases handled?
- Are platform dependencies isolated?
- Is the feature data-driven where appropriate?
- Are tests included?
- Is documentation updated?
