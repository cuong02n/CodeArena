/*
    author : cuong2905say
    created : 01-10-2023  00:27:19  UTC: +7
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
;
int all_cases = -1;
void precalc() {
}
using p = pair<int, int>;
void solve(bool v = false, int all_case = -1) {
    int n = sc;
    map<int, int> A;
    for (int i = 0; i < n; i++) {
        int x = sc;
        if (A.find(x) == A.end()) {
            A[x] = 1;
        } else {
            A[x]++;
        }
    }
    set<p> res;
    p begin = *A.begin();
    p last = *(--A.end());
    res.insert(begin);
    res.insert(last);
    A.erase(A.begin());
    A.erase(--A.end());
    int add = 1;
    while (add) {
        add = 0;
        for (auto it = A.begin(); it != A.end();) {
            auto it_before = res.lower_bound(*it);
            auto it_after = --it_before;
            if (it_before->second * it_after->first > it_before->second * it->first + it->second * it_after->first) {
                res.insert(make_pair(it->first, it->second));
                add = 1;
                A.erase(it++);
            } else {
                it++;
            }
        }
    }
    _print(all(res));
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
