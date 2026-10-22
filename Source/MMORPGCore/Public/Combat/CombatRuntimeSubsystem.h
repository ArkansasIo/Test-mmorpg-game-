#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CombatRuntimeSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FCombatRequest
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) uint64 AttackerId = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) uint64 TargetId = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FName AbilityId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Power = 0.0f;
};

UCLASS()
class MMORPGCORE_API UCombatRuntimeSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="AethernalAurelia|Combat") bool ResolveCombatRequest(const FCombatRequest& Request, float& OutDamage);
};
