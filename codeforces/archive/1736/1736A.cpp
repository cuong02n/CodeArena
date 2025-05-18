/*
    author : cuong2905say
    created : 10-10-2022  21:43:05  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
int A[101];
int B[101];
void solve() {
    cin >> n;
    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i]) {
            x++;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        if (B[i]) {
            y++;
        }
    }
    int z = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] - B[i]) {
            z++;
        }
    }
    cout << min(abs(x - y) + 1, z) << endl;
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
