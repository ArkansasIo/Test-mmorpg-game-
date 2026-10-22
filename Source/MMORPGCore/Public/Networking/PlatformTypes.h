#pragma once

#include "CoreMinimal.h"
#include "PlatformTypes.generated.h"

UENUM(BlueprintType)
enum class EAethernalPlatform : uint8
{
    Unknown,
    PC,
    PlayStation,
    Xbox,
    Nintendo,
    Apple,
    Android
};

USTRUCT(BlueprintType)
struct MMORPGCORE_API FAethernalPlatformIdentity
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EAethernalPlatform Platform = EAethernalPlatform::Unknown;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PlatformUserId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bVerified = false;
};
