/*
    author : cuong2905say
    created : 26-09-2022  20:45:21  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
set<int> A;
int ins(int x) {
    if (x == 2048) {
        A.insert(2048);
        return 2048;
    }
    int flag = 1;
    auto it = A.find(x);
    if (it != A.end()) {
        A.erase(it);
        return ins(x << 1);
    } else {
        A.insert(x);
    }
    return x;
}
void solve() {
    A.clear();
    int n;
    cin >> n;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (ins(x) == 2048) {
            flag = 1;
        }
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
