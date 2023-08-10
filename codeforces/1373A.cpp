/*
        author : cuong2905say
        created : 26-09-2022  19:43:11  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int a, b, c;
void solve1() {
    if (a >= c) {
        cout << -1 << " ";
    } else {
        cout << 1 << " ";
    }
}
void solve2() {
    if ((ll)c >= 1LL * a * b) {
        cout << -1 << endl;
    } else {
        cout << b << endl;
    }
}
void solve() {
    cin >> a >> b >> c;
    solve1();
    solve2();
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
