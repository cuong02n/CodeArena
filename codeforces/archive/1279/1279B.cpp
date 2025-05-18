/*
    author : cuong2905say
    created : 15-08-2023  08:51:11  UTC: +7
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
}

void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
using p = pair<int, int>;
void solve(bool v = false, int all_case = -1) {
    int n, s;
    cin >> n >> s;

    int A[n + 1] = {0};
    ll sum[n + 1] = {0};
    p _max[n + 1];
    for (int i = 0; i < n + 1; i++) {
        _max[n + 1] = {0, 0};
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum[i] = sum[i - 1] + A[i];
        if (_max[i - 1].first < A[i]) {
            _max[i] = {A[i], i};
        } else {
            _max[i] = _max[i - 1];
        }
    }
    for (int i = n; i >= 0; i--) {
        if (sum[i] <= s) {
            cout << 0 << endl;
            return;
        }
        if (sum[i] - _max[i].first <= s) {
            cout << _max[i].second << endl;
            // cout << "remove : " << _max[i].second << " , the last index: " << i << endl;
            return;
        }
    }

    // max ()
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
