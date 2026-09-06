/*
    author : cuong2905say
    problem: Codeforces 2259B
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> A) {
    os << "{ " << A.first << ", " << A.second << " }";
    return os;
}

int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    
    int f[4] = {0,0,0,0};
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        f[x%4]++;
    }
    cout<<max(f[1] + f[3], max(f[0] , f[2]))<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
