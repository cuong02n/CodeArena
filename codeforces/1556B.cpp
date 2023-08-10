/*
    author : cuong2905say
    created : 20-09-2022  16:32:33  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
bool A[100001];
int n;
int count(int start) {
    int res = 0;
    // changed pos even
    // 0 2 4 6 8...
    int pos = start;
    for (int i = 0; i < n; i++) {
        if (A[i]) {
            res += abs(pos - i);
            pos += 2;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        int _true = 0;
        int _false = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2) {
                _false++;
                A[i] = false;
            } else {
                _true++;
                A[i] = true;
            }
        }
        if (abs(_true - _false) > 1) {
            cout << -1 << endl;
            continue;
        }
        // only work with even ;
        if (_true == _false) {
            cout << min(count(0), count(1)) << endl;
            continue;
        }
        if (_true > _false) {
            cout << count(0) << endl;
            continue;
        }
        cout << count(1) << endl;
    }
    system("pause");
    return 0;
}
