/*
    author : cuong2905say
    created : 19-09-2022  22:40:16  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    vector<int> diff;
    while (t--) {
        int n;
        long x, y;
        diff.clear();
        cin >> n >> x >> y;
        string a;
        cin >> a;
        string b;
        cin >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                diff.push_back(i);
            }
        }
        if ((int)diff.size() % 2) {
            cout << -1 << endl;
        } else {
            long long res = 0;
            if ((int)diff.size() == 2) {
                if (diff[0] + 1 == diff[1]) {
                    res = min(1LL * x, 2LL * y);
                } else {
                    res = y;
                }
                cout << res << endl;
            } else {
                res = 1LL * (long long)((long long)diff.size() / (long long)2) * y;
                cout << res << endl;
            }
        }
        cout << flush;
    }
    system("pause");
    return 0;
}
