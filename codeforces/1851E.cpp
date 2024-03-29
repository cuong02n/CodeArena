/*
    author : cuong2905say
    created : 20-08-2023  00:06:00  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> A) {
    os << "{ " << A.first << ", " << A.second << " }";
    return os;
}
template <class T1, class T2, class T3>
ostream& operator<<(ostream& os, tuple<T1, T2, T3> A) {
    os << "{ " << get<0>(A) << ", " << get<1>(A) << ", " << get<2>(A) << " }";
    return os;
}

template <class it>
void _print(it begin, it end) {
    for (it i = begin; i != end; i++) {
        cout << *i << " ";
    }
}

void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;

void dfs(ll res[], int cost[], int i, int n, vector<int> adj[]) {
    if (res[i] != LLONG_MAX) return;
    if (cost[i] == 0) {
        res[i] = 0;
        return;
    }
    if (adj[i].empty()) {
        res[i] = cost[i];
        return;
    }

    ll v = 0;
    for (int x : adj[i]) {
        dfs(res, cost, x, n, adj);
        v += res[x];
    }
    res[i] = min((ll)cost[i], min(v, res[i]));
}
void solve(bool v = false, int all_case = -1) {
    int n, k;
    cin >> n >> k;
    int c[n + 1];
    for (int i = 1; i < n + 1; i++) {
        cin >> c[i];
    }

    vector<int> adj[n + 1];
    for (int i = 1; i < k + 1; i++) {
        int x;
        cin >> x;
        c[x] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    ll res[n + 1];
    for (int i = 1; i < n + 1; i++) {
        res[i] = LLONG_MAX;
    }
    for (int i = 1; i < n + 1; i++) {
        if (res[i] == LLONG_MAX) {
            dfs(res, c, i, n, adj);
        }
    }
    for (int i = 1; i < 1 + n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    if (!v && all_case == all_cases) {
        return;
    }
    if (v && all_case == all_cases) {
        _verbose();
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
            solve(true, t);
        } else {
            solve(false, t);
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
