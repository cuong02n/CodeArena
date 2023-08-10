/*
    author : cuong2905say
    created : 10-09-2022  16:25:36    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    long long res = 0;
    if (m == 1) {
        res = 1LL * (n - 1);
    } else {
        res = 1LL * n * (m - 1);
    }
    cout << res << endl;
    system("pause");
    return 0;
}