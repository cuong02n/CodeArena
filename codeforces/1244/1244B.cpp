/*
    author : cuong2905say
    created : 26-09-2022  13:54:12  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int A[1001];
void solve() {
    int n;
    cin >> n;
    int last = -1;
    int first = -1;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '1') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    if (first == -1) {
        cout << n << endl;
        return;
    }
    cout << max(2 * last + 2, 2 * (n - first)) << endl;
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
