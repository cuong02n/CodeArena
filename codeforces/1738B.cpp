/*
    author : cuong2905say
    created : 30-09-2022  22:10:09  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int s[100001];
int a[100001];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = n - k; i < n; i++) {
        cin >> s[i];
    }
    a[n - k] = s[n - k];
    for (int i = n - 1; i > n - k; i--) {
        a[i] = s[i] - s[i - 1];
    }

    for (int i = n - k + 2; i < n; i++) {
        if (a[i - 1] > a[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    if (k > 1 && 1LL * (n - k + 1) * a[n - k + 1] < 1LL * a[n - k]) {
        cout << "NO" << endl;

    } else {
        cout << "YES" << endl;
    }
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
