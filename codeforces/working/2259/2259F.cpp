/*
    author : cuong2905say
    problem: Codeforces 2259F
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int R = 0; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) R++;
    }
    
    string s;
    cin >> s;

    vector<int> d(R + 1, 0);
    int ones_seen = 0;
    int zeros_total = n - R;
    int zeros_seen = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ones_seen++;
            d[ones_seen] = zeros_total - zeros_seen;
        } else {
            zeros_seen++;
        }
    }

    vector<ll> P(R + 1, 0);
    for (int i = 1; i <= R; i++) {
        P[i] = P[i - 1] + d[i];
    }

    cout << P[R] << " ";

    int A = 0;
    int B = 0;

    for (int k = 0; k < n; k++) {
        if (s[k] == '1') A++;
        else B++;

        if (A >= R) {
            cout << 0 << " ";
            continue;
        }

        int low = A + 1, high = R;
        int idx = A; 

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (d[mid] > B) {
                idx = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        ll ans = 0;
        if (idx > A) {
            ll sum_d = P[idx] - P[A];
            ll subtract_b = 1LL * (idx - A) * B;
            ans = sum_d - subtract_b;
        }
        
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
