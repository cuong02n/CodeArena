/*
    author : cuong2905say
    created : 26-09-2022  17:11:55  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
string c[] = {"0", "01", "10", "11", "100", "101", "110", "111", "1000", "1001"};

int _round(int a, int b) {
    if (a % b) {
        return a / b + 1;
    }
    return a / b;
}
void solve() {
    int n;
    cin >> n;
    // if n divisor by 4 , then n/4 last digit should be 8;
    for (int i = 0; i < n - _round(n, 4); i += 1) {
        cout << 9;
    }
    for (int i = 0; i < _round(n, 4); i += 1) {
        cout << 8;
    }
    cout << endl;
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
