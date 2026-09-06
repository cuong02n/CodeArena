# CodeArena - 1-Click Setup & Environment Initialization
# Chay script nay de tu dong thiet lap toan bo moi truong sau khi cai lai Windows.

$ErrorActionPreference = 'Stop'

Write-Host ""
Write-Host "=======================================================" -ForegroundColor Cyan
Write-Host "         CodeArena - Setup & Environment Init           " -ForegroundColor Cyan
Write-Host "=======================================================" -ForegroundColor Cyan
Write-Host ""

$root = $PSScriptRoot
if (-not $root) { $root = Get-Location }

# ----------------------------------------------------
# 1. Kiem tra C++ Compiler (g++)
# ----------------------------------------------------
Write-Host "[1/5] Kiem tra C++ Compiler (g++)..." -ForegroundColor Yellow

function Find-Gxx {
    $candidates = @(
        'D:\SDK\mingw64\bin\g++.exe',
        'D:\SDK\winlibs\mingw64\bin\g++.exe',
        'C:\msys64\ucrt64\bin\g++.exe',
        'C:\msys64\mingw64\bin\g++.exe'
    )
    foreach ($p in $candidates) {
        if (Test-Path $p) { return $p }
    }

    $c = Get-Command g++ -ErrorAction SilentlyContinue
    if ($c) { return $c.Source }

    $searchRoots = @('D:\SDK\mingw64', 'D:\SDK\winlibs', 'D:\SDK', "$env:LOCALAPPDATA\Microsoft\WinGet\Packages")
    foreach ($base in $searchRoots) {
        if (Test-Path $base) {
            $hit = Get-ChildItem $base -Filter g++.exe -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
            if ($hit) { return $hit.FullName }
        }
    }
    return $null
}

$gxxPath = Find-Gxx

if (-not $gxxPath) {
    Write-Host "  -> Khong tim thay g++. Dang thu cai dat qua winget..." -ForegroundColor Yellow
    if (Get-Command winget -ErrorAction SilentlyContinue) {
        try {
            winget install --id BrechtSanders.WinLibs.POSIX.UCRT --scope user --location D:\SDK\winlibs --accept-source-agreements --accept-package-agreements
            $gxxPath = Find-Gxx
        } catch {
            Write-Host "  -> Loi khi chay winget." -ForegroundColor Red
        }
    }
}

if (-not $gxxPath) {
    Write-Host ""
    Write-Host "[ERROR] Khong tim thay hoac chua cai dat g++ compiler!" -ForegroundColor Red
    Write-Host "Vui long cai dat WinLibs vao D:\SDK\mingw64 hoac chay lenh:" -ForegroundColor Yellow
    Write-Host "winget install --id BrechtSanders.WinLibs.POSIX.UCRT --scope user --location D:\SDK\winlibs" -ForegroundColor White
    Write-Host ""
    exit 1
}

$gxxVersion = (& $gxxPath --version | Select-Object -First 1)
Write-Host "  [OK] Da tim thay: $gxxPath" -ForegroundColor Green
Write-Host "       Phien ban: $gxxVersion" -ForegroundColor Gray

# ----------------------------------------------------
# 2. Cau hinh bien moi truong PATH (User PATH)
# ----------------------------------------------------
Write-Host ""
Write-Host "[2/5] Cau hinh User PATH..." -ForegroundColor Yellow
$binDir = Split-Path -Parent $gxxPath
$userPath = [Environment]::GetEnvironmentVariable("Path", "User")
$pathEntries = if ($userPath) { $userPath -split ';' | Where-Object { $_ -ne "" } } else { @() }

if ($pathEntries -notcontains $binDir) {
    $newUserPath = "$binDir;" + ($pathEntries -join ";")
    [Environment]::SetEnvironmentVariable("Path", $newUserPath, "User")
    Write-Host "  [OK] Da them $binDir vao User PATH." -ForegroundColor Green
} else {
    Write-Host "  [OK] $binDir da co san trong User PATH." -ForegroundColor Green
}

# ----------------------------------------------------
# 3. Chuan hoa Snippets (.vscode/competitive.code-snippets)
# ----------------------------------------------------
Write-Host ""
Write-Host "[3/5] Cap nhat Snippets..." -ForegroundColor Yellow
$snippetTxt = Join-Path $root ".vscode\snippet.txt"
$snippetFile = Join-Path $root ".vscode\competitive.code-snippets"

