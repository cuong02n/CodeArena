/*
    author : cuong2905say
    problem: Codeforces 2252A
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
    map<int, int> mp;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mp[a[i]]++;
    }

    int c = 0, x = 0;
    for (auto& [val, cnt] : mp) {
        if (cnt > c) {
            c = cnt;
            x = val;
        }
    }

    // chơi được tối đa 2*(n-c)+2 lá; số lá x phải bỏ lại là 2c-n-2 (nếu > 0)
    ll drop = max(0, 2 * c - n - 2);
    cout << sum - drop * x << "\n";
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
