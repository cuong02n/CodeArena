/*
    author : cuong2905say
    created : 01-10-2022  19:29:40  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
int A[200001];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A, A + n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] >= res + 1) {
            res++;
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
