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
    # Direct hits first (cheap) - the WinLibs install lives on D:\SDK
    foreach ($p in @(
            'D:\SDK\mingw64\bin\g++.exe',
            'D:\SDK\winlibs\mingw64\bin\g++.exe',
            'C:\msys64\ucrt64\bin\g++.exe',
            'C:\msys64\mingw64\bin\g++.exe')) {
        if (Test-Path $p) { return $p }
    }
    $c = Get-Command g++ -ErrorAction SilentlyContinue
    if ($c) { return $c.Source }
    # Fallback: search the install roots, in case the layout/version changed
    foreach ($base in @(
            'D:\SDK\mingw64',
            'D:\SDK\winlibs',
            'D:\SDK',
            "$env:LOCALAPPDATA\Microsoft\WinGet\Packages")) {
        if (Test-Path $base) {
            $hit = Get-ChildItem $base -Filter g++.exe -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
            if ($hit) { return $hit.FullName }
        }
    }
    throw "g++ not found. Install it with:  winget install --id BrechtSanders.WinLibs.POSIX.UCRT --scope user --location D:\SDK\winlibs   (then Ctrl+Shift+P > Reload Window)"
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
