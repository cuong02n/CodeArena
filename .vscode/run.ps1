# CodeArena - build & run the active .cpp file.
#   - compiles with g++ (C++17)
#   - runs from the project root so the code's freopen("input.txt")/("output.txt") resolve there
#   - prints output.txt to the terminal
#   - deletes the temp .exe afterwards (no clutter in the repo)
param(
    [Parameter(Mandatory = $true)][string]$Source
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot          # .vscode -> project root
$exe  = Join-Path $env:TEMP 'codearena_run.exe'   # outside the repo; overwritten every run

function Get-Gxx {
    $c = Get-Command g++ -ErrorAction SilentlyContinue
    if ($c) { return $c.Source }
    # Fallback: locate WinLibs/MSYS2 g++ even if PATH hasn't refreshed yet
    foreach ($base in @(
            "$env:LOCALAPPDATA\Microsoft\WinGet\Packages",
            'C:\msys64\ucrt64\bin',
            'C:\msys64\mingw64\bin')) {
        if (Test-Path $base) {
            $hit = Get-ChildItem $base -Filter g++.exe -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
            if ($hit) { return $hit.FullName }
        }
    }
    throw "g++ not found. Reload VS Code (Ctrl+Shift+P > Reload Window) after installing the compiler."
}

$gxx = Get-Gxx

# --- compile (-static => self-contained exe, no mingw DLLs / PATH needed) ---
& $gxx -std=gnu++17 -O2 -static -Wall -Wextra $Source -o $exe
if ($LASTEXITCODE -ne 0) { Write-Host "== compile failed ==" -ForegroundColor Red; exit 1 }

# --- run (cwd = project root -> input.txt / output.txt live at the root) ---
Push-Location $root
try { & $exe; $code = $LASTEXITCODE } finally { Pop-Location }

# --- show output.txt ---
$out = Join-Path $root 'output.txt'
Write-Host "`n----- output.txt -----" -ForegroundColor Cyan
if (Test-Path $out) { Get-Content $out }
Write-Host "----------------------`n" -ForegroundColor Cyan
Write-Host "exit code: $code"

# --- clean up ---
Remove-Item -Force -ErrorAction SilentlyContinue $exe
