/*
    author : cuong2905say
    problem: Codeforces 2242B
*/
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n < 3) {
        cout << "NO\n";
        return;
    }
    vector<int> b1(n + 1, 0), b2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        b1[i + 1] = b1[i] + (a[i] == 1 ? 1 : -1);
        b2[i + 1] = b2[i] + (a[i] <= 2 ? 1 : -1);
    }
    vector<int> mx(n, INT_MIN);
    mx[n - 1] = b2[n - 1];
    for (int i = n - 2; i >= 0; i--) mx[i] = max(mx[i + 1], b2[i]);
    bool ok = false;
    for (int p = 1; p <= n - 2; p++) {
        if (b1[p] >= 0 && mx[p + 1] >= b2[p]) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
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
