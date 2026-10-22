#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ProgressionRuntimeSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FProgressionState
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int64 Experience = 0;
};

UCLASS()
class MMORPGCORE_API UProgressionRuntimeSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="AethernalAurelia|Progression") bool AddExperience(int64 Amount);
    UFUNCTION(BlueprintPure, Category="AethernalAurelia|Progression") FProgressionState GetProgression() const { return State; }
private:
    UPROPERTY() FProgressionState State;
};
