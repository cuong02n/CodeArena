/*
    author : cuong2905say
    created : 17-09-2022  20:08:18  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int A[101];
int is_ok(int n, int k, ll val) {
    for (int i = 1; i < n; i++) {
        if (val * k < 1LL * A[i] * 100) {
            return 0;
        }
        val += A[i];
    }
    return 1;
}
ll find(int n, int k, ll left, ll right) {
    // cout << "left : " << left << " right : " << right << endl;
    // system("pause");

    if (is_ok(n, k, left)) {
        return left;
    }

    ll mid = (left + right) / 2;
    if (is_ok(n, k, mid)) {
        return find(n, k, left, mid);
    }
    return find(n, k, mid + 1, right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        cout << find(n, k, (long long)A[0], (LONG_LONG_MAX >> 8) - A[0]) - A[0] << endl;
    }
    system("pause");
    return 0;
}
