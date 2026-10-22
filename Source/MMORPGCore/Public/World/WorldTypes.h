#pragma once

#include "CoreMinimal.h"
#include "WorldTypes.generated.h"

UENUM(BlueprintType)
enum class EWorldContinent : uint8
{
    Aurelia,
    Varkhora,
    Elyndra,
    Drakor,
    Nyxara
};

USTRUCT(BlueprintType)
struct FWorldZoneDefinition
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ZoneId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EWorldContinent Continent = EWorldContinent::Aurelia;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AreaKm2 = 4.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName RecommendedLevelRange = TEXT("1-5");
};
