/*
    author : cuong2905say
    created : 19-09-2022  21:48:05  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        if (x == 0 && y == 0) {
            cout << -1 << endl;
        } else if (x == 0 || y == 0) {
            if (x == 0) {
                x = y;
                y = 0;
            }
            if ((n - 1) % x == 0) {
                // cout << "n = " << n << " x =" << x << endl;
                for (int i = 2; i <= n; i += x) {
                    for (int j = 0; j < x; j++) {
                        cout << i << " ";
                    }
                }
                cout << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    system("pause");
    return 0;
}
