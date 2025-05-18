/*
    author : cuong2905say
    created : 27-09-2022  00:38:09  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int A[100001];

int is_valid(int i, int n) {
    // cout << " checking valid " << i << endl;
    if (i >= 0 && i < n) {
        return 1;
    }
    return 0;
}
int check(int n, int x, int y, int d) {
    // cout << "checking " << d << endl;
    for (int i = d - 1; i > d - 1 - x; i--) {
        if (!is_valid(i, n)) {
            continue;
        }
        if (A[d] > A[i]) {
            return 0;
        }
    }
    for (int i = d + 1; i < d + 1 + y; i++) {
        if (!is_valid(i, n)) {
            continue;
        }
        if (A[d] > A[i]) {
            return 0;
        }
    }

    return d + 1;
}
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        if (check(n, x, y, i)) {
            cout << check(n, x, y, i) << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
