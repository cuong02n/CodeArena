/*
    author : cuong2905say
    created : 27-07-2023  20:39:16  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int MOD = 1e9 + 7;
int verbose = -1;

using p = pair<int, int>;
void solve(bool v = false) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int A0[n];
    int A1[n];
    set<p> res;

    for (int i = 0, j = 0; (i < n) && (j < n); j++) {
        if (s[j] == '0' && j < n - 1) {
            continue;
        }
        for (int k = i; k <= j; k++) {
            A0[k] = j;
        }
        i = j + 1;
    }

    for (int i = n - 1, j = n - 1; (i >= 0) && (j >= 0); j--) {
        if (s[j] == '1' && j > 0) {
            continue;
        }
        for (int k = i; k >= j; k--) {
            A1[k] = j;
        }
        i = j - 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int newX;
        int newY;
        if (s[x] == '1' && x > 0 && s[x - 1] == '0') {
            newX = A0[x - 1];
        } else {
            newX = A0[x];
        }
        if (s[y] == '0' && y < n - 1 && s[y + 1] == '1') {
            newY = A1[y + 1];
        } else {
            newY = A1[y];
        }
        if (newX >= newY) {
            newX = 0;
            newY = 0;
        }
        res.insert({newX, newY});
    }
    cout << res.size() << endl;

    if (v) {
    }
}

void reset() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
#ifndef ONLINE_JUDGE
        cout << "case " << i + 1 << ": ";
#endif
        if (verbose == i + 1) {
            solve(true);
        } else {
            solve();
        }
        reset();
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
#ifndef ONLINE_JUDGE
    chrono::duration<double> time_span = chrono::duration_cast<std::chrono::duration<double>>(end - start);
    cout << "time use: " << time_span.count() << endl;
#endif

    return 0;
}
