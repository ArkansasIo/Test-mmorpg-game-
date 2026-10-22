#pragma once

#include "../../Source/MMORPGCore/Public/Networking/PlatformTypes.h"
#include <optional>
#include <string>

namespace Aethernal::Server
{
    class IdentityLinkService
    {
    public:
        virtual ~IdentityLinkService() = default;
        virtual bool LinkIdentity(const std::string& accountId, const FAethernalPlatformIdentity& identity) = 0;
        virtual bool UnlinkIdentity(const std::string& accountId, EAethernalPlatform platform) = 0;
        virtual std::optional<std::string> ResolveAccountId(const FAethernalPlatformIdentity& identity) = 0;
    };
}
