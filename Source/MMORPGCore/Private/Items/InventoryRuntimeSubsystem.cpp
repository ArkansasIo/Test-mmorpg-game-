#include "Items/InventoryRuntimeSubsystem.h"

bool UInventoryRuntimeSubsystem::AddItem(FName ItemId, int32 Quantity)
{
    if (ItemId.IsNone() || Quantity <= 0)
    {
        return false;
    }

    for (FInventoryEntry& Entry : Items)
    {
        if (Entry.ItemId == ItemId)
        {
            Entry.Quantity += Quantity;
            return true;
        }
    }

    FInventoryEntry Entry;
    Entry.ItemId = ItemId;
    Entry.Quantity = Quantity;
    Items.Add(MoveTemp(Entry));
    return true;
}
