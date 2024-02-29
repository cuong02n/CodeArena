/*
    author : cuong2905say
    created : 05-12-2023  22:20:06  UTC: +7
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
int min_distance(int x, int y, int prev_x, int prev_y) {
    if (x > prev_y) {
        return x - prev_y;
    }
    if (y < prev_x) {
        return prev_x - y;
    }
    return 0;
}
using p = pair<int, int>;
#define ff first
#define ss second
p intersec(p x, p y) {
    if (x.ff > y.ss) {
        return {-1, -1};
    }
    if (x.ss < y.ff) {
        return {-1, -1};
    }
    if (x.ff <= y.ff && y.ff <= x.ss) {
        return {y.ff, min(y.ss, x.ss)};
    }
    if (x.ff <= y.ss && y.ss <= x.ss) {
        return {max(y.ff, x.ff), y.ss};
    }
    return x;
}
bool check(p A[], int n, int k) {
    p blue_zone = {0, 0};
    for (int i = 0; i < n; i++) {
        blue_zone.ff -= k;
        blue_zone.ss += k;
        blue_zone = intersec(blue_zone, A[i]);
        if (blue_zone.ff == -1) {
            return false;
        }
    }
    return true;
}
void solve(bool v = false, int all_case = -1) {
    int n = sc;
    p A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i].ff >> A[i].ss;
    }
    int kl = 0, kr = 1e9;
    int mid = kl + kr >> 1;
    while (kl < kr) {
        // cout << "l = " << kl << " r = " << kr << endl;
        mid = kl + kr >> 1;
        if (check(A, n, mid)) {
            kr = mid;
        } else {
            kl = mid + 1;
        }
    }
    cout << kl << endl;
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
