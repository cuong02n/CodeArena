/*
    author : NGUYEN MANH CUONG
    created : 08-09-2022  21:42:32    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;//test case

int A[21];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int _max = INT_MIN;
        int I = -1;
        for(int i = 1; i < n+1; i++){
            int x;
            cin >> x;
            if(_max<x){
                I = i;
                _max = max(_max, x);
            }
        }
        cout << I << endl;

    }
    system("pause");
    return 0;
}