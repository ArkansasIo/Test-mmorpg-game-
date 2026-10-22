[CmdletBinding()]
param([string]$RepoRoot = (Resolve-Path (Join-Path $PSScriptRoot "../..")))

$script = Join-Path $PSScriptRoot 'New-AethernalAureliaModules.ps1'

& $script -RepoRoot $RepoRoot -CreateBlueprintFolders -CreateDataFolders -CreateLuaFolders

Write-Host "Source folders, Blueprint folders, Data folders, and Lua folders are ready." -ForegroundColor Cyan
Write-Host "Use -CreateCppStubs separately when you want generated C++ class shells." -ForegroundColor Yellow
