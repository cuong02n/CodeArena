/*
    author : cuong2905say
    created : 30-09-2022  00:22:08  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n, m, a;
    cin >> n >> m >> a;
    cout << (n / a + !!(n % a)) * (m / a + !!(m % a)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
