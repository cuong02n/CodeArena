/*
    author : cuong2905say
    created : 11-09-2022  22:22:50    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;//test case
int A[101];
int B[101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, N;
    cin >> n >> N;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < 101; i++){
        B[i] = -1;
    }
    // B[i] : cost between A[i] and A[i+1] if exist, otherwise, -1;
    // start index : 0;
    int val = 0;
    for(int i = 0; i < n; i++){
        if(A[i]%2){
            val++;
        }else{
            val--;
        }
        if(val==0){
            B[i] = abs(A[i] - A[i + 1]);
        }
    }
    vector<int> _B;
    for(int i = 0; i < n-1; i++){
        if(B[i]>=0){
            _B.push_back(B[i]);
        }
    }
    std::sort(_B.begin(), _B.end());
    int res = 0;
    for(int i = 0; i < _B.size(); i++){
        if(N-_B[i]>=0){
            N -= _B[i];
            res++;
        }else{
            break;
        }

    }
    cout << res << endl;

    system("pause");
    return 0;
}