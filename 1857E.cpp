/*
    author : cuong2905say
    created : 07-08-2023  23:01:27  UTC: +7
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
using p = pair<ll, ll>;
void solve(bool v = false, int all_case = -1) {
    int n;
    cin >> n;
    p A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A, A + n);
    ll base = n;
    for (ll i = n - 1, mul = 1; i > 0; i--, mul++) {
        base += 1ll * (A[i].first - A[i - 1].first) * mul;
    }
    vector<p> res;
    res.push_back({A[0].second, base});
    base -= n;
    ll prev = 0;

    for (ll i = 1; i < n; i++) {
        base -= 1ll * (n - i) * (A[i].first - A[i - 1].first);
        prev += 1ll * i * (A[i].first - A[i - 1].first);
        res.push_back({A[i].second, base + prev + n});
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].second << " ";
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
