/*
    author : NGUYEN MANH CUONG
    created : 07-09-2022  12:22:55
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
        char x, y;
        cin >> x >> y;
        int sum = 0;
        sum += (x - 'a') * 25;
        if (x > y) {
            sum += (y - 'a' + 1);
        } else {
            sum += (y - 'a');
        }
        cout << sum << endl;
    }
    return 0;
}
