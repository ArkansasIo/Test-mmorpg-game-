#include "UI/MobileUIApi.h"

FMobileHUDLayout UMobileUIApi::GetDefaultHUDLayout(EMobileHUDMode Mode)
{
    FMobileHUDLayout Layout;
    Layout.Mode = Mode;

    if (Mode == EMobileHUDMode::Portrait)
    {
        Layout.bShowMinimap = false;
        Layout.bShowQuestTracker = true;
        Layout.bShowVirtualJoystick = true;
        Layout.bShowAbilityBar = true;
    }

    return Layout;
}

int32 UMobileUIApi::GetActivityPlayerLimit(EActivityType ActivityType)
{
    switch (ActivityType)
    {
        case EActivityType::OpenWorld: return 64;
        case EActivityType::Dungeon:   return 4;
        case EActivityType::Trial:     return 6;
        case EActivityType::Raid:      return 12;
        default:                       return 1;
    }
}

bool UMobileUIApi::IsTouchAction(EMobileInputAction Action)
{
    switch (Action)
    {
        case EMobileInputAction::Move:
        case EMobileInputAction::Look:
        case EMobileInputAction::Target:
        case EMobileInputAction::PrimaryAttack:
        case EMobileInputAction::Ability1:
        case EMobileInputAction::Ability2:
        case EMobileInputAction::Ability3:
        case EMobileInputAction::Dodge:
        case EMobileInputAction::Block:
        case EMobileInputAction::Interact:
            return true;
        default:
            return false;
    }
}
