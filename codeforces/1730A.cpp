/*
    author : cuong2905say
    created : 25-09-2022  21:38:45  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int count_[101];

void solve() {
    int res = 0;
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < 101; i++) {
        count_[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count_[x]++;
    }
    for (int i = 1; i <= 100; i++) {
        res += min(count_[i], c);
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
