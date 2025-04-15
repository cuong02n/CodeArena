/*
    author : cuong2905say
    created : 10-09-2022  18:07:55    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if (n % 2) {
        cout << 0 << endl;
    } else {
        cout << (1ULL << (n / 2)) << endl;
    }
    system("pause");
    return 0;
}