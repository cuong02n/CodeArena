/*
    author : cuong2905say
    created : 12-09-2022  21:38:52    UTC: +7
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
        int a, b, c;
        cin >> a >> b >> c;
        int f = a - 1;
        int s = abs(b - c) + abs(c - 1);
        if (f == s) {
            cout << 3 << endl;
        } else if (f > s) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    }
    system("pause");
    return 0;
}