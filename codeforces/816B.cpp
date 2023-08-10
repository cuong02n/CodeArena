/*
    author : cuong2905say
    created : 16-10-2022  19:04:38  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 0;
int n = 0;
int A[200001];
int D[200001];
void solve() {
    int k, q;
    cin >> n >> k >> q;
    // D[i]= A[i+1]-A[i];
    // D[l-1] =A[l]-A[l-1];
    // D[l] = A[l+1]-A[l];
    // D[r] = A[r+1]-A[r];
    // D[l-1]
    // A[l]++ ->> D[l]++;
    // A[r]++ ->> D[r]--;
    // 0 0 0 0 0 0 0 0 0 0;
    // 0 0 0 0 0 0 0 0 0 0;

    // 0 0 0 1 1 1 0 0 0 0; // 4->6;
    // 0 0 1 0 0 -1 0 0 0 ; // up 3 , down 6
    // 0 1 0 1 1 1 0 0 0 0 //2
    // 1 -1 1 0 0 -1 0 0 0
    // 1 2 1 2 1 1 0 0 0 0// 1-> 4

    // prefix : D[0] = A[0];
    // -- > D[i] = A[i] - A[i - 1];

    for (int i = 0; i < n + 1; i++) {
        D[i] = 0;
        A[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 0;  // test case ;
    cin >> t;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}

// vi sau con mua dem qua, khong ai nhac ve chuyen doi ta!