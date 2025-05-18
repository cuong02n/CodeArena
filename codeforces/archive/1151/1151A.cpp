/*
    author : cuong2905say
    created : 01-10-2022  19:59:45  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
string c;
int f(char z, char T) {
    int r = min(26 - abs(z - T), abs(z - T));
    return r;
}
int cal(int i) {
    return f(c[i], 'A') + f(c[i + 1], 'C') + f(c[i + 2], 'T') + f(c[i + 3], 'G');
}
void solve() {
    cin >> n;
    cin >> c;
    int m = INT_MAX;
    for (int i = 0; i < n - 3; i++) {
        m = min(m, cal(i));
    }
    cout << m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
