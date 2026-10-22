#pragma once

#include "CoreMinimal.h"
#include "MatchmakingTypes.generated.h"

UENUM(BlueprintType)
enum class EAethernalMatchmakingMode : uint8
{
    OpenWorld,
    Dungeon,
    Trial,
    Raid,
    Arena,
    Battleground
};

USTRUCT(BlueprintType)
struct FMatchmakingRequest
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid AccountId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid CharacterId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EAethernalMatchmakingMode Mode = EAethernalMatchmakingMode::OpenWorld;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DesiredPartySize = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MinimumLevel = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaximumLevel = 50;
};

USTRUCT(BlueprintType)
struct FMatchmakingTicket
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid TicketId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid AccountId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid CharacterId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EAethernalMatchmakingMode Mode = EAethernalMatchmakingMode::OpenWorld;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int64 CreatedUnixSeconds = 0;
};
