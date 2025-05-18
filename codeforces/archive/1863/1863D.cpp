/*
    author : cuong2905say
    created : 30-08-2023  22:58:00  UTC: +7
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
    int n, m;
    cin >> n >> m;
    set<int> hor[n - 1];
    set<int> ver[m - 1];
    char res[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = '.';
        }
    }
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++) {
            if (x[j] == 'U') {
                hor[i].insert(j);
            } else if (x[j] == 'L') {
                ver[j].insert(i);
            } else if (x[j] == 'D') {
                hor[i - 1].insert(j);
            } else if (x[j] == 'R') {
                ver[j - 1].insert(i);
            }
        }
    }
    // for (int i = 0; i < n - 1; i++) {
    //     if (hor[i].size()) {
    //         cout << " hor " << i << " : ";
    //         _print(hor[i].begin(), hor[i].end());
    //         cout << endl;
    //     }
    // }
    // for (int i = 0; i < m - 1; i++) {
    //     if (ver[i].size()) {
    //         cout << " ver " << i << " : ";
    //         _print(ver[i].begin(), ver[i].end());
    //         cout << endl;
    //     }
    // }
    bool valid = true;
    for (int i = 0; i < n - 1; i++) {
        if (hor[i].size() % 2) {
            valid = false;
            break;
        }
        for (auto it = hor[i].begin(); it != hor[i].end(); it++) {
            res[i][*it] = 'B';
            res[i + 1][*it] = 'W';
            res[i][*(++it)] = 'W';
            res[i + 1][*it] = 'B';
        }
    }

    for (int j = 0; j < m - 1; j++) {
        if (ver[j].size() % 2) {
            valid = false;
            break;
        }
        for (auto it = ver[j].begin(); it != ver[j].end(); it++) {
            res[*it][j] = 'B';
            res[*it][j + 1] = 'W';
            res[*(++it)][j] = 'W';
            res[*it][j + 1] = 'B';
        }
    }
    if (!valid) {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j];
        }
        cout << endl;
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
