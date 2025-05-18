#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;  // Số test case
    cin >> t;

    while (t--) {
        int n;  // Kích thước của ma trận n x n
        cin >> n;

        vector<vector<int>> h(n, vector<int>(n));  // Ma trận chiều cao của các tòa nhà
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> h[i][j];
            }
        }

        vector<int> a(n), b(n);  // Chi phí thuê công nhân từ công ty A và B
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        // Biến tổng chi phí
        long long total_cost = 0;
        bool possible = true;

        // Kiểm tra các cặp tòa nhà kề nhau theo hàng và cột
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Kiểm tra cặp tòa nhà ngang
                if (j < n - 1 && h[i][j] == h[i][j + 1]) {
                    // Sửa chiều cao của hàng này
                    total_cost += a[i];  // Chọn sửa theo hàng
                    h[i][j + 1]++;  // Tăng chiều cao tòa nhà tiếp theo
                }
                // Kiểm tra cặp tòa nhà dọc
                if (i < n - 1 && h[i][j] == h[i + 1][j]) {
                    // Sửa chiều cao của cột này
                    total_cost += b[j];  // Chọn sửa theo cột
                    h[i + 1][j]++;  // Tăng chiều cao tòa nhà tiếp theo
                }
            }
        }

        // In ra chi phí tổng
        if (possible) {
            cout << total_cost << endl;
        } else {
            cout << -1 << endl;
        }
    }


    return 0;
}
