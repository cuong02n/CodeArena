/*
    author : cuong2905say
    problem: Codeforces 2254D
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MOD = 998244353;
const int MAXN = 1000006;

ll fact[MAXN], invFact[MAXN];

ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void initFact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;
}

ll C(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int m = 0, gap = 0, Ze = 0, Zo = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] != s[i + 1]) {
            m++;
            gap++;
        } else if (gap % 2 == 0) {
            Ze++;
        } else {
            Zo++;
        }
    }

    int E = m / 2 + 1;
    int O = (m + 1) / 2;

    ll ans = C(Ze + E - 1, E - 1);
    if (O > 0) ans = ans * C(Zo + O - 1, O - 1) % MOD;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    initFact();

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
