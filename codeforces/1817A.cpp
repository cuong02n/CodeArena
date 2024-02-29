/*
    author : cuong2905say
    created : 27-08-2023  14:05:52  UTC: +7
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()
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
void precalc() {
}
using p = pair<int, int>;
void solve(bool v = false, int all_case = -1) {
    int n, q;
    cin >> n >> q;
    int A[n];
    map<int, int> B;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    B[-1] = 0;
    B[0] = 0;
    B[1] = 0;
    for (int i = 1; i < n - 1; i++) {
        if (A[i - 1] >= A[i] && A[i] >= A[i + 1]) {
            B[i] = B[i - 1] + 1;
        } else {
            B[i] = B[i - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r) {
            cout << 1 << endl;
            continue;
        }
        cout << r - l + 1 - B[r - 1] + B[l] << endl;
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

    precalc();
    int t = 1;
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
