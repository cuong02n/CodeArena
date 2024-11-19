/*
    author : cuong2905say
    created : 21-09-2024  22:37:44  UTC: +7
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
vector<int> FENW;

inline int scan_single() {
    int x;
    cin >> x;
    return x;
}

void point_update(int idx, int value) {
    while (idx < FENW.size()) {
        FENW[idx] += value;
        idx += idx & (-idx);
    }
}
void range_update(int left, int right, int value) {
    point_update(left, value);
    point_update(right + 1, -value);
}
int point_query(int idx) {
    int res = 0;
    while (idx > 0) {
        res += FENW[idx];
        idx -= idx & (-idx);
    }
    return res;
}

void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
void precalc() {
}
void solve(bool v = false, int all_case = -1) {
    int n, d, k;
    cin >> n >> d >> k;
    FENW.clear();
    FENW.assign(n + 1, 0);

    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;

        range_update(max(1, l - d + 1), r, 1);
    }

    int result[n + 1];
    result[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        result[i] = point_query(i);
    }
    int max_index = n;
    int max_value = 0;

    int min_index = 1;
    int min_value = 1e9;
    for (int i = n - d + 1; i >= 1; i--) {
        if (result[i] >= max_value) {
            max_value = result[i];
            max_index = i;
        }
        if (result[i] <= min_value) {
            min_value = result[i];
            min_index = i;
        }
    }
    // brother
    cout << max_index << " " << min_index << endl;

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
