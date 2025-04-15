/*
    author : cuong2905say
    created : 27-09-2022  00:15:43  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    string c;
    cin >> c;
    int n = c.length();
    int have1 = 0;
    for (int i = 1; i < c.length(); i++) {
        if (c[i] == '1') {
            have1 = 1;
        }
    }
    if (!have1 && n % 2) {
        n -= 2;
    }
    cout << (n + 1) / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
