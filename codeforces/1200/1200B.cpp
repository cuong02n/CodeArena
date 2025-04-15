/*
    author : cuong2905say
    created : 11-09-2022  10:56:52    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int A[101];
int B[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        // start with m blocks in bag
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            B[i] = 0;
        }
        B[0] = m;
        int flag = 1;
        for (int i = 1; i < n; i++) {
            int need = max(0, A[i] - k);
            B[i] = B[i - 1] + A[i - 1] - max(0, A[i] - k);
            if (B[i] < 0) {
                flag = 0;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    system("pause");
    return 0;
}