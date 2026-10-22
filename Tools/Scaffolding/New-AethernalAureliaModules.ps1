[CmdletBinding()]
param(
    [string]$RepoRoot = (Resolve-Path (Join-Path $PSScriptRoot "../..")),
    [switch]$CreateCppStubs,
    [switch]$CreateBlueprintFolders,
    [switch]$CreateDataFolders,
    [switch]$CreateLuaFolders
)

$ErrorActionPreference = 'Stop'
$manifestPath = Join-Path $PSScriptRoot 'AethernalModuleManifest.json'
$manifest = Get-Content -Raw $manifestPath | ConvertFrom-Json

function Ensure-Directory([string]$Path) {
    if (-not (Test-Path -LiteralPath $Path)) {
        New-Item -ItemType Directory -Path $Path -Force | Out-Null
    }
}

foreach ($domainProperty in $manifest.domains.PSObject.Properties) {
    $domain = $domainProperty.Name
    $submodules = @($domainProperty.Value)
    $publicRoot = Join-Path $RepoRoot "Source/MMORPGCore/Public/$domain"
    $privateRoot = Join-Path $RepoRoot "Source/MMORPGCore/Private/$domain"
    Ensure-Directory $publicRoot
    Ensure-Directory $privateRoot

    foreach ($submodule in $submodules) {
        $publicDir = Join-Path $publicRoot $submodule
        $privateDir = Join-Path $privateRoot $submodule
        Ensure-Directory $publicDir
        Ensure-Directory $privateDir

        if ($CreateCppStubs) {
            $className = "${submodule}RuntimeSubsystem"
            $header = @"
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "${className}.generated.h"

UCLASS()
class MMORPGCORE_API U$className : public UGameInstanceSubsystem
{
    GENERATED_BODY()
};
"@
            $source = @"
#include "${domain}/${submodule}/${className}.h"
"@
            Set-Content -Path (Join-Path $publicDir "$className.h") -Value $header -Encoding UTF8
            Set-Content -Path (Join-Path $privateDir "$className.cpp") -Value $source -Encoding UTF8
        }
    }
}

if ($CreateBlueprintFolders) {
    foreach ($domainProperty in $manifest.domains.PSObject.Properties) {
        Ensure-Directory (Join-Path $RepoRoot "Content/AethernalAurelia/Blueprints/$($domainProperty.Name)")
    }
}

if ($CreateDataFolders) {
    foreach ($domainProperty in $manifest.domains.PSObject.Properties) {
        Ensure-Directory (Join-Path $RepoRoot "Data/$($domainProperty.Name)")
    }
}

if ($CreateLuaFolders) {
    foreach ($domainProperty in $manifest.domains.PSObject.Properties) {
        Ensure-Directory (Join-Path $RepoRoot "Lua/$($domainProperty.Name)")
    }
}

Write-Host "Aethernal Aurelia module scaffolding complete." -ForegroundColor Green
Write-Host "Repo: $RepoRoot"
Write-Host "Domains: $($manifest.domains.PSObject.Properties.Count)"
