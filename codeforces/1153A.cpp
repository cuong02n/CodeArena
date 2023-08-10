/*
    author : cuong2905say
    created : 01-10-2022  19:41:06  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
int t = 0;
void solve() {
    cin >> n >> t;
    int M = INT_MAX;
    int res = -1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (M > 0) {
            if (x >= t) {
                if (M > x - t) {
                    res = i + 1;
                    M = x - t;
                }
            } else {
                if ((t - x) % y == 0) {
                    M = 0;
                    res = i + 1;
                } else if (M > (y - (t - x) % y)) {
                    M = y - (t - x) % y;
                    res = i + 1;
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
