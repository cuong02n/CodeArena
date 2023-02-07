/*
    author : cuong2905say
    created : 12-09-2022  21:59:22    UTC: +7
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#endif
using namespace std;
int t = 0;  // test case

vector<int> A[26];  // 0: 'a' , 25: 'z'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        string c;
        cin >> c;
        int n = c.length();
        for (int i = 0; i < 26; i++) {
            A[i].clear();
        }
        int cost_max = abs(c[n - 1] - c[0]);
        for (int i = 0; i < n; i++) {
            if ((c[i] - c[0]) * (c[i] - c[n - 1]) <= 0) {
                A[c[i] - 'a'].push_back(i + 1);
            }
        }
        cout << cost_max << ' ';
        int _max = 0;
        if (c[n - 1] >= c[0]) {
            // tang dan
            for (int i = 0; i < 26; i++) {
                _max += A[i].size();
            }
            cout << _max << endl;
            for (int i = c[0] - 'a'; i <= c[n - 1] - 'a'; i++) {
                for (int j = 0; j < A[i].size(); j++) {
                    cout << A[i][j] << ' ';
                }
            }
        } else {
            // giam dan
            for (int i = 0; i < 26; i++) {
                _max += A[i].size();
            }
            cout << _max << endl;
            // cout << "f " << c[0] - 'a' << " last " << c[n - 1] - 'a' << endl;
            for (int i = c[0] - 'a'; i >= c[n - 1] - 'a'; i--) {
                // cout << "\tsize" << A[i].size() << endl;
                for (int j = 0; j < A[i].size(); j++) {
                    cout << A[i][j] << ' ';
                }
            }
        }
        cout << ' ' << endl;
    }
    system("pause");
    return 0;
}