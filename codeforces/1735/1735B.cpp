/*
    author : cuong2905say
    created : 02-10-2022  22:07:56  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
int p = 0;
int A[101];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    p = A[0];
    int res = 0;
    for (int i = 1; i < n; i++) {
        int d = A[i] % (2 * p - 1);
        res += (A[i] - d) / (2 * p - 1) - (d == 0);
    }
    cout << res << endl;
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
