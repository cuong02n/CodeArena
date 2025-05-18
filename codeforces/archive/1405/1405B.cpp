/*
    author : cuong2905say
    created : 26-09-2022  16:48:27  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
stack<ll> S;

void insert(ll x) {
    if (S.empty()) {
        S.push(x);
    } else if (S.top() > 0) {
        if (x > 0) {
            ll y = S.top();
            S.pop();
            S.push(x + y);
        } else if (x < 0) {
            ll y = S.top();
            if (y + x != 0) {
                S.pop();
                S.push(y + x);
            } else {
                S.pop();
            }
        }
    } else if (S.top() < 0) {
        S.push(x);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x != 0) {
            insert(x);
        }
    }

    ll res = 0;
    while (!S.empty()) {
        ll y = S.top();
        S.pop();
        if (y > 0) {
            res += y;
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
