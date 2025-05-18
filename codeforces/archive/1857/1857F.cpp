/*
    author : cuong2905say
    created : 19-08-2023  23:22:20  UTC: +7
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
optional<pair<int, int>> quadratic(int a, int b, int c) {
    long double delta = 1ll * b * b - 4ll * a * c;
    if (a == 0 || round(delta) < 0)
        return nullopt;
    long double s = round(sqrt(delta));
    return make_pair(round((-b + s) / 2 / a), (-b - s) / 2 / a);
}
void solve(bool v = false, int all_case = -1) {
    map<int, int> cnt;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        long double delta = 1ll * x * x - 4ll * y;
        if (round(delta) < 0) {
            cout << 0 << endl;
            continue;
        }
        long double s = sqrt(round(delta));
        ll r1 = (x + s) / 2;
        ll r2 = (x - s) / 2;
        if (r1 * r2 != y || r1 + r2 != x) {
            cout << 0 << endl;
            continue;
        }
        if (r1 == r2) {
            cout << 1ll * cnt[r1] * (cnt[r1] - 1) / 2 << endl;
            continue;
        }
        cout << 1ll * cnt[r1] * cnt[r2] << endl;
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
