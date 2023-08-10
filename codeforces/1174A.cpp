/*
    author : cuong2905say
    created : 01-10-2022  19:23:31  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int A[2001];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> A[i];
    }
    sort(A, A + 2 * n);
    if (A[0] == A[2 * n - 1]) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < 2 * n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
