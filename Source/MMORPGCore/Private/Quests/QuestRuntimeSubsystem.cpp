#include "Quests/QuestRuntimeSubsystem.h"

bool UQuestRuntimeSubsystem::StartQuest(FName QuestId)
{
    if (QuestId.IsNone()) return false;
    for (const FQuestRuntimeState& State : QuestStates)
    {
        if (State.QuestId == QuestId) return false;
    }
    FQuestRuntimeState State;
    State.QuestId = QuestId;
    QuestStates.Add(MoveTemp(State));
    return true;
}

bool UQuestRuntimeSubsystem::CompleteQuest(FName QuestId)
{
    for (FQuestRuntimeState& State : QuestStates)
    {
        if (State.QuestId == QuestId)
        {
            State.bCompleted = true;
            return true;
        }
    }
    return false;
}
