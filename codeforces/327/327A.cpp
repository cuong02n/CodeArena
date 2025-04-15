/*
    author : cuong2905say
    created : 29-09-2022  23:27:28  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int A[101];
void solve() {
    int n;
    cin >> n;
    int r = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        r += A[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tmp = r;
            for (int k = i; k <= j; k++) {
                if (A[k]) {
                    tmp--;
                } else {
                    tmp++;
                }
            }
            res = max(tmp, res);
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
