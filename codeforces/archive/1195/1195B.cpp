/*
    author : cuong2905say
    created : 27-09-2022  11:22:16  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    cout << (int)(n - (pow(9.0 + 8 * (n + k), 0.5) - 3) / 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
