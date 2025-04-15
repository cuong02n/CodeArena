/*
    author : cuong2905say
    created : 10-10-2022  22:10:04  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll n = 0;
ll A[100001];
ll B[100002];
ll GCD(ll a, ll b) {
    if (a == b) {
        return a;
    }
    if (a % b == 0) {
        return b;
    }
    if (b % a == 0) {
        return a;
    }
    if (a > b) {
        return GCD(a - b, b);
    }
    return GCD(a, b - a);
}
ll LCM(ll a, ll b) {
    return a * b / GCD(a, b);
}
void solve() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    B[0] = A[0];
    for (ll i = 0; i < n - 1; i++) {
        B[i + 1] = LCM(A[i], A[i + 1]);
    }
    B[n] = A[n - 1];
    for (ll i = 0; i < n; i++) {
        if (GCD(B[i], B[i + 1]) != A[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 0;  // test case ;
    cin >> t;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
