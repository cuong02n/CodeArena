/*
    author : cuong2905say
    problem: Codeforces 2259D
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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });


    if (a[idx[0]] == 0 && a[idx[1]] != 0) {
        cout << "NO\n";
        return;
    }

    string res(n, 'A');
    int pos = 0;
    int need = 0; 

    while (pos < n && a[idx[pos]] == need) {
        int start = pos;
        while (pos < n && a[idx[pos]] == need) pos++;
        int cnt = pos - start;

        if (cnt == 1) {
            res[idx[start]] = 'C';
            break;
        }

        res[idx[start + 1]] = 'B';
        need++;
    }

    cout << "YES\n" << res << "\n";
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
