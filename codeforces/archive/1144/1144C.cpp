/*
    author : cuong2905say
    created : 01-10-2022  21:00:02  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
set<int> res1;
set<int, greater<int> > res2;

void solve() {
    cin >> n;
    int flag = 1;
    res1.clear();
    res2.clear();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (res1.find(x) == res1.end()) {
            res1.insert(x);
        } else {
            if (res2.find(x) != res2.end()) {
                flag = 0;
            } else {
                res2.insert(x);
            }
        }
    }
    if (flag) {
        cout << "YES" << endl;
        cout << res1.size() << endl;
        for (auto x : res1) {
            cout << x << ' ';
        }
        cout << endl;
        cout << res2.size() << endl;
        for (auto x : res2) {
            cout << x << ' ';
        }
        cout << endl;
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
