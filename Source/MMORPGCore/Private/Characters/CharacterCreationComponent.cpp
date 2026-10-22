#include "Characters/CharacterCreationComponent.h"

UCharacterCreationComponent::UCharacterCreationComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

bool UCharacterCreationComponent::ValidateSelection(const FCharacterIdentity& Selection, FString& Error) const
{
    if (Selection.DisplayName.TrimStartAndEnd().IsEmpty())
    {
        Error = TEXT("A character name is required.");
        return false;
    }

    if (Selection.Gender != ECharacterGender::Female)
    {
        Error = TEXT("This starter creation flow is configured for a female character.");
        return false;
    }

    Error.Reset();
    return true;
}

bool UCharacterCreationComponent::CreateFemaleCharacter(
    const FString& DisplayName,
    EDnd5eRace Race,
    EDnd5eClass ClassType,
    FCharacterIdentity& OutCharacter,
    FString& Error) const
{
    OutCharacter = FCharacterIdentity{};
    OutCharacter.DisplayName = DisplayName.TrimStartAndEnd();
    OutCharacter.Gender = ECharacterGender::Female;
    OutCharacter.Level = 1;
    OutCharacter.CharacterId = FName(*FGuid::NewGuid().ToString(EGuidFormats::Digits));

    switch (Race)
    {
        case EDnd5eRace::Human: OutCharacter.RaceId = TEXT("Human"); break;
        case EDnd5eRace::Elf: OutCharacter.RaceId = TEXT("Elf"); break;
        case EDnd5eRace::Dwarf: OutCharacter.RaceId = TEXT("Dwarf"); break;
        case EDnd5eRace::Halfling: OutCharacter.RaceId = TEXT("Halfling"); break;
        case EDnd5eRace::Orc: OutCharacter.RaceId = TEXT("Orc"); break;
    }

    switch (ClassType)
    {
        case EDnd5eClass::Barbarian: OutCharacter.ClassId = TEXT("Barbarian"); break;
        case EDnd5eClass::Bard: OutCharacter.ClassId = TEXT("Bard"); break;
        case EDnd5eClass::Cleric: OutCharacter.ClassId = TEXT("Cleric"); break;
        case EDnd5eClass::Druid: OutCharacter.ClassId = TEXT("Druid"); break;
        case EDnd5eClass::Fighter: OutCharacter.ClassId = TEXT("Fighter"); break;
        case EDnd5eClass::Monk: OutCharacter.ClassId = TEXT("Monk"); break;
        case EDnd5eClass::Paladin: OutCharacter.ClassId = TEXT("Paladin"); break;
        case EDnd5eClass::Ranger: OutCharacter.ClassId = TEXT("Ranger"); break;
        case EDnd5eClass::Rogue: OutCharacter.ClassId = TEXT("Rogue"); break;
        case EDnd5eClass::Sorcerer: OutCharacter.ClassId = TEXT("Sorcerer"); break;
        case EDnd5eClass::Warlock: OutCharacter.ClassId = TEXT("Warlock"); break;
        case EDnd5eClass::Wizard: OutCharacter.ClassId = TEXT("Wizard"); break;
    }

    return ValidateSelection(OutCharacter, Error);
}
