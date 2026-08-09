/*
    author : cuong2905say
    problem: Codeforces 2253C
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int V = n + m;
    vector<char> mk(V + 1, 0);
    for (int i = 0; i < x; i++) {
        int v;
        cin >> v;
        mk[v] |= 1;
    }
    for (int i = 0; i < y; i++) {
        int v;
        cin >> v;
        mk[v] |= 2;
    }

    ll ans = 0;
    int cA = 0, cB = 0, tot = 0, cap = n + m - 1;
    for (int v = V; v >= 1 && tot < cap; v--) {
        if (mk[v] == 3) {
            ans += v;
            tot++;
        } else if (mk[v] == 1) {
            if (cA < n) {
                ans += v;
                cA++;
                tot++;
            }
        } else if (mk[v] == 2) {
            if (cB < m) {
                ans += v;
                cB++;
                tot++;
            }
        }
    }

    cout << ans << '\n';
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
