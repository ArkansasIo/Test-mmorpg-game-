#include "Features/FeatureRuntimeSubsystem.h"
#include "Features/FeatureModuleCatalog.h"

void UFeatureRuntimeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    Modules = UFeatureModuleCatalog::GetCoreModules();
}

void UFeatureRuntimeSubsystem::Deinitialize()
{
    Modules.Reset();
    Super::Deinitialize();
}

bool UFeatureRuntimeSubsystem::IsModuleEnabled(FName ModuleId) const
{
    for (const FFeatureModuleDefinition& Module : Modules)
    {
        if (Module.ModuleId == ModuleId)
        {
            return Module.State == EFeatureModuleState::Prototype ||
                   Module.State == EFeatureModuleState::Active ||
                   Module.State == EFeatureModuleState::Complete;
        }
    }
    return false;
}
