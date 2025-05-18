/*
    author : cuong2905say
    created : 26-09-2023  22:33:59  UTC: +7
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
inline int _get(int ind, int elem) {
    return ind / elem;
}
inline int gli(int group, int elem, int n) {
    return min(n - 1, elem * (group + 1) - 1);
}
void solve(bool v = false, int all_case = -1) {
    int n = sc;
    int elem = sqrt(n);
    int sz = n/elem + ((n%elem) ? 1 : 0);
    int A[n];
    int B[sz];
    for (int i = 0; i <= sz; i++) {
        B[i] = (1 << 30) - 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B[_get(i, elem)] &= A[i];
    }
    int q = sc;
    for (int i = 0; i < q; i++) {
        int l = sc;
        --l;
        int k = sc;
        if (A[l] < k) {
            cout << -1 << endl;
            continue;
        }
        int _r = gli(_get(l, elem), elem, n);
        // cout << " _r = " << _r << endl;
        int flag = 0;
        int res = A[l];
        for (int j = l + 1; j <= _r; j++) {
            res &= A[j];
            if (res < k) {
                cout << j << endl;
                flag = 1;
                break;
            }
        }
        // cout << "res after" << res << endl;
        if (flag) continue;
        int group_now = _get(l, elem) + 1;
        // cout << " grn = " << group_now << endl;
        // cout << "B [ grn ] = " << B[group_now] << endl;
        // cout << (B[group_now] & res) << endl;
        // cout << " sz = " << sz << endl;
        for (; ((group_now < sz) && ((res & B[group_now]) >= k)); res = res & group_now, group_now++) {
        }
        // cout << "grn " << group_now << endl;
        if (group_now == sz) {
            cout << n << endl;
        } else {
            for (int i = gli(group_now - 1, elem, n) + 1; i < n; i++) {
                // cout << "index = " << i << endl;
                if ((res & A[i]) < k) {
                    cout << i << endl;
                    break;
                }
            }
        }
        // group_now is the last group
    }

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
