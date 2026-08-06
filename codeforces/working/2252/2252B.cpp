/*
    author : cuong2905say
    problem: Codeforces 2252B
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

int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int A0 = count(all(s), '0');
    int A1 = n - A0;
    int d = A0 - A1;  // |d| >= 3 => vo nghiem

    int R = 1;  // so run
    for (int i = 1; i < n; i++)
        if (s[i] != s[i - 1]) R++;
    char f = s[0];

    int best = -1;  // do dai lon nhat cua chuoi giu lai
    for (int b = 0; b < 2; b++) {
        int cap = (char('0' + b) == f) ? R : R - 1;
        for (int L = cap; L >= max(0, cap - 1); L--) {
            int diff = (L % 2 == 0) ? 0 : (b == 0 ? 1 : -1);  // K0 - K1
            if (abs(d - diff) <= 1) best = max(best, L);
        }
    }

    cout << (best < 0 ? -1 : n - best) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
