/*
    author : cuong2905say
    created : 27-09-2022  12:05:58  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    string c = "";
    for (int i = 1; i <= 5000; i++) {
        c.append(to_string(i));
    }
    int k;
    cin >> k;
    cout << c[k - 1];
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    solve();

    system("pause");
    return 0;
}
