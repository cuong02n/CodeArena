/*
    author : cuong2905say
    created : 16-10-2022  21:36:02  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
int A[51];
char r[51];
int B[51];
void solve() {
    cin >> n;
    for (int i = 0; i < 51; i++) {
        r[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    string c;
    cin >> c;
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (r[A[i]] == 0) {
            r[A[i]] = c[i];
        } else {
            if (r[A[i]] != c[i]) {
                flag = 0;
            }
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
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
