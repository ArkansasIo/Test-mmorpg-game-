#pragma once

#include "../../Source/MMORPGCore/Public/Networking/CrossSaveTypes.h"

namespace Aethernal::Server
{
    class ConflictResolver
    {
    public:
        static EAethernalSaveResult Compare(const FAethernalSaveRevision& incoming,
                                            const FAethernalSaveRevision& current)
        {
            if (!incoming.CharacterId.IsValid() || !current.CharacterId.IsValid())
            {
                return EAethernalSaveResult::RejectedInvalid;
            }

            if (incoming.CharacterId.Value != current.CharacterId.Value)
            {
                return EAethernalSaveResult::Conflict;
            }

            if (incoming.Revision <= current.Revision)
            {
                return EAethernalSaveResult::RejectedStale;
            }

            if (incoming.SchemaVersion != current.SchemaVersion)
            {
                return EAethernalSaveResult::Conflict;
            }

            return EAethernalSaveResult::Accepted;
        }
    };
}
