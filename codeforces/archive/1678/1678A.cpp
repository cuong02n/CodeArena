/*
    author : NGUYEN MANH CUONG
    created : 05-09-2022  23:54:18
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
int A[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int have0 = 0;
        int bangnhau = 0;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            if (A[i] == 0) {
                have0++;
            }
            for (int j = 0; j < i; j++) {
                if (A[i] == A[j]) {
                    bangnhau = 1;
                }
            }
        }

        if (have0) {
            cout << n - have0 << endl;
        } else {
            if (bangnhau) {
                cout << n << endl;
            } else {
                cout << n + 1 << endl;
            }
        }
    }

    return 0;
}