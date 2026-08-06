# CodeArena

Repo lời giải competitive programming cá nhân, viết bằng **C++17**, chủ yếu là **Codeforces**.

Đây không phải một application — mỗi file `.cpp` là một lời giải độc lập, có `main()` riêng,
được compile và chạy riêng lẻ.

- 277 contest trong `codeforces/archive/`, ~526 file `.cpp`
- Build/run bằng **VS Code task + g++**, không dùng CMake

---

## Phím tắt

| Phím tắt | Tác dụng |
|----------|----------|
| `Ctrl+F9` | Compile + chạy file `.cpp` đang mở (task *CP: Build & Run active file*) |
| `Ctrl+Shift+B` | Giống hệt `Ctrl+F9` — task này là default build task của workspace |
| `Ctrl+F8` | Tạo file bài mới từ template (task *New CP problem*), sẽ hỏi contest id + problem letter |
| `cp` + `Tab` | Chèn template lời giải vào file `.cpp` đang mở (snippet, alias: `code_t`) |
| `Ctrl+Shift+P` → *Run Task* | Chạy task thủ công nếu không nhớ phím tắt |

### Cài `Ctrl+F9` / `Ctrl+F8` trên máy mới

VS Code **không đọc keybindings theo workspace** (chỉ `settings.json` / `tasks.json` / snippet mới có
scope workspace), nên chỉ clone repo về là chưa đủ. Repo giữ định nghĩa ở
[.vscode/keybindings.json](.vscode/keybindings.json), chạy một lệnh để merge vào keybindings của user:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .vscode/install-keybindings.ps1
```

Hoặc: `Ctrl+Shift+P` → *Run Task* → **Install CP keybindings**.

Script `.vscode/install-keybindings.ps1`:

- merge vào `%APPDATA%\Code\User\keybindings.json`, **giữ nguyên các binding cá nhân khác**
- ghi đè binding nào đang trùng phím `ctrl+f9` / `ctrl+f8`
- backup file cũ ra `keybindings.json.bak` trước khi ghi (comment trong file cũ không được giữ lại)
- chạy lại nhiều lần vô hại (idempotent)
- đổi editor bằng `-Editor`: `Code` (mặc định), `Code - Insiders`, `Cursor`, `VSCodium`

`Ctrl+Shift+B` thì luôn hoạt động sẵn, không cần cài gì — nó là phím mặc định của VS Code cho
default build task.

---

## Cấu trúc thư mục

| Path | Nội dung |
|------|----------|
| `codeforces/working/<id>/<id><letter>.cpp` | Bài đang giải (vd: `working/2242/2242A.cpp`) |
| `codeforces/archive/<id>/<id><letter>.cpp` | Bài đã giải xong, lưu trữ theo contest |
| `algorithm/` | Cài đặt thuật toán tham khảo (merge/quick sort, Fenwick, Kadane) |
| `leetcode/` | Gần như trống |
| `.vscode/` | Task, script, snippet, keybinding, config |
| `input.txt` / `output.txt` | stdin/stdout của lần chạy hiện tại (ở **root** repo) |

**Quy ước đặt tên:** `<contestId>/<contestId><ProblemLetter>.cpp`, chữ cái bài **viết hoa**.
Ví dụ contest 2242 bài A → `codeforces/working/2242/2242A.cpp`.

---

## Workflow chạy bài

Nhấn `Ctrl+F9` khi đang focus một file `.cpp`. Task gọi `.vscode/run.ps1`, script này:

1. Compile: `g++ -std=gnu++17 -O2 -static -Wall -Wextra`
2. Chạy exe **từ root repo**, để `freopen("input.txt")` / `freopen("output.txt")` trong code
   trỏ đúng vào 2 file ở root
3. In nội dung `output.txt` ra terminal kèm exit code
4. Xoá exe tạm (nằm ở `%TEMP%\codearena_run.exe`, không bao giờ lọt vào repo)

Cách dùng thủ công (tương đương task):

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .vscode/run.ps1 -Source <đường-dẫn.cpp>
```

**Cách nhập input:** gõ input vào `input.txt` ở root repo trước khi chạy, kết quả sẽ nằm ở
`output.txt` (đồng thời được in ra terminal).

---

## Tạo bài mới

Hai cách, cả hai đều sinh ra template đã wire sẵn cho workflow chạy ở trên:

1. **Task generator** — `Ctrl+F8` (hoặc Command Palette → *Run Task* → **New CP problem**),
   nhập contest id và problem letter. Script `.vscode/newcp.ps1` tạo
   `codeforces/working/<id>/<id><letter>.cpp` rồi mở file luôn. Nếu file đã tồn tại thì không ghi đè.
2. **Snippet** — trong file `.cpp` bất kỳ, gõ `cp` (hoặc `code_t`) rồi `Tab`.

`.vscode/competitive.code-snippets` còn có sẵn `DSU`, ` Segment Tree`, `kadane`, `is_prime`,
`BigINT`, `{} un_dir_graph {}`, `{} Tree {}`, `{} BST_TREE {}`, `() count_divisor ()`, …

---

## Template lời giải

```cpp
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
```

> **Giữ nguyên block `#ifndef ONLINE_JUDGE`.** Ở local nó redirect I/O vào `input.txt`/`output.txt`;
> trên judge (nơi `ONLINE_JUDGE` đã được define) nó dùng stdin/stdout thật. Xoá đi là hỏng workflow
> chạy local.

---

## Môi trường / compiler

- **WinLibs g++ 16.1** (POSIX/UCRT), cài trên ổ **D**:
  ```powershell
  winget install --id BrechtSanders.WinLibs.POSIX.UCRT --scope user --location D:\SDK\winlibs
  ```
  Binary: `D:\SDK\winlibs\mingw64\bin\g++.exe` — `run.ps1` kiểm tra đường dẫn này **trước** khi
  dò PATH, nên không cần thêm gì vào PATH.

- Đây là package *portable (zip)*: tải ~260 MB, bung ra ~11.700 file / 913 MB, nên cài lại mất
  vài phút. Cứ để chạy, đừng tưởng treo.

- **Bắt buộc compile `-static`.** winget chỉ shim command lên PATH chứ không đưa runtime DLL vào,
  nên exe link động sẽ crash với `0xC0000135 STATUS_DLL_NOT_FOUND` (exit code `-1073741515`).
  `run.ps1` luôn dùng `-static`, và có fallback tự dò `g++` trong WinGet Packages / MSYS2 ngay cả
  khi shell chưa refresh PATH.

- Nếu gặp lỗi *"g++ not found"*: `Ctrl+Shift+P` → **Reload Window** sau khi cài compiler.

---

## Phần đã bỏ

Build CMake + CLion cũ (`CMakeLists.txt`, `cmake-build-debug/`) **đã bị xoá** — nó là tàn dư từ
máy cũ (MSYS2 + CLion), không còn thuộc workflow hiện tại. `.vscode/launch.json`, `.vscode/snippet.txt`
và `.idea/` cũng là leftover không dùng đến.
