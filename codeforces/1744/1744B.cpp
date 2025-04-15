/*
    author : cuong2905say
    created : 16-10-2022  21:46:30  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;

void solve() {
    int q;
    cin >> n >> q;
    ll sum_odd = 0;
    ll sum_even = 0;
    int odd = 0;
    int even = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x & 1) {
            odd++;
            sum_odd += x;
        } else {
            even++;
            sum_even += x;
        }
    }
    int f = 0;
    for (int i = 0; i < q; i++) {
        // cout << "sum even : " << sum_even << " even: " << even << " sum odd " << sum_odd << " odd" << odd << endl;
        cin >> f >> x;
        if (x & 1) {
            // le : doi
            if (f) {
                // le -> chan
                sum_odd += 1ll * odd * x;
                sum_even += sum_odd;
                even += odd;
                sum_odd = 0;
                odd = 0;
            } else {
                // chan ->le
                sum_even += 1ll * even * x;
                sum_odd += sum_even;
                odd += even;
                sum_even = 0;
                even = 0;
            }
        } else {
            if (f) {
                sum_odd += 1ll * odd * x;
            } else {
                sum_even += 1ll * even * x;
            }
        }
        cout << sum_odd + sum_even << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 0;  // test case ;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        // cout << "test " << i << endl;
        solve();
    }

    system("pause");
    return 0;
}
