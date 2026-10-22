#pragma once

#include "CoreMinimal.h"
#include "FeatureModuleTypes.generated.h"

UENUM(BlueprintType)
enum class EMMORPGFeatureDomain : uint8
{
    World,
    Character,
    Combat,
    Quest,
    NPC,
    Dungeon,
    Raid,
    Item,
    Profession,
    Social,
    PvP,
    Economy,
    Progression,
    Cinematic,
    Traversal,
    UI,
    Networking,
    Persistence,
    Scripting
};

UENUM(BlueprintType)
enum class EFeatureModuleState : uint8
{
    Planned,
    Prototype,
    Active,
    Complete
};

USTRUCT(BlueprintType)
struct FFeatureModuleDefinition
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ModuleId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EMMORPGFeatureDomain Domain = EMMORPGFeatureDomain::World;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EFeatureModuleState State = EFeatureModuleState::Planned;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FName> Dependencies;
};
