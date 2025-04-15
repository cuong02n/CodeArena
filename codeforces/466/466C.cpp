/*
    author : cuong2905say
    created : 30-09-2022  10:39:50  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll A[500001];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (i) {
            A[i] += A[i - 1];
        }
    }
    if (A[n - 1] % 3) {
        cout << 0 << endl;
        return;
    }
    ll f = 0;
    ll s = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == A[n - 1] / 3) {
            f++;
        }
        if (f) {
            if (A[i] != A[n - 1] / 3) {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] == 2 * A[n - 1] / 3) {
            s++;
        }
        if (s) {
            if (A[i] != 2 * A[n - 1] / 3) {
                break;
            }
        }
    }
    cout << (f * s) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
