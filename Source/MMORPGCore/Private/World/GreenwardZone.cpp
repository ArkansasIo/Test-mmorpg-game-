#include "World/GreenwardZone.h"
#include "Engine/World.h"
#include "Misc/Paths.h"

void UGreenwardZone::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    Landmarks.Reset();

    auto AddLandmark = [this](const FName Id, const EGreenwardArea Area, const FVector Location, const bool bMajor)
    {
        FGreenwardLandmark Landmark;
        Landmark.Id = Id;
        Landmark.Area = Area;
        Landmark.Location = Location;
        Landmark.bMajorLandmark = bMajor;
        Landmarks.Add(Landmark);
    };

    AddLandmark(TEXT("GreenwardVillage"), EGreenwardArea::Village, FVector(0, 0, 0), true);
    AddLandmark(TEXT("Farmland"), EGreenwardArea::Farmland, FVector(1800, -900, 0), false);
    AddLandmark(TEXT("OldPinewood"), EGreenwardArea::OldPinewood, FVector(-1400, 1200, 100), true);
    AddLandmark(TEXT("WatchersRoad"), EGreenwardArea::WatchersRoad, FVector(1700, 1600, 250), false);
    AddLandmark(TEXT("OldWatchtower"), EGreenwardArea::OldWatchtower, FVector(2600, 2600, 900), true);
    AddLandmark(TEXT("HighstoneRidge"), EGreenwardArea::HighstoneRidge, FVector(1000, 3600, 1500), true);
    AddLandmark(TEXT("River"), EGreenwardArea::River, FVector(-2500, -400, -50), false);
    AddLandmark(TEXT("SouthGate"), EGreenwardArea::SouthGate, FVector(0, -3000, 0), true);
    AddLandmark(TEXT("HollowrootEntrance"), EGreenwardArea::HollowrootEntrance, FVector(-2300, 1700, -250), true);
    AddLandmark(TEXT("WorldEventClearing"), EGreenwardArea::WorldEventClearing, FVector(900, 2100, 100), true);
}

void UGreenwardZone::Deinitialize()
{
    Landmarks.Reset();
    Super::Deinitialize();
}

bool UGreenwardZone::IsGreenwardWorld() const
{
    const UWorld* World = GetWorld();
    if (!World)
    {
        return false;
    }

    return World->GetMapName().Contains(TEXT("Greenward"), ESearchCase::IgnoreCase);
}
