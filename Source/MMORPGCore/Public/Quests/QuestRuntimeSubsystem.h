#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestRuntimeSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FQuestRuntimeState
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FName QuestId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentObjective = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bCompleted = false;
};

UCLASS()
class MMORPGCORE_API UQuestRuntimeSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="AethernalAurelia|Quests") bool StartQuest(FName QuestId);
    UFUNCTION(BlueprintCallable, Category="AethernalAurelia|Quests") bool CompleteQuest(FName QuestId);
    UFUNCTION(BlueprintPure, Category="AethernalAurelia|Quests") const TArray<FQuestRuntimeState>& GetQuestStates() const { return QuestStates; }
private:
    UPROPERTY() TArray<FQuestRuntimeState> QuestStates;
};
