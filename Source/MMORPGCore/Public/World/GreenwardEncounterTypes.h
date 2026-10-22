#pragma once

#include "CoreMinimal.h"
#include "GreenwardEncounterTypes.generated.h"

UENUM(BlueprintType)
enum class EGreenwardEncounterType : uint8
{
    Tutorial,
    Wildlife,
    Bandit,
    Elite,
    Dungeon,
    WorldEvent
};

USTRUCT(BlueprintType)
struct FGreenwardEncounterDefinition
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName EncounterId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EGreenwardEncounterType Type = EGreenwardEncounterType::Wildlife;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName SpawnProfile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MinimumPlayers = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaximumPlayers = 4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPublicWorldEncounter = false;
};
