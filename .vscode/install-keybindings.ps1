# CodeArena - Install CP keybindings to User keybindings.json
param(
    [string]$Editor = ""
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$sourceFile = Join-Path $PSScriptRoot "keybindings.json"

if (-not (Test-Path $sourceFile)) {
    Write-Host "Source keybindings file not found: $sourceFile" -ForegroundColor Red
    exit 1
}

$newBindings = Get-Content -Raw $sourceFile | ConvertFrom-Json

$editorDirs = @(
    "Antigravity IDE",
    "Code",
    "Cursor",
    "VSCodium",
    "Code - Insiders"
)

if ($Editor -ne "") {
    $editorDirs = @($Editor)
}

$updatedCount = 0

foreach ($ed in $editorDirs) {
    $userDir = Join-Path $env:APPDATA "$ed\User"
    if (Test-Path (Join-Path $env:APPDATA $ed)) {
        if (-not (Test-Path $userDir)) {
            New-Item -ItemType Directory -Force -Path $userDir | Out-Null
        }

        $targetFile = Join-Path $userDir "keybindings.json"
        $currentBindings = @()

        if (Test-Path $targetFile) {
            # Backup
            Copy-Item $targetFile "$targetFile.bak" -Force

            try {
                $raw = Get-Content -Raw $targetFile
                # Remove single-line comments // ...
                $rawClean = [System.Text.RegularExpressions.Regex]::Replace($raw, '(?m)^\s*//.*$', '')
                # Remove multi-line comments /* ... */
                $rawClean = [System.Text.RegularExpressions.Regex]::Replace($rawClean, '/\*[\s\S]*?\*/', '')
                if (-not [string]::IsNullOrWhiteSpace($rawClean)) {
                    $currentBindings = $rawClean | ConvertFrom-Json
                }
            } catch {
                Write-Host "Warning: Could not parse existing $targetFile. Overwriting with clean configuration." -ForegroundColor Yellow
                $currentBindings = @()
            }
        }

        # Filter out old / conflicting CP bindings (Ctrl+F9, Ctrl+F8)
        $filtered = @()
        if ($currentBindings) {
            foreach ($b in $currentBindings) {
                $k = if ($b.key) { $b.key.ToLower().Trim() } else { "" }
                if ($k -ne "ctrl+f9" -and $k -ne "ctrl+f8") {
                    $filtered += $b
                }
            }
        }

        # Merge new bindings
        foreach ($nb in $newBindings) {
            $filtered += $nb
        }

        # Save back
        $jsonOut = ConvertTo-Json -InputObject $filtered -Depth 10
        [System.IO.File]::WriteAllText($targetFile, $jsonOut, [System.Text.Encoding]::UTF8)
        Write-Host "Successfully installed CP keybindings for $ed -> $targetFile" -ForegroundColor Green
        $updatedCount++
    }
}

if ($updatedCount -eq 0) {
    Write-Host "No supported editor directories found in $env:APPDATA" -ForegroundColor Yellow
}
