/*
    author : cuong2905say
    created : 27-09-2022  11:43:58  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
set<int> A;
void solve() {
    A.clear();
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = A.find(x);
        if (it != A.end()) {
            res += 2;
            A.erase(it);
        } else {
            A.insert(x);
        }
    }
    res += (A.size() + 1) / 2;
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
