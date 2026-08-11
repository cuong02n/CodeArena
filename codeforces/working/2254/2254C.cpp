/*
    author : cuong2905say
    problem: Codeforces 2254C
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

// 7 4
// 0 1 0 1 1 1 0 1 0 1 0 1 1 1

int nxt(int i, int n) {
    return (i + 1) % n;
}
void solve() {
    int n, k;
    cin >> n >> k;
    n *= 2;
    string s;
    cin >> s;
    string s2 = s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && s[nxt(i, n)] == '0') {
            s2[i] = '0';
            s2[nxt(i, n)] = '1';
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i += 2) {
        if (s2[i] == '1') {
            cnt2++;
        }
    }

    for (int i = 1; i < n; i += 2) {
        if (s2[i] == '1') {
            cnt1++;
        }
    }

    cout << cnt1 << " " << cnt2 << endl;
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
