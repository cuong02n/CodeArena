/*
    author : cuong2905say
    created : 01-10-2022  21:07:41  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;
    int res = -1;
    if (m % n == 0) {
        int x = m / n;
        res = 0;
        while (x % 2 == 0) {
            x /= 2;
            res++;
        }
        while (x % 3 == 0) {
            x /= 3;
            res++;
        }
        if (x != 1) {
            res = -1;
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
