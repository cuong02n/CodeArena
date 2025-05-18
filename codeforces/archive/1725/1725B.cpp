/*
    author : cuong2905say
    created : 10-09-2022  16:32:07    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;//test case
deque<int> A;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, D;
    cin >> N >> D;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    int WINS = 0;
    std::sort(A.begin(), A.end());
    while(A.size()!=0){
        int MAX = A.back();
        int need = ceil((D + 0.1) / MAX);
        if(A.size()>=need){
            WINS++;
            A.pop_back();
            for(int i = 0; i < need-1; i++){
                A.pop_front();
            }
        }else{
            break;
        }
    }
    cout << WINS << endl;
    system("pause");
    return 0;
}