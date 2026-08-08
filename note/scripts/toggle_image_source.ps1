# toggle_image_source.ps1
#
# Switch image references in DaVinci note markdown files between:
#   1) local relative paths    e.g. image/DaVinci_Mcu/1785902033896.png
#   2) image bed / CDN urls    e.g. https://cdn.jsdelivr.net/gh/xiongGithub1/picGoUpload/image/20260805115538.png
#
# Each image slot keeps TWO lines (your current convention):
#   <!-- ![local-name](local-path) -->
#   ![cdn-name](https://cdn.jsdelivr.net/gh/.../cdn-name.png)
# One line is ACTIVE, the other is COMMENTED as backup.
# This script flips every pair so the selected source becomes active.
#
# Usage (run from last364\note\scripts):
#   powershell -ExecutionPolicy Bypass -File .\toggle_image_source.ps1 -Mode cdn    # switch to image bed (CDN)
#   powershell -ExecutionPolicy Bypass -File .\toggle_image_source.ps1 -Mode local  # switch to local images
#   powershell -ExecutionPolicy Bypass -File .\toggle_image_source.ps1 -Mode local -Path ..\Config\DaVinci_Modules\DaVinci_Mcu.md
#   powershell -ExecutionPolicy Bypass -File .\toggle_image_source.ps1 -DryRun      # preview only, no file is written
#
# Notes:
#   - Default: scans all *.md under the folder that contains this script.
#   - Slots that have only one form (local-only or cdn-only) are reported at the
#     end but are NOT modified, so you can add the missing counterpart manually.
#   - Old placeholder comment blocks (<!-- 自插图片: ... -->) are ignored.

param(
    [ValidateSet('local','cdn')]
    [string]$Mode = 'cdn',
    [string]$Path = '',
    [switch]$DryRun,
    [int]$Window = 6,
    [string]$CdnPrefix = 'https://cdn.jsdelivr.net/gh/xiongGithub1/picGoUpload/image/'
)

$ErrorActionPreference = 'Stop'
$utf8NoBom = New-Object System.Text.UTF8Encoding($false)

if ($Path) {
    $mdFiles = @(Get-Item -LiteralPath $Path -ErrorAction Stop | Where-Object { $_.Extension -eq '.md' })
} else {
    # 脚本位于 note\scripts 时，默认扫描整个 note 目录；否则扫描脚本所在目录
    $scanRoot = if ((Split-Path $PSScriptRoot -Leaf) -eq 'scripts') { Split-Path $PSScriptRoot -Parent } else { $PSScriptRoot }
    $mdFiles = @(Get-ChildItem -Path $scanRoot -Recurse -Filter *.md)
}

function Test-ImageLine {
    param([string]$Line)
    return $Line -match '!\[[^\]]*\]\([^)]+\)'
}

function Get-ImageInfo {
    param([string]$Line)
    $m = [regex]::Match($Line, '!\[([^\]]*)\]\(([^)]+)\)')
    if (-not $m.Success) { return $null }
    $target = $m.Groups[2].Value
    $isLocal = ($target -notmatch '^https?://') -and ($target -match '\.(png|jpe?g|gif|webp)$')
    $isCdn = $target.StartsWith($CdnPrefix, [System.StringComparison]::OrdinalIgnoreCase)
    if (-not ($isLocal -or $isCdn)) { return $null }
    return [pscustomobject]@{
        Alt     = $m.Groups[1].Value
        Target  = $target
        IsLocal = $isLocal
        IsCdn   = $isCdn
    }
}

function Format-ImageLine {
    param([string]$Alt, [string]$Target, [bool]$Commented)
    $core = "![$Alt]($Target)"
    if ($Commented) { return "<!-- $core -->" }
    return $core
}

$totalPairs = 0
$allUnpaired = New-Object System.Collections.Generic.List[string]

