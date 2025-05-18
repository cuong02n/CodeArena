/*
    author : cuong2905say
    created : 27-09-2022  12:16:49  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    ll k;
    cin >> k;
    int i = 1;
    ll mul = 1;
    while (k - 9 * i * mul > 0) {
        k -= 9 * i * mul;
        i++;
        mul *= 10;
    }
    cout << i << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
