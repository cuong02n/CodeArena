/*
    author : cuong2905say
    created : 26-09-2022  20:58:13  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int _min = INT_MAX;
int _max = INT_MIN;
void solve() {
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int u1 = 0;
    int u2 = 0;
    int _max = a1 * (k1 - 1) + a2 * (k2 - 1);
    if (_max >= n) {
        cout << 0 << " ";
    } else {
        cout << n - _max << " ";
    }
    if (k1 <= k2) {
        u1 = min(n / k1, a1);
        u2 = min((n - u1 * k1) / k2, a2);
    } else {
        u2 = min(n / k2, a2);
        u1 = min((n - u2 * k2) / k1, a1);
    }
    cout << u1 + u2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
