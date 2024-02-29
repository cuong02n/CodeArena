/*
    author : cuong2905say
    created : 05-10-2023  10:42:32  UTC: +7
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

bool check(int A[], int x, int m, int n) {
    int u[n + 1] = {};
    long long d = 0;
    for (int i = 0; i < m; i++) {
        if (u[A[i]] < x) {
            u[A[i]]++;
            d++;
        }
    }
    long long free = 0;
    for (int i = 1; i <= n; i++) {
        free += (x - u[i]) / 2;
    }
    return (d + free) >= m;
}
void solve(bool v = false, int all_case = -1) {
    int n, m;
    cin >> n >> m;
    int A[m];
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }
    int l = 1, r = 2 * m;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(A, mid, m, n))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l << endl;

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
