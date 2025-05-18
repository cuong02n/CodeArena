/*
    author : cuong2905say
    created : 17-09-2022  11:31:59  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll cal(ll k, ll i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    if (i == 2) {
        return 3;
    }
    if (i <= k) {
        return i * (i + 1) / 2;
    }
    if (i > k && i < 2ll * k) {
        return cal(k, k) + (i - k) * (2ll * k - i) + (i - k) * (i - k - 1) / 2;
    }
    return 2ll * cal(k, k) - k;
}
int check(ll k, ll x, ll check) {
    if (cal(k, check - 1) < x && (cal(k, check) >= x)) {
        return 1;
    }
    return 0;
}
ll find(ll k, ll x, ll left, ll right) {
    if ((cal(k, right)) <= x) {
        return right;
    }
    // cout << "left: " << left << " right: " << right << endl;
    // system("pause");
    ll mid = (left + right) / 2;
    if (check(k, x, right)) {
        return right;
    }
    if (check(k, x, left)) {
        return left;
    }

    if (check(k, x, mid)) {
        return mid;
    }
    if (cal(k, mid) < x) {
        return find(k, x, mid + 1, right);
    }
    return find(k, x, left, mid - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        ll x, k;
        cin >> k >> x;
        cout << find(k, x, 1, 2 * k - 1) << endl;
    }
    system("pause");
    return 0;
}
