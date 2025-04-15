/*
    author : cuong2905say
    created : 19-09-2022  21:36:41  UTC: +7
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
    int A[106];
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        long long res = 0;
        for (int i = 0; i < k; i++) {
            int _max = INT_MIN;
            for (int j = i; j < n; j += k) {
                _max = max(_max, A[j]);
            }
            res += _max;
        }
        cout << res << endl;
    }
    system("pause");
    return 0;
}
