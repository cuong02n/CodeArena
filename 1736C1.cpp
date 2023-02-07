/*
    author : cuong2905say
    created : 10-10-2022  22:50:41  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
int A[200005];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    ll res = 0;
    int before = 1;
    for (int i = 1; i <= n; i++) {
        while (before <= n && A[before] >= before - i + 1) {
            before++;
        }
        res += before - i;
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
