/*
    author : cuong2905say
    created : 08-04-2025  22:17:51  UTC: +7
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
void solve(bool v = false, int all_case = -1) {
    int n = sc;
    long long mx = 1 << n;
    int q = sc;
    for (int i = 0; i < q; i++) {
        char _, __;
        cin >> _ >> __;
        if (_ == '-') {
            long long x, y;
            cin >> x >> y;
            long long sz = mx;
            long long result = 1;
            while (sz > 0) {
                // cout << "sz =" << sz << ", x= " << x << ", y=" << y << endl;
                // cout << "result = " << result << endl;
                if (x > sz / 2) {
                    if (y > sz / 2) {
                        result += 1 * sz * sz / 4;
                    } else {
                        result += 2 * sz * sz / 4;
                    }
                } else if (y > sz / 2) {
                    result += 3 * sz * sz / 4;
                } else {
                    // cout << "end algo" << endl;
                }
                if (x > sz / 2) x -= sz / 2;
                if (y > sz / 2) y -= sz / 2;
                sz >>= 1;
            }
            cout << result << endl;
        } else if (_ == '<') {
            ll z;
            cin >> z;
            long long sz = mx;
            long long x = 1;
            long long y = 1;
            while (sz > 1) {
                // cout << "sz = " << sz << ", x= " << x << ", y=" << y << ", z = " << z << endl;
                if (z > 3 * sz * sz / 4) {
                    z -= 3 * sz * sz / 4;
                    y += sz / 2;
                } else if (z > 2 * sz * sz / 4) {
                    z -= 2 * sz * sz / 4;
                    x += sz / 2;
                } else if (z > sz * sz / 4) {
                    z -= sz * sz / 4;
                    x += sz / 2;
                    y += sz / 2;
                }
                sz /= 2;
            }
            cout << x << " " << y << endl;
        }
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
