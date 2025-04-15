/*
    author : cuong2905say
    created : 11-09-2022  00:54:06    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
int A[100001];
int B[100001];
long long dp[100001][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    dp[0][0] = 0;
    dp[0][1] = A[0];
    dp[0][2] = B[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + A[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + B[i];
    }
    cout << max(dp[n - 1][1], dp[n - 1][2]) << endl;
    ;
    system("pause");
    return 0;
}