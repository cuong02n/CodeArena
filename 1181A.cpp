/*
    author : cuong2905say
    created : 01-10-2022  19:15:36  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    ll x, y, z;
    ll res = 0;
    cin >> x >> y >> z;
    res = (x + y) / z;
    x %= z;
    y %= z;
    if (x + y < z) {
        cout << res << " " << 0 << endl;
    } else {
        cout << res << " " << min(z - x, z - y) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
