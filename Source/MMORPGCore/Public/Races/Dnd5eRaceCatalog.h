#pragma once

#include "CoreMinimal.h"
#include "Dnd5eRaceCatalog.generated.h"

UENUM(BlueprintType)
enum class EDnd5eRace : uint8
{
    Human,
    Elf,
    Dwarf,
    Halfling,
    Orc
};

USTRUCT(BlueprintType)
struct FRaceDefinition
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EDnd5eRace RaceId = EDnd5eRace::Human;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;
};

UCLASS()
class MMORPGCORE_API UDnd5eRaceCatalog : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure)
    static TArray<FRaceDefinition> GetAvailableRaces();
};
