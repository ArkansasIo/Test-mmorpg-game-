#pragma once

#include "CoreMinimal.h"
#include "Dnd5eClassCatalog.generated.h"

UENUM(BlueprintType)
enum class EDnd5eClass : uint8
{
    Barbarian,
    Bard,
    Cleric,
    Druid,
    Fighter,
    Monk,
    Paladin,
    Ranger,
    Rogue,
    Sorcerer,
    Warlock,
    Wizard
};

USTRUCT(BlueprintType)
struct FClassDefinition
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EDnd5eClass ClassId = EDnd5eClass::Fighter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;
};

UCLASS()
class MMORPGCORE_API UDnd5eClassCatalog : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure)
    static TArray<FClassDefinition> GetAvailableClasses();
};
