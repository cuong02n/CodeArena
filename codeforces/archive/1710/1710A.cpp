/*
    author : cuong2905say
    created : 23-08-2023  10:47:07  UTC: +7
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

bool e(vector<int> res, int sum) {
<<<<<<< HEAD
    ll s = 0;
    for (int i = 0; i < res.size(); i++) {
        s += res[i];
    }
=======
    int s = 0;
    for (int i = 0; i < res.size(); i++) {
        s += res[i];
    }utfysl. j wt szdfygucxTEYSRUDGr e at rsy rsyXacwcf wdcwVCAS DS SD S S
>>>>>>> 56b5bcc1082cd17797f1bcbcca57872924a6bfb6
    if (s < sum) {
        return false;
    }
    if (sum % 2) {
        for (int i = 0; i < res.size(); i++) {
            if (res[i] >= 3) {
                return true;
            }
        }
    } else {
        return true;
    }
    return false;
}

void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
void solve(bool v = false, int all_case = -1) {
    int n, m, k;
    cin >> n >> m >> k;
    int res = 0;
    int _m = 0;
    int _n = 0;
    vector<int> resm;
    vector<int> resn;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
<<<<<<< HEAD
        if (x / n >= 2) resm.push_back(x / n);
        if (x / m >= 2) resn.push_back(x / m);
=======
        if (x / n >= 2 && x / n != m - 1) resm.push_back(x / n);
        if (x / m >= 2 && x / m != n - 1) resn.push_back(x / m);
>>>>>>> 56b5bcc1082cd17797f1bcbcca57872924a6bfb6
    }

    if (!v && all_case == all_cases) {
        return;
    }
    cout << (e(resm, m) || e(resn, n) ? "YES" : "NO") << endl;
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
<<<<<<< HEAD
}
=======
}
>>>>>>> 56b5bcc1082cd17797f1bcbcca57872924a6bfb6
