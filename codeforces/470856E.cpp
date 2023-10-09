/*
    author : cuong2905say
    created : 30-09-2023  00:33:53  UTC: +7
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()
#define sc scan_single()

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

inline int scan_single() {
    int x;
    cin >> x;
    return x;
}

void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
void precalc() {
}
using p = pair<int, int>;
int get(vector<int> child[], int A[], int par[], int n, int i, string x) {
    // cout << "getting " << i << endl;
    // return the value
    if (A[i] != INT_MAX) return A[i];
    A[i] = (x[i - 1] == 'W') ? 1 : -1;
    for (int k = 0; k < child[i].size(); k++) {
        A[i] += get(child, A, par, n, child[i][k], x);
    }
    // cout << "A[" << i << "] = " << A[i] << endl;
    return A[i];
}
void solve(bool v = false, int all_case = -1) {
    int n = sc;
    int par[n + 1];
    int A[n + 1];  // the value
    vector<int> child[n + 1];
    for (int i = 2; i < n + 1; i++) {
        int x = sc;
        par[i] = x;
        child[x].push_back(i);
    }
    for (int i = 1; i < n + 1; i++) {
        A[i] = INT_MAX;
        // _print(all(child[i]));
        // cout << endl;
    }
    par[1] = 0;
    string x;
    cin >> x;
    get(child, A, par, n, 1, x);
    int res = 0;
    for (int i = 1; i < n + 1; i++) {
        // cout << "A[" << i << "] = " << A[i] << endl;
        if (!A[i]) res++;
    }
    cout << res << endl;

    if (!v && all_case == all_cases) {
        return;
    }
    if (v && all_case == all_cases) {
        _verbose();
    }
}

void reset() {
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    precalc();
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
