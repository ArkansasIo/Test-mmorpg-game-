#include "Networking/PlatformServiceSubsystem.h"

void UPlatformServiceSubsystem::SetPlatformIdentity(const FAethernalPlatformIdentity& NewIdentity)
{
    Identity = NewIdentity;
}
