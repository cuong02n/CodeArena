/*
    author : cuong2905say
    created : 16-10-2022  22:39:06  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;

int p2(int x) {
    int res = 0;
    while (x % 2 == 0) {
        x /= 2;
        res++;
    }
    return res;
}
void solve() {
    cin >> n;
    int p = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p += p2(x);
    }
    int x = n / 2 * 2;
    int res = 0;
    vector<int> r;
    for (int i = 2; i <= n; i += 2) {
        r.push_back(p2(i));
    }

    sort(r.begin(), r.end());
    while (p < n) {
        if (r.size() == 0) {
            res = -1;
            break;
        } else {
            p += r[r.size() - 1];
            r.pop_back();
        }
        res++;
    }
    if (p < n) {
        res = -1;
    }
    cout << res << endl;
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

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
