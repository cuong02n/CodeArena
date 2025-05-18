/*
    author : cuong2905say
    created : 13-10-2022  21:47:48  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;

map<int, int> A;

void solve() {
    A.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (A.find(x) == A.end()) {
            A.insert({x, i});
        } else {
            A[x] = i;
        }
    }
    if (A.size() == 1) {
        if (A.begin()->first == 1) {
            cout << 2 * n << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    int res = -1;
    for (auto it1 = A.begin(); it1 != A.end(); it1++) {
        for (auto it2 = A.begin(); it2 != A.end(); it2++) {
            if (gcd(it1->first, it2->first) == 1) {
                // cout << " xem xet : " << it1->first << " " << it1->second << " " << it2->first << " " << it2->second << endl;
                res = max(res, it1->second + it2->second);
            }
        }
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
