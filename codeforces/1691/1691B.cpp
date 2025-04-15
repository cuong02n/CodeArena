/*
    author : cuong2905say
    created : 15-09-2022  20:27:46  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
int A[100001];
vector<int> res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        int flag = 1;
        int n;
        cin >> n;
        res.clear();
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 1, j = 1; i <= n; i = j + 1, j = i) {
            while (A[j] == A[j + 1]) {
                if (j == n) {
                    break;
                }
                j++;
            }
            if (j - i < 1) {
                flag = 0;
                break;
            } else {
                for (int k = i; k < j; k++) {
                    res.push_back(k + 1);
                }
                res.push_back(i);
            }
        }
        if (flag) {
            for (auto x : res) {
                cout << x << ' ';
            }
            cout << endl;

        } else {
            cout << -1 << endl;
        }
    }
    system("pause");
    return 0;
}