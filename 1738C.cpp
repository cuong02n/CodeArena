#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100;
int T, n;
ll factorial[N], mo = 998244353, Alex[N];
ll ksm(ll a, ll x) {  // what is factorial and ksm ? ?
    // a^x mod m;
    ll ans = 1;
    while (x) {
        if (x & 1) {  // x is odd ( x%2)
            ans = ans * a % mo;
        }
        a = a * a % mo;
        x >>= 1;
    }
    return ans;
}
ll C(int n, int m) {
    return factorial[n] * ksm(factorial[m], mo - 2) % mo * ksm(factorial[n - m], mo - 2) % mo;
}
int main() {
    factorial[0] = 1;
    for (ll i = 1; i <= 60; ++i) {
        factorial[i] = factorial[i - 1] * i % mo;
    }
    // pre calculate factorial[], factorial [i]= i!
    for (int i = 2; i <= 60; i += 2) {
        Alex[i] = (C(i - 1, i / 2 - 1) + C(i - 2, (i - 2) / 2) - 1 - Alex[i - 2] + mo) % mo;
    }
    // cin >> T;
    // while (T--) {
    //     cin >> n;
    //     cout << Alex[n] << " " << (C(n, n / 2) - 1 - Alex[n] + mo) % mo << 1;
    // }
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << C(x, y) << endl;
    }
    system("pause");
}