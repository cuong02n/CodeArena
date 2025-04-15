/*
    author : cuong2905say
    created : 18-09-2023  23:24:28  UTC: +7
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()
#define sc scan_single()
#define int long long
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
vector<int> FENW;
void point_update(int idx, int value) {
    while (idx < FENW.size()) {
        FENW[idx] += value;
        idx += idx & (-idx);
    }
}
void range_update(int left, int right, int value) {
    point_update(left, value);
    point_update(right + 1, -value);
}
int point_query(int idx) {
    int res = 0;
    while (idx > 0) {
        res += FENW[idx];
        idx -= idx & (-idx);
    }
    return res;
}
using p = pair<int, int>;

inline int bin_search(const vector<p>& a, int st, int sum, int count) {
    if (count == 0) return 0;
    int mn = 0;
    int mx = count;

    while (mn < mx) {
        int mid = (mn + mx) / 2;
        if ((count - mid) * a[st + 1].first + mid * a[st].first > sum)
            mn = mid + 1;
        else
            mx = mid;
    }

    return mn;
}

void solve(bool v = false, int all_case = -1) {
    int n = sc;
    int B[n + 1];
    vector<p> C;
    for (int i = 0; i < n; i++) {
        B[i] = sc;
    }
    p base = make_pair(-1, -1);
    for (int i = 0; i < n; i++) {
        if (base.first >= B[i]) {
            while (!C.empty()) {
                if (C.back().first >= B[i]) {
                    C.pop_back();
                } else {
                    break;
                }
            }
            C.push_back(make_pair(B[i], i));
        } else {
            C.push_back(make_pair(B[i], i));
        }
        base = make_pair(B[i], i);
    }
    int k = sc;
    vector<long long> out = vector<long long>(n);
    int l = k / C[0].first;
    for (int i = 0; i < C.size() - 1; ++i) {
        out[C[i].second] = bin_search(C, i, k, l);
        l -= out[C[i].second];
        k -= out[C[i].second] * C[i].first;
    }
    out[C.back().second] = l;
    for (int i = n - 2; i >= 0; i--) {
        out[i] += out[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        cout << out[i] << ' ';
    }
    cout << '\n';
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
        cout << "case " << i + 1 << ": \n";
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
