/*
    author : cuong2905say
    created : 25-09-2023  16:08:55  UTC: +7
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
using p = pair<int, bool>;
void solve(bool v = false, int all_case = -1) {
    int n;
    cin >> n;
    p A[n];
    for (int i = 0; i < n; i++) {
        int x = sc;
        A[i].second = x ? true : false;
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        A[i].first = sc;
        sum += A[i].first;
    }
    vector<int> X;
    vector<int> Y;
    for (int i = 0; i < n; i++) {
        ((A[i].second) ? X : Y).push_back(A[i].first);
    }

    // X: true
    // Y: false
    sort(all(X));
    sort(all(Y));
    ll r1 = 0, r2 = 0;
    int n1 = X.size();
    int n2 = Y.size();
    // cout << n1 << " " << n2 << endl;
    if (n2 == n1) {
        sum *= 2;
        sum -= min(X[0], Y[0]);
    } else if (n1 < n2) {
        for (int i = n1 - 1; i >= 0; i--) {
            sum += X[i];
        }
        for (int i = n2 - 1; (i >= 0 && i >= n2 - n1); i--) {
            sum += Y[i];
        }
    } else {
        for (int i = n2 - 1; i >= 0; i--) {
            sum += Y[i];
        }
        for (int i = n1 - 1; (i >= 0 && i >= n1 - n2); i--) {
            sum += X[i];
        }
    }
    cout << sum << endl;
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
