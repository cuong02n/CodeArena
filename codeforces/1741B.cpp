/*
    author : cuong2905say
    created : 12-10-2022  16:43:52  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
void solve() {
    cin >> n;
    if (n - 3) {
        for (int i = n; i >= 1; i--) {
            if (n + 1 - i == i) {
                cout << i - 1 << " " << i << " ";
                i--;
            } else {
                cout << i << " ";
            }
        }
        cout << endl;
        return;
    }
    cout << -1 << endl;
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
