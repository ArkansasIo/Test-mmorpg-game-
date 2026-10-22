#include "MatchmakingService.h"
#include "Networking/MatchmakingTypes.h"

EMatchmakingResult FMatchmakingService::Enqueue(const FMatchmakingRequest& Request, FMatchmakingTicket& OutTicket)
{
    if (!Request.AccountId.IsValid() || !Request.CharacterId.IsValid())
    {
        return EMatchmakingResult::Rejected;
    }

    for (const TPair<FGuid, FMatchmakingTicket>& Pair : Tickets)
    {
        if (Pair.Value.AccountId == Request.AccountId && Pair.Value.CharacterId == Request.CharacterId)
        {
            return EMatchmakingResult::AlreadyQueued;
        }
    }

    OutTicket.TicketId = FGuid::NewGuid();
    OutTicket.AccountId = Request.AccountId;
    OutTicket.CharacterId = Request.CharacterId;
    OutTicket.Mode = Request.Mode;
    OutTicket.CreatedUnixSeconds = FDateTime::UtcNow().ToUnixTimestamp();
    Tickets.Add(OutTicket.TicketId, OutTicket);
    return EMatchmakingResult::Accepted;
}

EMatchmakingResult FMatchmakingService::Cancel(const FGuid& TicketId)
{
    return Tickets.Remove(TicketId) > 0 ? EMatchmakingResult::Cancelled : EMatchmakingResult::NotFound;
}

bool FMatchmakingService::FindTicket(const FGuid& TicketId, FMatchmakingTicket& OutTicket) const
{
    const FMatchmakingTicket* Found = Tickets.Find(TicketId);
    if (!Found)
    {
        return false;
    }

    OutTicket = *Found;
    return true;
}

int32 FMatchmakingService::GetQueueSize() const
{
    return Tickets.Num();
}
