/*
    author : cuong2905say
    created : 26-09-2022  14:30:24  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (i == 0) {
            if (n == 1) {
                if (k == 1) {
                    cout << 0;
                } else {
                    cout << c;
                }
                break;
            }
            if (c == '1') {
                cout << c;
                continue;
            } else {
                if (k) {
                    cout << '1';
                    k--;
                } else {
                    cout << c;
                }
            }
        } else {
            if (c == '0') {
                cout << c;
                continue;
            } else {
                if (k) {
                    cout << '0';
                    k--;
                } else {
                    cout << c;
                }
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
