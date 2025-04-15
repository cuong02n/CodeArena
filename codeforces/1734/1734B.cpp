/*
    author : cuong2905say
    created : 23-09-2022  19:26:21  UTC: +7
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
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= j; i++) {
                if (i == 1) {
                    cout << 1 << " ";
                } else if (i == j) {
                    cout << 1 << " ";
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}
