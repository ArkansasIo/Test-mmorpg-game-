#pragma once

#include "CoreMinimal.h"
#include "FeatureModuleTypes.h"
#include "FeatureModuleCatalog.generated.h"

UCLASS()
class MMORPGCORE_API UFeatureModuleCatalog : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="MMORPG|Features")
    static TArray<FFeatureModuleDefinition> GetCoreModules();
};
