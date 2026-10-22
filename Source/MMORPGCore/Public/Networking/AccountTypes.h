#pragma once

#include "CoreMinimal.h"
#include "AccountTypes.generated.h"

USTRUCT(BlueprintType)
struct MMORPGCORE_API FAethernalAccountId
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid Value;

    bool IsValid() const { return Value.IsValid(); }
};

USTRUCT(BlueprintType)
struct MMORPGCORE_API FAethernalCharacterId
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid Value;

    bool IsValid() const { return Value.IsValid(); }
};
