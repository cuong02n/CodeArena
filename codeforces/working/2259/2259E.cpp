/*
    author : cuong2905say
    problem: Codeforces 2259E
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> diff(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            int L = max(0, i - b[i] + 1);
            int R = min(n - 1, i + b[i] - 1);
            if (L <= R) {
                diff[L]++;
                diff[R + 1]--;
            }
        }
    }

    vector<bool> can(n, true);
    int current_sum = 0;
    for (int i = 0; i < n; i++) {
        current_sum += diff[i];
        if (current_sum > 0) {
            can[i] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            int L = i - b[i];
            int R = i + b[i];
            bool ok = false;
            if (L >= 0 && L < n && can[L]) ok = true;
            if (R >= 0 && R < n && can[R]) ok = true;
            if (!ok) {
                cout << "-1\n";
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (can[i] ? '1' : '0');
    }
    cout << "\n";
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
    while (t--) {
        solve();
    }
    return 0;
}
