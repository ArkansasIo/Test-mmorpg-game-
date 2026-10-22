#pragma once

#include "CoreMinimal.h"
#include "MobilePanelTypes.generated.h"

UENUM(BlueprintType)
enum class EMobilePanel : uint8
{
    MainMenu,
    Character,
    Equipment,
    Stats,
    Talents,
    Abilities,
    Inventory,
    Quests,
    Map,
    Professions,
    Guild,
    Party,
    Raid,
    Collections,
    Achievements,
    Social,
    Realm,
    Settings
};

UENUM(BlueprintType)
enum class EMobileLayoutMode : uint8
{
    Portrait,
    Landscape,
    TabletSplit
};

USTRUCT(BlueprintType)
struct FMobilePanelState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EMobilePanel Panel = EMobilePanel::MainMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bVisible = false;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bModal = false;
};
