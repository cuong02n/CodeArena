/*
    author : cuong2905say
    created : 21-09-2023  10:28:38  UTC: +7
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
int exp(int x, int y) {
    int res = 1;
    while (--y) {
        res *= 10;
    }
    return res;
}
int len(int x) {
    int res = 0;
    while (x > 0) {
        x /= 10;
        res++;
    }
    return res;
}

void solve(bool v = false, int all_case = -1) {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if (a > c || b > c) {
        cout << -1 << endl;
        return;
    }
    vector<p> res;
    if (a == b && a == c) {
        int min_c = 2 * exp(10, c);
        int max_c = exp(10, c + 1) - 1;
        int min_a = exp(10, a);
        int max_a = exp(10, a + 1) - 1;
        for (int A = min_a; A <= max_a; A++) {
            int B = exp(10, b);
            while (len(B) == b && len(A + B) == c) {
                res.push_back(make_pair(A, B));
                B++;
            }
        }
    } else if (a == c && b < a) {
        int min_b = exp(10, b);
        int max_b = exp(10, b + 1) - 1;
        int min_c = exp(10, c);
        int max_c = exp(10, c + 1) - 1;
        int min_a = exp(10, a);
        int max_a = exp(10, a + 1) - 1;
        min_a = max(min_a, min_c - max_b);
        max_a = min(max_a, max_c - min_b);
        for (int A = min_a; A <= max_a; A++) {
            for (int B = min_b; B <= max_b;B++){
                if (len(A + B) > c) break;
                res.push_back(make_pair(A, B));
            }
        }
    }
    if (res.size() < k)
        cout << -1 << endl;
    else {
        cout << res[k - 1].first << " + " << res[k - 1].second << " = " << res[k - 1].first + res[k - 1].second << endl;
        // _print(all(res));
        // cout << endl;
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
