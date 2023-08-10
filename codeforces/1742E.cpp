/*
    author : cuong2905say
    created : 13-10-2022  22:09:03  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
int q = 0;
ll A[200001];
ll B[200001];  // min value
ll sum[200001];
int check(ll i, ll k) {
    if (i == n - 1) {
        if (B[i] <= k) {
            return 1;
        }
    } else {
        if (B[i] <= k && k < B[i + 1]) {
            return 1;
        }
    }
    return 0;
}
ll find(ll k, ll l, ll r) {
    // find in B ;
    // 0<= k <n
    // thoa man : A[i]<=k<A[i+1]
    if (check(r, k)) {
        return r;
    }
    if (check(l, k)) {
        return l;
    }
    if (B[l] > k) {
        return -1;
    }
    ll m = (l + r) / 2;
    if (check(m, k)) {
        return m;
    }
    if (B[m] <= k) {
        return find(k, m + 1, r);
    }
    return find(k, l, m - 1);
}
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sum[0] = A[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + A[i];
    }
    ll m = 0;
    for (int i = 0; i < n; i++) {
        m = max(m, A[i]);
        B[i] = m;
    }

    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        ll z = find(k, 0, n - 1);
        if (z >= 0) {
            cout << sum[z] << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << endl;
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
