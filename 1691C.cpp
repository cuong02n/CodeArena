/*
    author : cuong2905say
    created : 16-09-2022  22:31:29  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
int A[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, k;
        cin >> n >> k;

        int first_bit1 = -1;
        int last_bit1 = -1;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            A[i] = c - '0';
        }
        // if (z != 63 && t >= 200) {
        //     continue;
        // }
        // if (z == 63) {
        //     cout << n << ' ' << k << endl;
        //     for (int i = 0; i < n; i++) {
        //         cout << A[i] << ' ';
        //     }
        //     cout << " " << endl;
        // }
        for (int i = n - 1; i >= 0; i--) {
            if (A[i] && (last_bit1 == -1)) {
                last_bit1 = i;
            }
        }
        int res = 0;

        int first = A[0];
        int last = A[n - 1];
        // cout << "first_bit1" << first_bit1 << " last_bit1" << last_bit1 << endl;
        if (!last) {
            if (k >= (n - 1 - last_bit1) && last_bit1 != -1) {
                A[last_bit1] = 0;
                A[n - 1] = 1;
                k -= n - 1 - last_bit1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (A[i] && (first_bit1 == -1)) {
                first_bit1 = i;
            }
        }
        if (!first) {
            if (k >= first_bit1 && first_bit1 != -1) {
                A[first_bit1] = 0;
                A[0] = 1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            res += A[i] * 10 + A[i + 1];
        }
        cout << res << endl;
    }
    system("pause");
    return 0;
}