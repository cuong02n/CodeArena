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
    int n;
    int A[n];
    cin >> n;

    map<int, bool> B[3];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B[A[i]].insert({i, false});
    }
    int blue = n;
    while (B[2].size()) {
        auto k = B[2].begin();
        if (k->second) {
            B[2].erase(k);
            continue;
        }
        k->second = true;
        int pos = k->first;
        // if()
    }

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
