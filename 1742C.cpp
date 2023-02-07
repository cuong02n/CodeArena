/*
    author : cuong2905say
    created : 13-10-2022  21:41:05  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
char A[8][8];

void solve() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < 8; i++) {
        int c = 0;
        for (int j = 0; j < 8; j++) {
            if (A[i][j] == 'R') {
                c++;
            } else {
                break;
            }
        }
        if (c == 8) {
            cout << "R" << endl;
            return;
        }
    }
    cout << "B" << endl;
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
