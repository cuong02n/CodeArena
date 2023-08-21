/*
    author : cuong2905say
    created : 15-08-2023  22:05:40  UTC: +7
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
int cal(int begin, int end, int d) {
    // cout << "cal " << begin << " and " << end << " is " << (end - 1 - begin) / d + 1 << endl;
    return (end - 1 - begin) / d + 1;
}
void solve(bool v = false, int all_case = -1) {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> A;
    A.push_back(1);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if (1 == x) {
            continue;
        }
        A.push_back(x);
    }
    A.push_back(n + 1);
    int res = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        int k = cal(A[i], A[i + 1], d);
        res += k;
    }
    int _max = 0;
    int amount = 0;

    for (int i = 1; i < A.size() - 1; i++) {
        int z = -cal(A[i - 1], A[i + 1], d) + cal(A[i], A[i + 1], d) + cal(A[i - 1], A[i], d);
        if (z > _max) {
            _max = z;
            amount = 1;
        } else if (_max == z) {
            amount++;
        }
    }
    cout << res - _max << " " << (_max ? amount : m) << endl;

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
