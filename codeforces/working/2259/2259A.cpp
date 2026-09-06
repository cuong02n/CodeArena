/*
    author : cuong2905say
    problem: Codeforces 2259A
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
    int n,k;
    cin >>n>>k;
    string s;
    cin>>s;
    int cnt=n/k;
    for(int i=0;i<n/k;i++){
        // cout<<"farm: "<<i<<endl;
        for(int j = 0;j<k;j++){
            // cout<<"index = "<<i*k+j<<'\n';
            if(s[i*k+j] == '0'){
                // cout<<"index cnt= "<<i*k+j<<'\n';
                cnt--;
                break;
            }
        }
    }
    cout<<cnt<<'\n';
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
