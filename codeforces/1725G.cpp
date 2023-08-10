/*
    author : cuong2905say
    created : 10-09-2022  16:56:17    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    if (N == 1) {
        cout << 3 << endl;
    } else {
        int div = (N - 1) / 3;
        int mod = (N - 1) % 3;
        if (mod == 0) {
            cout << 4 + 1LL * 4 * div << endl;
        } else if (mod == 1) {
            cout << 5 + 1LL * 4 * div << endl;
        } else {
            cout << 7 + 1LL * 4 * div << endl;
        }
    }
    system("pause");
    return 0;
}