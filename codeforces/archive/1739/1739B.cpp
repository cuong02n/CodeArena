/*
    author : cuong2905say
    created : 29-09-2022  22:06:18  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int D[101];
int A[101];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> D[i];
    }

    A[0] = D[0];
    for (int i = 1; i < n; i++) {
        if (D[i] <= A[i - 1] && D[i] != 0) {
            cout << -1 << endl;
            return;
        } else {
            A[i] = D[i] + A[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
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
