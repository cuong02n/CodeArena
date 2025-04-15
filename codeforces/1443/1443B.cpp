/*
    author : cuong2905say
    created : 14-08-2023  16:34:44  UTC: +7
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
void solve(bool v = false, int all_case = -1) {
    int a, b;
    cin >> a >> b;
    string x;
    cin >> x;
    int n = x.length();
    if (!v && all_case == all_cases) {
        return;
    }
    int dp[2][n];  // dp[0][i]: only active mine, no put
                   // dp[1][i]: connect with last mine, put all of mine
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    int last_mine = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (x[i] == '1') {
            last_mine = i;
            break;
        }
    }
    for (int i = 0, last_mine = -1; i < n; i++) {
        if (x[i] - '0') {
            if (last_mine == -1) {
                dp[0][i] = a;
                dp[1][i] = a;
            } else {
                int dif = i - last_mine - 1;
                if (dif == 0) {
                    dp[0][i] = dp[0][i - 1];
                    dp[1][i] = dp[1][i - 1];
                } else {
                    dp[0][i] = min(dp[0][last_mine] + a, dp[1][last_mine] + a);  // active
                    dp[1][i] = min(dp[0][last_mine] + dif * b, dp[1][last_mine] + dif * b);
                }
            }
            last_mine = i;
        }
    }
    // _print(dp[0], dp[0] + n);
    // cout << endl;
    // _print(dp[1], dp[1] + n);
    // cout << endl;
    cout << min(dp[0][last_mine], dp[1][last_mine]) << endl;

    if (v && all_case == all_cases) {
        cout << a << " " << b << endl;
        cout << x << endl;
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
