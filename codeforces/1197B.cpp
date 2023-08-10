/*
    author : cuong2905say
    created : 27-09-2022  11:08:13  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int A[200001];
void solve() {
    int n;
    cin >> n;
    int m = INT_MIN;
    int I = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > m) {
            I = i;
            m = A[i];
        }
    }
    int flag = 1;
    for (int i = 0; i < I; i++) {
        if (A[i] >= A[i + 1]) {
            flag = 0;
        }
    }
    for (int i = I + 1; i < n; i++) {
        if (A[i - 1] <= A[i]) {
            flag = 0;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
