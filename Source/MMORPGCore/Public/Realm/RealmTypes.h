#pragma once

#include "CoreMinimal.h"
#include "RealmTypes.generated.h"

UENUM(BlueprintType)
enum class ERealmRunMode : uint8
{
    Local,
    Host,
    Internet,
    Dedicated
};

UENUM(BlueprintType)
enum class EActivityType : uint8
{
    OpenWorld,
    Dungeon,
    Trial,
    Raid
};

USTRUCT(BlueprintType)
struct FRealmDescriptor
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid RealmId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName RealmName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxOpenWorldPlayers = 64;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 WorldSeed = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ProtocolVersion = 1;
};

USTRUCT(BlueprintType)
struct FActivityCapacity
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EActivityType Type = EActivityType::OpenWorld;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxPlayers = 64;
};
