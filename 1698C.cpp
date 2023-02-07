/*
    author : cuong2905say
    created : 15-09-2022  22:22:52  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

vector<long> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int z = 1; z <= t; z++) {
        A.clear();
        int n;
        cin >> n;
        int count0 = 0;
        for (int i = 0; i < n; i++) {
            long x;
            cin >> x;
            if (x == 0) {
                count0++;
            }
            if (x == 0) {
                if (count0 <= 3)
                    A.push_back(x);
            } else {
                A.push_back(x);
            }
        }

        sort(A.begin(), A.end());
        n = A.size();
        int flag = 1;
        if (n < 3) {
            flag = 0;
        }
        if (flag) {
            if (A[0] < 0 && A[1] < 0 && A[2] < 0) {
                flag = 0;
            }
            if (A[n - 1] > 0 && A[n - 2] > 0 && A[n - 3] > 0) {
                flag = 0;
            }
        }
        if (flag) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (i == j) {
                            continue;
                        }
                        if (j == k) {
                            continue;
                        }
                        if (i == k) {
                            continue;
                        }
                        if (find(A.begin(), A.end(), A[i] + A[j] + A[k]) == A.end()) {
                            flag = 0;
                        }
                    }
                }
            }
        }
        cout << (flag ? "YES" : "NO");
        cout << endl;
    }

    system("pause");
    return 0;
}