/*
    author : cuong2905say
    created : 11-08-2023  19:31:15  UTC: +7
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
int MEX(int A[], int size) {
    int B[size];
    for (int i = 0; i < size; i++) {
        B[i] = A[i];
    }
    sort(B, B + size);
    int _MEX = 0;
    for (int i = 0; i < size; i++) {
        _MEX += _MEX == B[i];
    }
    return _MEX;
}
void solve(bool v = false, int all_case = -1) {
    int n;
    cin >> n;
    int A[n];
    p B[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int mex = MEX(A, n);
    // turn off all first == MEX+1 to last == MEX+ 1 to MEX
    int last_ind = 0;
    int first_ind = 0;
    for (int i = 0; i < n; i++) {
        last_ind = (A[i] == mex + 1) ? i : last_ind;
    }
    for (int i = n - 1; i >= 0; i--) {
        first_ind = (A[i] == mex + 1) ? i : first_ind;
    }
    for (int i = first_ind; i <= last_ind; i++) {
        A[i] = mex;
    }
    cout << (MEX(A, n) == mex + 1 ? "YES" : "NO") << endl;

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
