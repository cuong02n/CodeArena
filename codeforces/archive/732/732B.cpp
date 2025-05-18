/*
    author : cuong2905say
    created : 29-09-2022  23:56:31  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int A[501];
int res[501];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (A[i - 1] + A[i] >= k) {
            continue;
        }
        res += k - A[i - 1] - A[i];
        A[i] = k - A[i - 1];
    }
    cout << res << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
