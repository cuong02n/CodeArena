/*
    author : cuong2905say
    created : 16-10-2022  22:02:18  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
void solve() {
    char k;
    cin >> n >> k;
    string c;
    cin >> c;
    c.append(c);
    if (k == 'g') {
        cout << 0 << endl;
        return;
    }
    int f = -1;
    int res = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (c[i] == 'g') {
            if (f != -1) {
                res = max(i - f, res);
                f = -1;
            }
        }
        if (c[i] == k) {
            if (f == -1) {
                f = i;
            }
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 0;  // test case ;
    cin >> t;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
