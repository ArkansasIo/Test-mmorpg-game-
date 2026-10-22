#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "InventoryRuntimeSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FInventoryEntry
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FName ItemId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Quantity = 0;
};

UCLASS()
class MMORPGCORE_API UInventoryRuntimeSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="AethernalAurelia|Inventory") bool AddItem(FName ItemId, int32 Quantity);
    UFUNCTION(BlueprintPure, Category="AethernalAurelia|Inventory") const TArray<FInventoryEntry>& GetItems() const { return Items; }
private:
    UPROPERTY() TArray<FInventoryEntry> Items;
};
