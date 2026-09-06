# Hướng Dẫn Thiết Lập Môi Trường CodeArena (Windows)

Tài liệu này hướng dẫn cách khôi phục và thiết lập toàn bộ môi trường làm việc khi cài lại Windows hoặc chuyển sang máy mới.

---

## ⚡ Cách 1: 1-Click Auto Setup (Khuyến nghị)

Bạn chỉ cần thực hiện **1 trong các cách sau**:

### Cách 1.1: Double-click file `setup.bat`
* Mở thư mục `CodeArena` trong File Explorer và **nhấp đúp chuột vào file `setup.bat`**.

### Cách 1.2: Chạy qua PowerShell Terminal
```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File setup.ps1
```

### Cách 1.3: Chạy qua Command Palette trong IDE (Antigravity IDE / VS Code)
* Nhấn `Ctrl+Shift+P` (hoặc `F1`) -> gõ **Run Task** -> chọn **`CP: Setup environment & keybindings`**.

---

## 🔧 Script `setup.ps1` tự động làm những gì?

1. **Kiểm tra Compiler `g++`**:
   - Tự động tìm kiếm g++ tại `D:\SDK\mingw64\bin\g++.exe`, `D:\SDK\winlibs\...`, `C:\msys64\...` hoặc trên PATH.
   - Nếu chưa có compiler, script sẽ tự động tải và cài đặt WinLibs POSIX UCRT qua `winget`.
2. **Cấu hình biến môi trường PATH**:
   - Tự động thêm thư mục `bin` của compiler vào `User PATH` trong Windows Registry (đảm bảo mở terminal nào cũng nhận `g++`, `gcc`, `gdb`).
3. **Kích hoạt Snippets**:
   - Đồng bộ 45 snippets thuật toán & template vào `.vscode/competitive.code-snippets`.
4. **Cài đặt Phím tắt (Keybindings)**:
   - Tự động merge các phím tắt vào file `keybindings.json` của user cho Antigravity IDE / VS Code / Cursor / VSCodium:
     - `Ctrl+F9` (hoặc `Ctrl+Shift+B`): Compile và chạy file `.cpp` đang mở.
     - `Ctrl+F8`: Tạo bài mới (nhập mã contest + chữ cái bài).
5. **Kiểm tra biên dịch thử nghiệm**:
   - Biên dịch và chạy thử nghiệm một chương trình mẫu để xác nhận toàn bộ pipeline hoạt động hoàn hảo.

---

## 📋 Các phím tắt chính sau khi cài đặt

| Phím tắt | Chức năng | Ghi chú |
| :--- | :--- | :--- |
| `Ctrl+F9` | **Build & Run bài đang mở** | Đọc `input.txt` ở root và xuất kết quả ra `output.txt` + Terminal. |
| `Ctrl+Shift+B` | **Build & Run mặc định** | Giống `Ctrl+F9`. |
| `Ctrl+F8` | **Tạo bài mới (New CP problem)** | Nhập contest ID (vd: `2259`) và problem letter (vd: `A`). |
| `cp` + `Tab` (hoặc `code_t` + `Tab`) | **Chèn template CP** | Chèn khung code C++17 chuẩn có sẵn I/O redirection. |

---

## 🛠 Hướng dẫn cài đặt thủ công (Nếu không dùng script)

Nếu bạn muốn tự tay cấu hình từng bước:

### 1. Cài đặt C++ Compiler
- Tải **WinLibs MinGW-w64 (POSIX + UCRT)** và giải nén vào `D:\SDK\mingw64`.
- Hoặc chạy lệnh:
  ```powershell
  winget install --id BrechtSanders.WinLibs.POSIX.UCRT --scope user --location D:\SDK\winlibs
  ```
- Thêm `D:\SDK\mingw64\bin` vào `User PATH`.

### 2. Cài đặt Phím tắt
- Chạy script cài phím tắt:
  ```powershell
  powershell -NoProfile -ExecutionPolicy Bypass -File .vscode/install-keybindings.ps1
  ```
- Hoặc copy nội dung từ `.vscode/keybindings.json` dán vào file cấu hình phím tắt của IDE (`%APPDATA%\Antigravity IDE\User\keybindings.json` hoặc `%APPDATA%\Code\User\keybindings.json`).
