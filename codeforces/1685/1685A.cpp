/*
    author : cuong2905say
    created : 15-09-2022  20:40:59  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
int A[100003];
vector<int> res;
int n;
int low1(int i) {
    if (i == 0) {
        return n - 1;
    }
    return i - 1;
}
int up1(int i) {
    if (i == n - 1) {
        return 0;
    }
    return i + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        res.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        sort(A, A + n);
        int flag = 1;
        if (n % 2) {
            flag = 0;
        }
        if (flag) {
            for (int i = 0; i < n / 2; i++) {
                res.push_back(A[i]);
                res.push_back(A[i + n / 2]);
            }
        }
        if (flag) {
            for (int i = 0; i < n; i++) {
                if (1LL * (res[low1(i)] - res[i]) * (res[i] - res[up1(i)]) >= 0) {
                    flag = 0;
                }
            }
        }
        if (!flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (auto x : res) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}