if (Test-Path $snippetTxt) {
    try {
        $raw = Get-Content -Raw $snippetTxt
        $clean = [System.Text.RegularExpressions.Regex]::Replace($raw, ',\s*([\]}])', '$1')
        $data = $clean | ConvertFrom-Json
        
        foreach ($prop in $data.PSObject.Properties) {
            $item = $prop.Value
            if (-not $item.scope) {
                Add-Member -InputObject $item -NotePropertyName "scope" -NotePropertyValue "cpp"
            }
            if ($prop.Name -eq "codeArena (test case )") {
                $item.prefix = @("cp", "code_t")
            }
        }
        $jsonStr = ConvertTo-Json -InputObject $data -Depth 10
        [System.IO.File]::WriteAllText($snippetFile, $jsonStr, [System.Text.Encoding]::UTF8)
        Write-Host "  [OK] Da tao/cap nhat $snippetFile" -ForegroundColor Green
    } catch {
        Write-Host "  [WARN] Khong the convert snippet.txt: $_" -ForegroundColor Yellow
    }
} else {
    Write-Host "  [INFO] $snippetFile da san sang." -ForegroundColor Gray
}

# ----------------------------------------------------
# 4. Cai dat Keybindings (Ctrl+F9 / Ctrl+F8)
# ----------------------------------------------------
Write-Host ""
Write-Host "[4/5] Cai dat phim tat (Keybindings)..." -ForegroundColor Yellow
$installKeybindingsScript = Join-Path $root ".vscode\install-keybindings.ps1"
if (Test-Path $installKeybindingsScript) {
    & powershell -NoProfile -ExecutionPolicy Bypass -File $installKeybindingsScript
} else {
    Write-Host "  [WARN] Khong tim thay $installKeybindingsScript" -ForegroundColor Yellow
}

# ----------------------------------------------------
# 5. Kiem tra Compile & Run thuc te
# ----------------------------------------------------
Write-Host ""
Write-Host "[5/5] Kiem tra bien dich va chay thu..." -ForegroundColor Yellow
$testCpp = Join-Path $env:TEMP "codearena_test.cpp"
$testExe = Join-Path $env:TEMP "codearena_test.exe"

$testCode = @"
#include <iostream>
int main() {
    std::cout << "CodeArena Test OK" << std::endl;
    return 0;
}
"@

[System.IO.File]::WriteAllText($testCpp, $testCode, [System.Text.Encoding]::UTF8)

try {
    & $gxxPath -std=gnu++17 -O2 -static -Wall -Wextra $testCpp -o $testExe
    if ($LASTEXITCODE -eq 0) {
        $testOut = (& $testExe)
        if ($testOut -match "CodeArena Test OK") {
            Write-Host "  [OK] Bien dich va chay thu thanh cong!" -ForegroundColor Green
        } else {
            Write-Host "  [WARN] Chay thu khong dung output mong doi." -ForegroundColor Yellow
        }
    } else {
        Write-Host "  [FAIL] Bien dich thu nghiem that bai." -ForegroundColor Red
    }
} catch {
    Write-Host "  [FAIL] Loi: $_" -ForegroundColor Red
} finally {
    Remove-Item -Force -ErrorAction SilentlyContinue $testCpp, $testExe
}

# ----------------------------------------------------
# Hoan tat
# ----------------------------------------------------
Write-Host ""
Write-Host "=======================================================" -ForegroundColor Cyan
Write-Host "               THIET LAP HOAN TAT THANH CONG!          " -ForegroundColor Green
Write-Host "=======================================================" -ForegroundColor Cyan
Write-Host "Cac phim tat va tinh nang san sang su dung:" -ForegroundColor White
Write-Host "  - Ctrl+F9 (hoac Ctrl+Shift+B) : Compile & Run file .cpp dang mo (doc tu input.txt -> output.txt)" -ForegroundColor Gray
Write-Host "  - Ctrl+F8                     : Tao nhanh bai moi (nhap ID contest & chu cai bai)" -ForegroundColor Gray
Write-Host "  - cp / code_t + Tab           : Chen template giai bai" -ForegroundColor Gray
Write-Host ""
