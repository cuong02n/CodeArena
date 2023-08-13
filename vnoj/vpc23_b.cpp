/*
    author : cuong2905say
    created : 11-08-2023  06:58:20  UTC: +7
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
    int c, n, m;
    cin >> c >> m >> n;
    p A[n];
    vector<int> s;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        cin >> A[i].second;
    }
    sort(A, A + n);
    int _c = c;
    ll res = 0;
    for (int i = 0, j = 0; i < n;) {
        // j : provide index;
        if (j < m && s[j] < A[i].first) {
            _c = c;
            j++;
            continue;
        }
        if (_c >= A[i].second) {
            _c -= A[i].second;
            res += A[i].second;
        }
        i++;
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
