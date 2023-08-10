/*
    author : cuong2905say
    created : 07-10-2022  21:38:10  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int A[25];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 25; i++) {
        A[i] = 0;
    }
    int each = 25;
    each = min(each, n / k);
    string c;
    cin >> c;
    for (int i = 0; i < n; i++) {
        A[c[i] - 'a']++;
    }
    string res = "";
    for (int i = 0; i < k; i++) {
        int j = 0;
        int tmp = 0;
        while (A[j] && (tmp < each)) {
            A[j++]--;
            tmp++;
        }
        res += (char)(j + 'a');
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
