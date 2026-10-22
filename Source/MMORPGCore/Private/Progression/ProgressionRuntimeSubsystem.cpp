#include "Progression/ProgressionRuntimeSubsystem.h"

bool UProgressionRuntimeSubsystem::AddExperience(int64 Amount)
{
    if (Amount <= 0) return false;
    State.Experience += Amount;
    while (State.Experience >= static_cast<int64>(State.Level) * static_cast<int64>(State.Level) * 1000)
    {
        State.Experience -= static_cast<int64>(State.Level) * static_cast<int64>(State.Level) * 1000;
        ++State.Level;
    }
    return true;
}
