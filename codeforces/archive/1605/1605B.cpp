/*
    author : cuong2905say
    created : 26-09-2022  20:22:14  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
char A[1001];
vector<int> res;
void solve() {
    res.clear();
    int n;
    cin >> n;
    int num0 = 0;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] == '0') {
            num0++;
        }
    }
    // that mean num0 should put in position : 0 1 ... num0 - 1;
    if (is_sorted(A, A + n)) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < num0; i++) {
        if (A[i] == '1') {
            res.push_back(i);
        }
    }
    for (int i = num0; i < n; i++) {
        if (A[i] == '0') {
            res.push_back(i);
        }
    }
    cout << 1 << endl;
    cout << res.size() << " ";
    for (auto x : res) {
        cout << x + 1 << ' ';
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
