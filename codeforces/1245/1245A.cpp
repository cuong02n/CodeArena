/*
    author : cuong2905say
    created : 26-09-2022  13:46:15  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
void solve() {
    int a, b;
    cin >> a >> b;
    if (gcd(a, b) != 1) {
        cout << "infinite" << endl;
    } else {
        cout << "finite" << endl;
    }
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
