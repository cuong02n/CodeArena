/*
    author : NGUYEN MANH CUONG
    created : 08-09-2022  21:49:54    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i < n - 3; i++) {
            cout << n - 3 - i << ' ';
        }
        cout << n - 2 << ' ';
        cout << n - 3 << ' ';
        cout << n - 1 << ' ';
        cout << n << endl;
    }
    system("pause");
    return 0;
}