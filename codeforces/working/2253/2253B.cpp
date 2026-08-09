/*
    author : cuong2905say
    problem: Codeforces 2253B
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& v : a) cin >> v;

    vector<int> C, L;
    for (int i = 0; i < n; i++) {
        if (C.empty() || C.back() != a[i]) {
            C.push_back(a[i]);
            L.push_back(1);
        } else {
            L.back()++;
        }
    }

    int R = C.size();
    int ans = R;
    for (int i = 0; i < R; i++) {
        if (L[i] < 2) continue;
        if (i >= 1 && (i < 2 || C[i - 2] != C[i])) ans = max(ans, R + 1);
        if (i + 1 < R && (i + 2 >= R || C[i + 2] != C[i])) ans = max(ans, R + 1);
        if (i + 1 < R && L[i + 1] >= 2) ans = max(ans, R + 2);
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
