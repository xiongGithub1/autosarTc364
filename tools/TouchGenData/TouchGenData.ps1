# Refresh Appl\GenData *.c / *.h timestamps to current time.
# Usage:
#   .\TouchGenData.ps1
#   .\TouchGenData.ps1 -ProjectRoot "E:\workFiles\TC367\TC367\workspace\last364"

param(
    [string]$ProjectRoot = ""
)

function Resolve-ProjectRoot {
    param([string]$Root)

    $candidates = @()
    if ($Root -ne "") {
        $candidates += (Resolve-Path -LiteralPath $Root -ErrorAction SilentlyContinue).Path
    }

    $candidates += (Get-Location).Path
    $candidates += Split-Path -Parent $PSScriptRoot
    $candidates += Split-Path -Parent (Split-Path -Parent $PSScriptRoot)

    foreach ($candidate in ($candidates | Select-Object -Unique)) {
        if ($null -eq $candidate) { continue }
        $genData = Join-Path $candidate "Appl\GenData"
        if (Test-Path -LiteralPath $genData) {
            return @{
                ProjectRoot = $candidate
                GenDataPath = $genData
            }
        }
    }

    return $null
}

$resolved = Resolve-ProjectRoot -Root $ProjectRoot
if ($null -eq $resolved) {
    Write-Error "Cannot find Appl\GenData. Pass -ProjectRoot explicitly."
    exit 1
}

$now = Get-Date
$files = Get-ChildItem -Path $resolved.GenDataPath -Recurse -Include *.c,*.h -File
foreach ($file in $files) {
    $file.LastWriteTime = $now
}

Write-Host "TouchGenData - refresh GenData .c/.h timestamps"
Write-Host "Project root : $($resolved.ProjectRoot)"
Write-Host "GenData path : $($resolved.GenDataPath)"
Write-Host "Timestamp    : $($now.ToString('yyyy-MM-dd HH:mm:ss'))"
Write-Host "Files updated: $($files.Count)"
Write-Host "Done."
