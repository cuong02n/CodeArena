/*
    author : cuong2905say
    problem: Codeforces 2259C
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
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int first1 = 1e6;
    int last1 = -1;
    int first_1 = -1;
    int last_1 = -1;


    for(int i = 0; i<n;i++){
        if(a[i] == 1){
            last1 = i;
        }
        if(a[i] == -1){
            last_1 = i;
        }
    }
    for(int i =n-1;i>=0;i--){
        if(a[i] == 1){
            first1 = i;
        }
        if(a[i] == -1){
            first_1 = i;
        }
    }
    if(first_1 ==-1){
        for(int i = 0; i < n; i++){
            cout<<a[i]<< ' ';
        }
        cout<<endl;
        return;
    }

    for(int i = 0; i < n; i++){
        if(a[i] != -1){
            cout << a[i] << ' ';
        } else {
            if((i == first_1 && i < first1) || (i == last_1 && i > last1)){
                cout << 1 << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
    }
    cout << endl;
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
