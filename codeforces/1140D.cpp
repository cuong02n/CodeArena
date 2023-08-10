/*
    author : cuong2905say
    created : 29-09-2022  23:50:57  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll f(ll n) {
    if (n == 3) {
        return 6;
    }
    return f(n - 1) + n * (n - 1);
}
void solve() {
    int n;
    cin >> n;
    cout << f((ll)n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
