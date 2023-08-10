/*
    author : cuong2905say
    created : 15-10-2022  21:39:29  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
int k = 0;
void solve() {
    cin >> n >> k;
    int _1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) {
            _1 = 1;
        }
    }
    cout << (_1 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 0;  // test case ;
    cin >> t;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
