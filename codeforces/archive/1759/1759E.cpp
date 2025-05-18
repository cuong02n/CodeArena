/*
    author : cuong2905say
    created : 23-08-2023  19:56:21  UTC: +7
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

int access(ll A[], int n, ll h, int x[]) {  // [2,2,3]
    ll res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < 3 && h <= A[i]) {
            h *= x[j];
            j++;
        }
        if (h <= A[i]) {
            return res;
        }
        h += A[i] / 2;
        res++;
    }
    return res;
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
void solve(bool v = false, int all_case = -1) {
    ll n, h;
    cin >> n >> h;
    ll A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A, A + n);
    ll _max = A[n - 1];
    int x[] = {3, 2, 2};
    int y[] = {2, 3, 2};
    int z[] = {2, 2, 3};
    cout << max(access(A, n, h, x), max(access(A, n, h, y), access(A, n, h, z))) << endl;
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
