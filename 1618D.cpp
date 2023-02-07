/*
    author : cuong2905say
    created : 17-09-2022  15:07:35  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int A[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        sort(A, A + n);
        int sum = 0;
        for (int i = 0; i < n - 2 * k; i++) {
            sum += A[i];
        }
        for (int i = n - 2 * k; i < n - k; i++) {
            sum += A[i] / A[i + k];
        }
        cout << sum << endl;
    }
    system("pause");
    return 0;
}
