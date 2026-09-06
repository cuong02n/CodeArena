# CLAUDE.md

Guidance for Claude Code when working in this repository.

## What this repo is

**CodeArena** — a personal competitive-programming solutions repo, written in **C++17**,
mostly **Codeforces**. It is a collection of standalone solution files, not an application.
Each `.cpp` has its own `main()` and is compiled/run independently.

## Layout

| Path | Contents |
|------|----------|
| `codeforces/working/<id>/<id><problem>.cpp` | Problems currently being solved (e.g. `working/2242/2242A.cpp`) |
| `codeforces/archive/<id>/<id><problem>.cpp` | ~277 contests of solved problems |
| `algorithm/` | Reference algorithm implementations (merge/quick sort, Fenwick) |
| `leetcode/` | Mostly empty |
| `.vscode/` | Build/run tasks, snippets, config (see below) |
| `input.txt` / `output.txt` | Local stdin/stdout for the active run (at repo root) |

**File naming convention:** `<contestId>/<contestId><ProblemLetter>.cpp`, problem letter uppercase
(e.g. contest 2242 problem A → `codeforces/working/2242/2242A.cpp`).

## Build & run (the main workflow)

Solutions are built and run through a VS Code task — **not** CMake.

- **Shortcut:** `Ctrl+F9` (or `Ctrl+Shift+B`) with a `.cpp` focused → compile + run the active file.
- Defined in `.vscode/tasks.json` → runs `.vscode/run.ps1`, which:
  1. compiles the active file with `g++ -std=gnu++17 -O2 -static -Wall -Wextra`,
  2. runs it **from the repo root** so the code's `freopen("input.txt")/("output.txt")` resolve to the root files,
  3. prints `output.txt` to the terminal,
  4. deletes the temp exe (kept at `%TEMP%\codearena_run.exe`, never committed to the repo).

To run manually (same as the task):
```
powershell -NoProfile -ExecutionPolicy Bypass -File .vscode/run.ps1 -Source <path-to.cpp>
```

### Compiler / environment gotchas
- Compiler is **WinLibs g++** (POSIX/UCRT), installed **on D:** at `D:\SDK\mingw64`.
  Binary: `D:\SDK\mingw64\bin\g++.exe` — `run.ps1` checks this path first, before PATH.
- It is a *portable (zip)* package: ~260 MB download that expands to ~11.7k files / 913 MB, so a
  (re)install takes several minutes. It is **not** guaranteed to be on PATH — do not rely on
  `Get-Command g++`.
- **`-static` is required.** winget only shims the commands onto PATH, not the runtime DLLs,
  so a dynamically-linked exe crashes with `0xC0000135 STATUS_DLL_NOT_FOUND` (exit `-1073741515`).
  `run.ps1` always compiles `-static` and has a fallback that locates `g++` under WinGet Packages
  even before a fresh shell picks up the new PATH.

## Creating a new problem

Two ways, both give the standard template already wired for the run workflow:

1. **Generator task:** Command Palette → *Run Task* → **New CP problem** → enter contest id + problem
   letter. Creates `codeforces/working/<id>/<id><letter>.cpp` (via `.vscode/newcp.ps1`) and opens it.
2. **Snippet:** in a `.cpp`, type `cp` (or `code_t`) + `Tab`. Snippets live in
   `.vscode/competitive.code-snippets` (converted from the older, non-loading `.vscode/snippet.txt`);
   also includes `DSU`, ` Segment Tree`, `kadane`, `is_prime`, graph classes, etc.

## Solution template shape

Standard structure (see `codeforces/working/2242/2242A.cpp`):
- `#include <bits/stdc++.h>`, `using ll = long long`, debug `operator<<` for `pair`/`tuple`.
- `void solve()` handles one test case; `main()` reads `t` then loops `solve()`.
- I/O is guarded: `#ifndef ONLINE_JUDGE` redirects stdin/stdout to `input.txt`/`output.txt` for local
  runs; on the judge (where `ONLINE_JUDGE` is defined) it uses real stdin/stdout. **Keep this guard**
  when editing/creating solutions, or the local run workflow breaks.

## Removed / stale

The old CMake + CLion build (`CMakeLists.txt`, `cmake-build-debug/`) has been **removed** — it was a
leftover from a previous machine (MSYS2 + CLion) and is not part of the current workflow.
`.vscode/launch.json` and `.idea/` are remaining IDE leftovers from that setup and are unused; do not
rely on or "fix" them unless explicitly asked.
