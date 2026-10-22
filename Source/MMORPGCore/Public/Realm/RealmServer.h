#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Realm/RealmTypes.h"
#include "RealmServer.generated.h"

UCLASS()
class MMORPGCORE_API URealmServer : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Realm")
    bool CreateRealm(const FName RealmName, int32 WorldSeed);

    UFUNCTION(BlueprintCallable, Category="Realm")
    bool StartRealm(ERealmRunMode RunMode);

    UFUNCTION(BlueprintCallable, Category="Realm")
    void StopRealm();

    UFUNCTION(BlueprintPure, Category="Realm")
    bool IsRunning() const { return bRunning; }

    UFUNCTION(BlueprintPure, Category="Realm")
    FRealmDescriptor GetRealm() const { return Realm; }

    UFUNCTION(BlueprintCallable, Category="Realm")
    void TickRealm(float DeltaSeconds);

private:
    FRealmDescriptor Realm;
    ERealmRunMode RunMode = ERealmRunMode::Local;
    bool bRunning = false;
};