foreach ($file in $mdFiles) {
    $rawBytes = [System.IO.File]::ReadAllBytes($file.FullName)
    $hasBom = ($rawBytes.Length -ge 3 -and $rawBytes[0] -eq 0xEF -and $rawBytes[1] -eq 0xBB -and $rawBytes[2] -eq 0xBF)
    $rawText = [System.Text.Encoding]::UTF8.GetString($rawBytes)
    if ($hasBom) { $rawText = $rawText.Substring(1) }
    $eol = if ($rawText.Contains("`r`n")) { "`r`n" } else { "`n" }
    $lines = New-Object System.Collections.Generic.List[string]
    foreach ($l in ($rawText -split "`n")) { $lines.Add($l.TrimEnd("`r")) }

    # 1) collect image slots (skip code fences and multi-line placeholder comments)
    $slots = New-Object System.Collections.Generic.List[object]
    $inCode = $false
    $inBlockComment = $false
    for ($i = 0; $i -lt $lines.Count; $i++) {
        $line = $lines[$i]
        $trim = $line.Trim()
        if ($trim.StartsWith('```')) { $inCode = -not $inCode; continue }
        if ($inCode) { continue }

        $hasOpen = $line -match '<!--'
        $hasClose = $line -match '-->'

        if ($inBlockComment) {
            if ($hasClose) { $inBlockComment = $false }
            continue
        }
        if ($hasOpen -and -not $hasClose) { $inBlockComment = $true; continue }
        if (-not (Test-ImageLine $line)) { continue }

        $commented = $hasOpen -and $hasClose
        $info = Get-ImageInfo $line
        if ($info) {
            $slots.Add([pscustomobject]@{
                Index     = $i
                Alt       = $info.Alt
                Target    = $info.Target
                IsLocal   = $info.IsLocal
                IsCdn     = $info.IsCdn
                Commented = $commented
                Raw       = $line
            })
        }
    }

    # 2) greedy nearest-neighbour pairing: local <-> cdn
    #    (one line must be active; both-active pairs are treated as duplicates and fixed)
    $paired = @{}
    $pairs = New-Object System.Collections.Generic.List[object]
    for ($i = 0; $i -lt $slots.Count; $i++) {
        $a = $slots[$i]
        if ($paired.ContainsKey($a.Index)) { continue }
        $best = $null
        $bestDist = [int]::MaxValue
        for ($j = $i + 1; $j -lt $slots.Count; $j++) {
            $b = $slots[$j]
            $dist = $b.Index - $a.Index
            if ($dist -gt $Window) { break }
            if ($paired.ContainsKey($b.Index)) { continue }
            if (($a.IsLocal -ne $b.IsLocal) -and -not ($a.Commented -and $b.Commented)) {
                if ($dist -lt $bestDist) { $best = $b; $bestDist = $dist }
            }
        }
        if ($best) {
            $paired[$a.Index] = $true
            $paired[$best.Index] = $true
            $pairs.Add([pscustomobject]@{ A = $a; B = $best })
        }
    }

    # 3) rewrite paired lines
    $changed = $false
    foreach ($p in $pairs) {
        $localSlot = if ($p.A.IsLocal) { $p.A } else { $p.B }
        $cdnSlot   = if ($p.A.IsCdn)   { $p.A } else { $p.B }
        $lines[$localSlot.Index] = Format-ImageLine $localSlot.Alt $localSlot.Target ($Mode -eq 'cdn')
        $lines[$cdnSlot.Index]   = Format-ImageLine $cdnSlot.Alt   $cdnSlot.Target   ($Mode -eq 'local')
        $changed = $true
    }
    $totalPairs += $pairs.Count

    # 4) report unpaired image lines (never modified)
    foreach ($s in $slots) {
        if (-not $paired.ContainsKey($s.Index)) {
            $kind = if ($s.IsLocal) { 'local' } else { 'cdn' }
            $state = if ($s.Commented) { 'commented' } else { 'active' }
            $allUnpaired.Add("$($file.Name):$($s.Index+1) [$kind/$state] $($s.Raw.Trim())")
        }
    }

    if ($DryRun) {
        if ($pairs.Count -gt 0) { Write-Host "[$($file.Name)] would toggle $($pairs.Count) pair(s) -> mode=$Mode" }
    } elseif ($changed) {
        $text = [string]::Join($eol, $lines)
        $writeEncoding = if ($hasBom) { New-Object System.Text.UTF8Encoding($true) } else { $utf8NoBom }
        [System.IO.File]::WriteAllText($file.FullName, $text, $writeEncoding)
        Write-Host "[$($file.Name)] toggled $($pairs.Count) pair(s) -> mode=$Mode"
    }
}

Write-Host "----------------------------------------"
Write-Host "Total pairs processed: $totalPairs (mode=$Mode)"
if ($allUnpaired.Count -gt 0) {
    Write-Host "Unpaired image lines (NOT modified, add the missing counterpart to enable switching):"
    $allUnpaired | ForEach-Object { Write-Host "  $_" }
} else {
    Write-Host "No unpaired image lines."
}
