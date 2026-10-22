#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "WorldRuntimeSubsystem.generated.h"

UCLASS()
class MMORPGCORE_API UWorldRuntimeSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="AethernalAurelia|World") void InitializeWorldRuntime();
    UFUNCTION(BlueprintPure, Category="AethernalAurelia|World") bool IsWorldRuntimeReady() const { return bReady; }
private:
    UPROPERTY() bool bReady = false;
};
