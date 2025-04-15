/*
    author : cuong2905say
    created : 26-09-2022  13:32:29  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
set<int> even;
set<int> odd;
set<int> even1;
set<int> odd1;
void solve() {
    int n;
    cin >> n;
    even.clear();
    odd.clear();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2) {
            odd.insert(x);
        } else {
            even.insert(x);
        }
    }
    int m;
    cin >> m;
    odd1.clear();
    even1.clear();
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x % 2) {
            odd1.insert(x);
        } else {
            even1.insert(x);
        }
    }
    cout << 1LL * odd1.size() * odd.size() + 1LL * even1.size() * even.size() << endl;
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
