#pragma once

#include "CoreMinimal.h"

struct FMatchmakingTicket;
struct FMatchmakingRequest;

enum class EMatchmakingResult : uint8
{
    Accepted,
    Rejected,
    AlreadyQueued,
    NotFound,
    Cancelled
};

class FMatchmakingService
{
public:
    EMatchmakingResult Enqueue(const FMatchmakingRequest& Request, FMatchmakingTicket& OutTicket);
    EMatchmakingResult Cancel(const FGuid& TicketId);
    bool FindTicket(const FGuid& TicketId, FMatchmakingTicket& OutTicket) const;
    int32 GetQueueSize() const;

private:
    TMap<FGuid, FMatchmakingTicket> Tickets;
};
