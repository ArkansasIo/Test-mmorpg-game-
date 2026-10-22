#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Persistence/CharacterPersistenceTypes.h"
#include "CharacterPersistenceSubsystem.generated.h"

UCLASS()
class MMORPGCORE_API UCharacterPersistenceSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Aethernal Aurelia|Persistence")
    bool CreateCharacterRecord(const FGuid& AccountId, const FString& CharacterName, FGuid& OutCharacterId);

    UFUNCTION(BlueprintCallable, Category="Aethernal Aurelia|Persistence")
    bool LoadCharacterRecord(const FGuid& CharacterId, FCharacterPersistenceRecord& OutRecord) const;

    UFUNCTION(BlueprintCallable, Category="Aethernal Aurelia|Persistence")
    bool SaveCharacterRecord(FCharacterPersistenceRecord& InOutRecord);

    UFUNCTION(BlueprintCallable, Category="Aethernal Aurelia|Persistence")
    bool DeleteCharacterRecord(const FGuid& CharacterId);

    UFUNCTION(BlueprintPure, Category="Aethernal Aurelia|Persistence")
    int64 GetLatestRevision(const FGuid& CharacterId) const;

private:
    UPROPERTY()
    TMap<FGuid, FCharacterPersistenceRecord> Records;
};
