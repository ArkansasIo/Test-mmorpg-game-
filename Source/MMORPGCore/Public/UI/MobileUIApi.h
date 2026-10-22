#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Realm/RealmTypes.h"
#include "MobileUIApi.generated.h"

UENUM(BlueprintType)
enum class EMobileHUDMode : uint8
{
    Portrait,
    Landscape
};

UENUM(BlueprintType)
enum class EMobileInputAction : uint8
{
    Move,
    Look,
    Target,
    PrimaryAttack,
    Ability1,
    Ability2,
    Ability3,
    Dodge,
    Block,
    Interact,
    Mount,
    OpenCharacter,
    OpenInventory,
    OpenMap,
    OpenQuestLog,
    OpenGuild
};

USTRUCT(BlueprintType)
struct FMobileHUDLayout
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EMobileHUDMode Mode = EMobileHUDMode::Landscape;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bShowMinimap = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bShowQuestTracker = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bShowVirtualJoystick = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bShowAbilityBar = true;
};

UCLASS()
class MMORPGCORE_API UMobileUIApi : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="MMORPG|UI")
    static FMobileHUDLayout GetDefaultHUDLayout(EMobileHUDMode Mode);

    UFUNCTION(BlueprintPure, Category="MMORPG|UI")
    static int32 GetActivityPlayerLimit(EActivityType ActivityType);

    UFUNCTION(BlueprintPure, Category="MMORPG|UI")
    static bool IsTouchAction(EMobileInputAction Action);
};
