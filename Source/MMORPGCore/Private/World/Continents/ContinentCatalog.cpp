#include "World/Continents/ContinentCatalog.h"

TArray<FContinentDefinition> UContinentCatalog::GetInitialContinents()
{
    return {
        { EWorldContinent::Aurelia, TEXT("Aurelia"), FText::FromString(TEXT("Aurelia")), 25.0f, { TEXT("GreenwardFrontier"), TEXT("AurelianHeartlands"), TEXT("WatcherCoast") } },
        { EWorldContinent::Varkhora, TEXT("Varkhora"), FText::FromString(TEXT("Varkhora")), 20.0f, { TEXT("Frostmarch"), TEXT("HighstoneExpanse"), TEXT("IronwindValley") } },
        { EWorldContinent::Elyndra, TEXT("Elyndra"), FText::FromString(TEXT("Elyndra")), 20.0f, { TEXT("Elderwood"), TEXT("MoonlitVale"), TEXT("Silvergrove") } },
        { EWorldContinent::Drakor, TEXT("Drakor"), FText::FromString(TEXT("Drakor")), 20.0f, { TEXT("AshenReach"), TEXT("RedDuneSea"), TEXT("Emberfall") } },
        { EWorldContinent::Nyxara, TEXT("Nyxara"), FText::FromString(TEXT("Nyxara")), 15.0f, { TEXT("VeiledFrontier"), TEXT("Nightsea"), TEXT("StarfallWastes") } }
    };
}
