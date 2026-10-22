#pragma once

#include "CoreMinimal.h"
#include "Persistence/CharacterPersistenceTypes.generated.h"

USTRUCT(BlueprintType)
struct FCharacterPersistenceRecord
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid CharacterId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid AccountId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int64 SaveRevision = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SchemaVersion = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int64 Experience = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ZoneId = TEXT("GreenwardFrontier");

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Location = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FRotator Rotation = FRotator::ZeroRotator;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PayloadHash;
};
