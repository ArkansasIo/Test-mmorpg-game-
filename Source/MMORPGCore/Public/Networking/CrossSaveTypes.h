#pragma once

#include "CoreMinimal.h"
#include "AccountTypes.h"
#include "PlatformTypes.h"
#include "CrossSaveTypes.generated.h"

USTRUCT(BlueprintType)
struct MMORPGCORE_API FAethernalSaveRevision
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FAethernalCharacterId CharacterId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int64 Revision = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SchemaVersion = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PayloadHash;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EAethernalPlatform SourcePlatform = EAethernalPlatform::Unknown;
};

UENUM(BlueprintType)
enum class EAethernalSaveResult : uint8
{
    Accepted,
    RejectedStale,
    RejectedInvalid,
    Conflict,
    Failed
};
