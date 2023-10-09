/*
    author : cuong2905say
    created : 21-09-2023  22:40:30  UTC: +7
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()
#define sc scan_single()
#define endl '\n'
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
void solve(bool v = false, int all_case = -1) {
    int n, k;
    cin >> n >> k;
    int f[n];
    int A[n];
    int res = 0;

    for (int i = 0; i < n; i++) {
        cin >> f[i];
        if (f[i] <= k) {
            res = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (A[i] % A[i + 1]) {
            continue;
        }
        int res_tmp = f[i];
        for (int j = i + 1; j < n; j++) {
            if (A[j - 1] % A[j]) {
                i = j - 1;
                break;
            }
            res_tmp += f[j];
            while (res_tmp > k) {
                res_tmp -= f[i++];
            }
            if (j - i + 1 > res) res = j - i + 1;
            if (j == n - 1) {
                cout << res << endl;
                return;
            }
        }
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
