/*
    author : cuong2905say
    created : 21-09-2023  14:03:27  UTC: +7
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

int gcd(int x, int y) {
    if (x < y) {
        return gcd(y, x);
    }
    if (x % y) {
        return gcd(y, x % y);
    }
    return y;
}

const int N = 1e7 + 5;
bool prime[N] = {};
vector<int> prm;
void solve(bool v = false, int all_case = -1) {
    int n = sc;
    for (int i = 0; i < N; i++) {
        prime[i] = true;
    }
    for (int i = 2; i < N; i++) {
        for (int j = i + i; j < N; j += i) {
            prime[j] = false;
        }
    }
    for (int i = 2; i < N; i++) {
        if (prime[i]) prm.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        int x = sc, y = sc;
        int k = INT_MAX;
        if (y - x == 1) {
            cout << -1 << '\n';
            continue;
        }
        if (__gcd(x, y) != 1) {
            cout << 0 << '\n';
            continue;
        }
        int c = sqrt(y - x);
        int l = y - x;
        int upper = sqrt(y - x);

        for (int i = 0; (i < prm.size() && prm[i] <= c); i++) {
            if (l % prm[i]) {
                continue;
            }
            while (l % prm[i] == 0)
                l /= prm[i];
            if (x % prm[i] == 0) k = 0;
            k = min(k, prm[i] - x % prm[i]);
        }
        if (l != 1) {
            if (x % l == 0) k = 0;
            k = min(k, l - x % l);
        }
        cout << k << '\n';
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

    int t = 1;
    precalc();
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
