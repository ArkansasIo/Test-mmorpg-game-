#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FeatureModuleTypes.h"
#include "FeatureRuntimeSubsystem.generated.h"

UCLASS()
class MMORPGCORE_API UFeatureRuntimeSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintPure, Category="MMORPG|Features")
    const TArray<FFeatureModuleDefinition>& GetModules() const { return Modules; }

    UFUNCTION(BlueprintPure, Category="MMORPG|Features")
    bool IsModuleEnabled(FName ModuleId) const;

private:
    UPROPERTY()
    TArray<FFeatureModuleDefinition> Modules;
};
