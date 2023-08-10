/*
    author : cuong2905say
    created : 15-09-2022  18:07:57  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int main() {
    long long x;
    long long y;
    for (int i = 0; i < 25; i++) {
        cout << "? " << 1 << " " << i + 3 << endl;
        cin >> x;
        cout << "? " << i + 3 << " " << 1 << endl;
        cin >> y;
        if (x == -1 || y == -1) {
            cout << "! " << i + 2 << endl;
            break;
        }
        if (x != y) {
            cout << "! " << x + y << endl;
            break;
        }
    }
    system("pause");

    return 0;
}