/*
    author : cuong2905say
    created : 29-09-2022  14:36:32  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

long long n;

void solve1() {
    // min
    if (n % 6 == 0) {
        cout << n / 6 << " ";
    } else {
        cout << n / 6 + 1 << " ";
    }
}
void solve2() {
    cout << n / 4 << endl;
}
void solve() {
    cin >> n;
    if (n % 2 || n < 4) {
        cout << -1 << endl;
    } else {
        solve1();
        solve2();
    }
    // max ;
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
