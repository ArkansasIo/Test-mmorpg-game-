#include "Combat/CombatRuntimeSubsystem.h"

bool UCombatRuntimeSubsystem::ResolveCombatRequest(const FCombatRequest& Request, float& OutDamage)
{
    if (Request.AttackerId == 0 || Request.TargetId == 0 || Request.Power <= 0.0f)
    {
        OutDamage = 0.0f;
        return false;
    }

    OutDamage = Request.Power;
    return true;
}
