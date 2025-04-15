/*
    author : cuong2905say
    created : 23-09-2022  19:11:38  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int A[301];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        sort(A, A + n);
        int res = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            res = min(res, A[i + 1] - A[i - 1]);
        }
        cout << res << endl;
    }
    system("pause");
    return 0;
}
