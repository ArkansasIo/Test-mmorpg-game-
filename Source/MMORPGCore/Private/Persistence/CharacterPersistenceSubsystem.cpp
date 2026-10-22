#include "Persistence/CharacterPersistenceSubsystem.h"

bool UCharacterPersistenceSubsystem::CreateCharacterRecord(const FGuid& AccountId, const FString& CharacterName, FGuid& OutCharacterId)
{
    if (!AccountId.IsValid() || CharacterName.TrimStartAndEnd().IsEmpty())
    {
        return false;
    }

    OutCharacterId = FGuid::NewGuid();

    FCharacterPersistenceRecord Record;
    Record.CharacterId = OutCharacterId;
    Record.AccountId = AccountId;
    Record.CharacterName = CharacterName.TrimStartAndEnd();
    Record.SaveRevision = 1;

    Records.Add(OutCharacterId, Record);
    return true;
}

bool UCharacterPersistenceSubsystem::LoadCharacterRecord(const FGuid& CharacterId, FCharacterPersistenceRecord& OutRecord) const
{
    const FCharacterPersistenceRecord* Found = Records.Find(CharacterId);
    if (!Found)
    {
        return false;
    }

    OutRecord = *Found;
    return true;
}

bool UCharacterPersistenceSubsystem::SaveCharacterRecord(FCharacterPersistenceRecord& InOutRecord)
{
    if (!InOutRecord.CharacterId.IsValid() || !InOutRecord.AccountId.IsValid())
    {
        return false;
    }

    FCharacterPersistenceRecord* Existing = Records.Find(InOutRecord.CharacterId);
    if (!Existing)
    {
        return false;
    }

    if (InOutRecord.SaveRevision < Existing->SaveRevision)
    {
        return false;
    }

    InOutRecord.SaveRevision = Existing->SaveRevision + 1;
    Records[InOutRecord.CharacterId] = InOutRecord;
    return true;
}

bool UCharacterPersistenceSubsystem::DeleteCharacterRecord(const FGuid& CharacterId)
{
    return Records.Remove(CharacterId) > 0;
}

int64 UCharacterPersistenceSubsystem::GetLatestRevision(const FGuid& CharacterId) const
{
    const FCharacterPersistenceRecord* Found = Records.Find(CharacterId);
    return Found ? Found->SaveRevision : 0;
}
