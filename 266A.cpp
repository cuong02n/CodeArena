/*
    author : cuong2905say
    created : 30-09-2022  10:19:12  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

char A[51];
void solve() {
    int n;
    cin >> n;
    int last = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (i) {
            if (A[last] == A[i]) {
                res++;
            } else {
                last = i;
            }
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
