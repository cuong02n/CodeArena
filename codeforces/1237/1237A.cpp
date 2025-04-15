/*
    author : cuong2905say
    created : 26-09-2022  14:17:24  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    int u = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            cout << x / 2 << endl;
        } else {
            if (u == 0) {
                if (x < 0) {
                    cout << x / 2 << endl;
                } else {
                    cout << x / 2 + 1 << endl;
                }
                u = 1;
            } else {
                if (x < 0) {
                    cout << x / 2 - 1 << endl;
                } else {
                    cout << x / 2 << endl;
                }
                u = 0;
            }
        }
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
