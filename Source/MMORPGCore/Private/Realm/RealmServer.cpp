#include "Realm/RealmServer.h"

bool URealmServer::CreateRealm(const FName RealmName, int32 WorldSeed)
{
    Realm.RealmId = FGuid::NewGuid();
    Realm.RealmName = RealmName;
    Realm.MaxOpenWorldPlayers = 64;
    Realm.WorldSeed = WorldSeed;
    Realm.ProtocolVersion = 1;
    return Realm.RealmId.IsValid();
}

bool URealmServer::StartRealm(ERealmRunMode InRunMode)
{
    if (!Realm.RealmId.IsValid())
    {
        return false;
    }

    RunMode = InRunMode;
    bRunning = true;
    return true;
}

void URealmServer::StopRealm()
{
    bRunning = false;
}

void URealmServer::TickRealm(float DeltaSeconds)
{
    if (!bRunning || DeltaSeconds <= 0.0f)
    {
        return;
    }

    // Authoritative realm simulation hooks will run here.
}
