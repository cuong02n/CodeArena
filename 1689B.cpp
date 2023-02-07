/*
    author : cuong2905say
    created : 22-09-2022  13:14:02  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int n;
int A[1001];
int res[1001];
int check() {
    for (int i = 1; i <= n; i++) {
        if (A[i] == res[i]) {
            return i;
        }
    }
    return -1;
}
void swap(int a, int b) {
    int tmp = res[a];
    res[a] = res[b];
    res[b] = tmp;
}
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            res[i] = i;
        }
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        while (check() != -1) {
            int i = check();
            if (i == n) {
                swap(i, i - 1);
            } else {
                swap(i, i + 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
