/*
    author : cuong2905say
    created : 17-09-2022  12:52:34  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int P = (int)1e9 + 7;
// int P = 5;
int add_mod(int a, int b) {
    return (a + b) % P;
}
ll mul_mod(ll a, ll b) {
    return (1LL * a * b) % (long long)P;
}
ll pow_mod(ll a, ll k) {
    // a^k;
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return a;
    }
    ll u = pow_mod(a, k / 2);
    if (k % 2) {
        return a * u % P * u % P;
    }
    return u * u % P;
}
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int t = 1;  // test case ;
    // t = 0;
    // cout << pow_mod(95, 51);

    while (t--) {
        int n;

        cin >> n;
        if (n == 1) {
            cout << 6 << endl;
        } else {
            cout << mul_mod(6, pow_mod(4, (1LL << n) - 2)) << endl;
        }
    }
    system("pause");
    return 0;
}
