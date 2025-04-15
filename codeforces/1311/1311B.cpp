/*
    author : cuong2905say
    created : 15-09-2022  16:25:32  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int A[101];
vector<int> P;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int z = 1; z <= t; z++) {
        P.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            P.push_back(x - 1);
        }
        // if (z == 53) {
        //     cout << " A : ";
        //     for (int i = 0; i < n; i++) {
        //         cout << A[i] << ' ';
        //     }
        //     cout << endl;
        //     cout << " P : ";
        //     for (auto x : P) {
        //         cout << x << ' ';
        //     }
        //     cout << endl;
        // }

        std::sort(P.begin(), P.end());
        for (int i = 0, j = 0; i < m; i = j + 1, j = i) {
            int start = P[j];
            while (P[j] == P[j + 1] - 1) {
                if (j == m - 1) {
                    break;
                }

                j++;
            }
            int end = P[j] + 1;
            sort(A + start, A + min(end + 1, n));
        }
        // if (z == 53) {
        //     cout << " A : ";
        //     for (int i = 0; i < n; i++) {
        //         cout << A[i] << ' ';
        //     }
        //     cout << endl;
        //     cout << " P : ";
        //     for (auto x : P) {
        //         cout << x << ' ';
        //     }
        //     cout << endl;
        // }
        cout << flush;
        if (is_sorted(A, A + n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}