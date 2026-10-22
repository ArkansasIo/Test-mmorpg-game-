#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GreenwardTypes.h"
#include "GreenwardZone.generated.h"

UCLASS()
class MMORPGCORE_API UGreenwardZone : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category="Greenward")
    const TArray<FGreenwardLandmark>& GetLandmarks() const { return Landmarks; }

    UFUNCTION(BlueprintCallable, Category="Greenward")
    FGreenwardAssetBudget GetAssetBudget() const { return AssetBudget; }

    UFUNCTION(BlueprintPure, Category="Greenward")
    bool IsGreenwardWorld() const;

private:
    UPROPERTY()
    TArray<FGreenwardLandmark> Landmarks;

    UPROPERTY()
    FGreenwardAssetBudget AssetBudget;
};
