/*
    author : cuong2905say
    created : 27-09-2022  00:24:20  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int A[201];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int flag = 0;
    int incr = 0;
    int decr = 0;
    auto up1 = [](int i, int n) {
        if (i == n - 1) {
            return 0;
        }
        return i + 1;
    };
    for (int i = 0; i < n; i++) {
        if (A[i] < A[up1(i, n)]) {
            incr++;
        }
        if (A[i] > A[up1(i, n)]) {
            decr++;
        }
    }
    if (incr <= 1 || decr <= 1) {
        flag = 1;
    }
    cout << (flag ? "YES" : "NO") << endl;
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
