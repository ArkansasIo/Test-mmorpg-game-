#pragma once

#include "CoreMinimal.h"
#include "CharacterTypes.generated.h"

UENUM(BlueprintType)
enum class ECharacterGender : uint8
{
    Female,
    Male,
    NonBinary
};

UENUM(BlueprintType)
enum class ECharacterArchetype : uint8
{
    Adventurer,
    Combatant,
    Caster,
    Support
};

USTRUCT(BlueprintType)
struct FCharacterIdentity
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName CharacterId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ECharacterGender Gender = ECharacterGender::Female;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName RaceId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ClassId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level = 1;
};
