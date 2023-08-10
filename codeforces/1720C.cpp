/*
        author : cuong2905say
        created : 20-09-2022  16:49:17  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
bool A[501][501];
int n, m;
int check(int i, int j) {
    if (i >= n || j >= m || i < 0 || j < 0) {
        return 0;
    }
    return 1;
}
int di[] = {0, 0, 1, 1};
int dj[] = {0, 1, 0, 1};
int count(int i, int j) {
    int res = 0;
    for (int k = 0; k < 4; k++) {
        if (!A[i + di[k]][j + dj[k]]) {
            res++;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        int num = 0;
        int _max = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '0') {
                    A[i][j] = false;
                } else {
                    num++;
                    A[i][j] = true;
                }
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                _max = max(_max, count(i, j));
            }
        }
        if (_max == 1) {
            num -= 1;
        } else if (_max == 0) {
            num -= 2;
        }

        cout << max(num, 0) << endl;
    }
    system("pause");
    return 0;
}
