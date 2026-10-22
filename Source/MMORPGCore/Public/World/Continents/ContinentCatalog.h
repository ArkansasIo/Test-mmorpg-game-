#pragma once

#include "CoreMinimal.h"
#include "World/WorldTypes.h"
#include "ContinentCatalog.generated.h"

USTRUCT(BlueprintType)
struct FContinentDefinition
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EWorldContinent Continent = EWorldContinent::Aurelia;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ContinentId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TargetAreaKm2 = 20.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FName> ZoneIds;
};

UCLASS()
class MMORPGCORE_API UContinentCatalog : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure)
    static TArray<FContinentDefinition> GetInitialContinents();
};
