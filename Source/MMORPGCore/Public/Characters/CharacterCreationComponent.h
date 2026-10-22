#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterTypes.h"
#include "Classes/Dnd5eClassCatalog.h"
#include "Races/Dnd5eRaceCatalog.h"
#include "CharacterCreationComponent.generated.h"

UCLASS(ClassGroup=(MMORPG), Blueprintable, meta=(BlueprintSpawnableComponent))
class MMORPGCORE_API UCharacterCreationComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCharacterCreationComponent();

    UFUNCTION(BlueprintCallable)
    bool ValidateSelection(const FCharacterIdentity& Selection, FString& Error) const;

    UFUNCTION(BlueprintCallable)
    bool CreateFemaleCharacter(const FString& DisplayName, EDnd5eRace Race, EDnd5eClass ClassType, FCharacterIdentity& OutCharacter, FString& Error) const;
};
