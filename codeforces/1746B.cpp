/*
    author : cuong2905say
    created : 15-10-2022  21:45:58  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
int A[200001];
int B[200001];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(A, A + n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] - B[i]) {
            res++;
        }
    }
    res >>= 1;
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
