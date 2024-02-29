/*
    author : cuong2905say
    created : 26-09-2023  22:02:32  UTC: +7
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
vector<int> FENW;
/*START INDEX : 1*/
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
using p = pair<int, int>;
void solve(bool v = false, int all_case = -1) {
    int n = sc;
    int k = sc;
    FENW.resize(n + 1);
    for (int i = 0; i < n + 1; i++) {
        FENW[i] = 0;
    }
    string x;
    cin >> x;
    int l[k + 1];
    p r[k + 1];
    for (int i = 1; i < k + 1; i++) {
        cin >> l[i];
    }
    for (int i = 1; i < k + 1; i++) {
        cin >> r[i].first;
        r[i].second = i;
    }
    int q = sc;
    for (int i = 0; i < q; i++) {
        int x = sc;
        auto z = lower_bound(r + 1, r + k + 1, make_pair(x, 0));
        int ind = z->second;
        int a = l[ind];
        int b = r[ind].first;
        int left = min(x, a + b - x);
        int right = max(x, a + b - x);
        range_update(left, right, 1);
    }
    for (int i = 1; i <= k; i++) {
        for (int j = l[i]; j <= r[i].first; j++) {
            if (point_query(j) % 2) {
                cout << x[l[i] + r[i].first - j - 1] ;
            }else{
                cout << x[j - 1] ;
            }
        }
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
