#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Networking/PlatformTypes.h"
#include "PlatformServiceSubsystem.generated.h"

UCLASS()
class MMORPGCORE_API UPlatformServiceSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Aethernal|Platform")
    void SetPlatformIdentity(const FAethernalPlatformIdentity& Identity);

    UFUNCTION(BlueprintPure, Category="Aethernal|Platform")
    const FAethernalPlatformIdentity& GetPlatformIdentity() const { return Identity; }

    UFUNCTION(BlueprintPure, Category="Aethernal|Platform")
    bool HasVerifiedIdentity() const { return Identity.bVerified && !Identity.PlatformUserId.IsEmpty(); }

private:
    UPROPERTY()
    FAethernalPlatformIdentity Identity;
};
