/*
    author : cuong2905say
    created : 07-10-2022  22:06:07  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
ll f(ll r) {
    if (r == 0) {
        return 0;
    }
    if (r == 1) {
        return 1;
    }
    ll res = 0;
    ll m = floor(sqrt(1.0 * r));
    if (m * m > r) {
        m--;
    }
    res = (m - 1) * 3;
    ll m1 = m * m;
    res += (r - m1) / m + 1;
    return res;
}
void solve() {
    ll l, r;
    cin >> l >> r;
    ll x = f(l - 1);
    ll y = f(r);
    cout << y - x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
