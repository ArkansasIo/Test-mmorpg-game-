#pragma once

#include "../../Source/MMORPGCore/Public/Networking/CrossSaveTypes.h"
#include <optional>
#include <string>

namespace Aethernal::Server
{
    class SaveRevisionService
    {
    public:
        virtual ~SaveRevisionService() = default;
        virtual std::optional<FAethernalSaveRevision> GetLatestRevision(const std::string& characterId) = 0;
        virtual EAethernalSaveResult CommitRevision(const FAethernalSaveRevision& revision, const std::string& payload) = 0;
    };
}
