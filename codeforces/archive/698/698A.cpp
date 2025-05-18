/*
    author : cuong2905say
    created : 10-09-2022  19:34:26    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int A[101];
int dp[101][3];

int _max(int a, int b, int c) {
    return max(max(a, b), c);
}
// day i : choose IT :1 gym :2 , not choose : 0
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        // 1: only it
        // 2 : only gym
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }

    if (A[0] == 0) {
        dp[0][0] = 0;
    } else if (A[0] == 1) {
        dp[0][0] = 0;
        dp[0][1] = 1;
    } else if (A[0] == 2) {
        dp[0][0] = 0;
        dp[0][2] = 1;
    } else {
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 1;
    }

    for (int i = 1; i < n; i++) {
        // dp[i-1][0,1,2]

        if (A[i] == 0) {
            dp[i][0] = _max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = -1;
            dp[i][2] = -1;
        } else if (A[i] == 1) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
            dp[i][0] = _max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = -1;
        } else if (A[i] == 2) {
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][0] = _max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = -1;
        } else {
            // A[i]=3;
            dp[i][0] = _max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }
    }
    int __max = 0;
    for (int i = 0; i < 3; i++) {
        __max = max(__max, dp[n - 1][i]);
    }
    cout << n - __max << endl;
    system("pause");
    return 0;
}