/*
    author : cuong2905say
<<<<<<< HEAD
    created : 23-08-2023  20:10:41  UTC: +7
*/
#include <bits/stdc++.h>
=======
    created : 12-10-2023  13:02:26  UTC: +7
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()
#define sc scan_single()
>>>>>>> 56b5bcc1082cd17797f1bcbcca57872924a6bfb6

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

<<<<<<< HEAD
=======
inline int scan_single() {
    int x;
    cin >> x;
    return x;
}

>>>>>>> 56b5bcc1082cd17797f1bcbcca57872924a6bfb6
void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
<<<<<<< HEAD
void solve(bool v = false, int all_case = -1) {
    int res = 0;
    int n = 99999;
    for (int i = 1; i <= n; i++) {
        if (i % 10 == 4 || (i / 10) % 10 == 4 || ((i / 100) % 10) == 4 || (i / 1000) % 10 == 4 || (i / 10000) % 10 == 4) {
            res++;
        }
    }
    cout << n - res << endl;
=======
void precalc() {
}
void solve(bool v = false, int all_case = -1) {
    map<int, int> A;
    A[0]++;
    _print(all(A));
>>>>>>> 56b5bcc1082cd17797f1bcbcca57872924a6bfb6
    if (!v && all_case == all_cases) {
        return;
    }
    if (v && all_case == all_cases) {
        _verbose();
    }
}

void reset() {
}

<<<<<<< HEAD
int main() {
=======
signed main() {
>>>>>>> 56b5bcc1082cd17797f1bcbcca57872924a6bfb6
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

<<<<<<< HEAD
    int t = 1;
=======
    precalc();
    int t = 1;
    cin >> t;
>>>>>>> 56b5bcc1082cd17797f1bcbcca57872924a6bfb6
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
