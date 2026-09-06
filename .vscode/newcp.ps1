# CodeArena - Generate a new competitive programming solution file
param(
    [Parameter(Mandatory = $true)][string]$Contest,
    [Parameter(Mandatory = $true)][string]$Problem
)

$ErrorActionPreference = 'Stop'

$Contest = $Contest.Trim()
$Problem = $Problem.Trim().ToUpper()

if ([string]::IsNullOrWhiteSpace($Contest) -or [string]::IsNullOrWhiteSpace($Problem)) {
    Write-Host "Contest and Problem cannot be empty." -ForegroundColor Red
    exit 1
}

$root = Split-Path -Parent $PSScriptRoot
$workingDir = Join-Path $root "codeforces\working\$Contest"
$targetFile = Join-Path $workingDir "$Contest$Problem.cpp"

if (-not (Test-Path $workingDir)) {
    New-Item -ItemType Directory -Force -Path $workingDir | Out-Null
}

$template = @"
/*
    author : cuong2905say
    problem: Codeforces $Contest$Problem
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> A) {
    os << "{ " << A.first << ", " << A.second << " }";
    return os;
}

int MOD = 1e9 + 7;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
"@

if (-not (Test-Path $targetFile)) {
    Set-Content -Path $targetFile -Value $template -Encoding utf8
    Write-Host "Created: $targetFile" -ForegroundColor Green
} else {
    Write-Host "File already exists: $targetFile" -ForegroundColor Yellow
}

# Try opening in current IDE
if (Get-Command antigravity -ErrorAction SilentlyContinue) {
    & antigravity $targetFile
} elseif (Get-Command code -ErrorAction SilentlyContinue) {
    & code $targetFile
}
