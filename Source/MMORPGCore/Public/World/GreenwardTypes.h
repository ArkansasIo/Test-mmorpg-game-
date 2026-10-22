#pragma once

#include "CoreMinimal.h"
#include "GreenwardTypes.generated.h"

UENUM(BlueprintType)
enum class EGreenwardArea : uint8
{
    Village,
    Farmland,
    OldPinewood,
    WatchersRoad,
    OldWatchtower,
    HighstoneRidge,
    River,
    SouthGate,
    HollowrootEntrance,
    WorldEventClearing
};

USTRUCT(BlueprintType)
struct FGreenwardLandmark
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EGreenwardArea Area = EGreenwardArea::Village;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Location = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StreamingRadius = 5000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMajorLandmark = false;
};

USTRUCT(BlueprintType)
struct FGreenwardAssetBudget
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 EnvironmentProps = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ModularBuildings = 30;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Rocks = 25;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Trees = 15;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Vegetation = 50;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 VillageBuildings = 12;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CreatureArchetypes = 8;
};
