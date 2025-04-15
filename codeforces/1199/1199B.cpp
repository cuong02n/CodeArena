/*
    author : cuong2905say
    created : 27-09-2022  00:32:29  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    double L, H;
    cin >> H >> L;
    cout << fixed << setprecision(10) << ((L * L - H * H) / H / 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
