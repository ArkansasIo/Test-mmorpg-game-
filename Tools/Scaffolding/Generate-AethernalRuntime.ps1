param(
    [string]$Root = "Source/MMORPGCore",
    [switch]$CreateCpp
)

$domains = @(
    'World','Characters','Races','Classes','Stats','Combat','Abilities','Items','Inventory','Equipment','Quests','NPC','AI','Dungeons','Trials','Raids','Professions','Social','Guilds','PvP','Economy','Progression','Cinematic','Traversal','UI','Networking','Persistence','Lua'
)

foreach ($domain in $domains) {
    $public = Join-Path $Root "Public/$domain"
    $private = Join-Path $Root "Private/$domain"
    New-Item -ItemType Directory -Force -Path $public,$private | Out-Null

    if ($CreateCpp) {
        $safe = ($domain -replace '[^A-Za-z0-9]', '')
        $header = @"
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "${safe}RuntimeSubsystem.generated.h"

UCLASS()
class MMORPGCORE_API U${safe}RuntimeSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintPure, Category="AethernalAurelia|$domain")
    bool IsReady() const { return bReady; }

    UFUNCTION(BlueprintCallable, Category="AethernalAurelia|$domain")
    void InitializeRuntime() { bReady = true; }

private:
    UPROPERTY()
    bool bReady = false;
};
"@
        $cpp = @"
#include "${domain}/${safe}RuntimeSubsystem.h"
"@
        Set-Content -Encoding UTF8 -Path (Join-Path $public "${safe}RuntimeSubsystem.h") -Value $header
        Set-Content -Encoding UTF8 -Path (Join-Path $private "${safe}RuntimeSubsystem.cpp") -Value $cpp
    }
}

Write-Host "Aethernal Aurelia runtime structure generated under $Root"
