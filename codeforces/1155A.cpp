/*
    author : cuong2905say
    created : 01-10-2022  19:32:55  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
void solve() {
    cin >> n;
    string A;
    cin >> A;
    int L = -1;
    for (int i = 1; i < n; i++) {
        if (A[i - 1] > A[i]) {
            L = i;
            break;
        }
    }
    if (L != -1) {
        cout << "YES" << endl;
        cout << L << " " << L + 1 << endl;
    } else {
        cout << "NO" << endl;
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
