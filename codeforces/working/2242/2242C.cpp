/*
    author : cuong2905say
    problem: Codeforces 2242C
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> cnt;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        cnt.push_back(j - i);
        i = j;
    }
    sort(cnt.begin(), cnt.end());
    int m = cnt.size();
    vector<ll> suf(m + 1, 0);
    for (int i = m - 1; i >= 0; i--) suf[i] = suf[i + 1] + cnt[i];
    int ans = 0;
    for (int i = 0; i < m;) {
        int v = cnt[i];
        int sz = m - i;
        ll sumS = suf[i];
        ll num = (ll)k - sumS;
        if (num % sz == 0) {
            ll g = num / sz;
            if (g >= 1 - v) ans++;
        }
        int j = i;
        while (j < m && cnt[j] == v) j++;
        i = j;
    }
    cout << ans << "\n";
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
