/*
    author : cuong2905say
    created : 06-08-2023  22:31:50  UTC: +7
*/
#include <bits/stdc++.h>

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
    cout << endl;
}

void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
template <class T>
int _max(T first, T last) {
    int __max = INT_MIN;
    for (T it = first; it != last; it++) {
        __max = max(__max, *it);
    }
    return __max;
}
ll build_from(ll A[], ll k, int i) {
    cout << "build from " << i;
    ll prev = A[i];
    for (int j = i - 1; j >= 0; j--) {
        if (A[j] > prev) {
            return A[j];
        }
        int added = prev + 1 - A[j];
        if (added > k) {
            return prev;
        }
        k -= added;
        prev = A[j] + added;
    }
    return prev;
}
void solve(bool v = false, int all_case = -1) {
    ll n, k;
    cin >> n >> k;
    ll A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ll res = INT_MIN;
    for (int i = n - 1; i >= 1; i--) {
        ll x = build_from(A, k, i);
        cout << " = " << x << endl;
        res = max(res, x);
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
#ifndef ONLINE_JUDGE
        cout << "case " << i + 1 << ": ";
#endif
        if (verbose == i + 1) {
            solve(true);
        } else {
            solve();
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
