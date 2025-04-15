/*
    author : cuong2905say
    created : 28-08-2023  23:20:41  UTC: +7
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
template <class T>
ostream& operator>>(ostream& os, vector<T>& x) {
    for (T& i : x) cin >> i;
    return os;
}

void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
void precalc() {
}
void solve(bool v = false, int all_case = -1) {
    int n;
    cin >> n;
    int A[n];
    int _maxm = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        _maxm = max(_maxm, A[i]);
    }
    bool a_e = true;
    bool dif = false;
    bool eq = false;
    for (int i = 1; i < n; i++) {
        if (A[i] != A[i - 1]) {
            a_e = false;
            dif = true;
        } else {
            eq = true;
        }
    }
    if (dif && eq) {
        cout << "-1" << endl;
        return;
    }
    if (a_e) {
        cout << 0 << endl;
        return;
    }
    ll res = 0;
    int incr_step = -1;
    int decr_step = -1;
    bool nv = 0;
    ll c = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] > A[i - 1]) {
            if (incr_step == -1) {
                incr_step = A[i] - A[i - 1];
            } else if (incr_step != A[i] - A[i - 1]) {
                nv = 1;
            }
        } else if (A[i] < A[i - 1]) {
            if (decr_step == -1) {
                decr_step = A[i - 1] - A[i];
            } else if (decr_step != A[i - 1] - A[i]) {
                nv = 1;
            }
            if (incr_step == -1)
                continue;
            else {
                res = A[i - 1] + incr_step - A[i];
                c = incr_step;
            }
        }
    }
    if (!nv) {
        // cout << "inc " << incr_step << " dec " << decr_step << endl;
        if (decr_step == -1)
            cout << 0 << endl;
        else if (incr_step + decr_step <= _maxm)
            cout << -1 << endl;
        else if (incr_step + decr_step)
            cout << incr_step + decr_step << " " << incr_step << endl;
        else if (res)
            cout << res << " " << c << endl;
        else
            cout << res << endl;
    } else
        cout << -1 << endl;

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
