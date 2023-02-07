/*
    author : cuong2905say
    created : 11-09-2022  22:01:04    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;//test case 
template <typename T>
int find_max_digit(T n){
    T _max = 0;
    while(n!=0){
        _max = max(_max, n % 10);
        n /= 10;
    }
    return (int)_max;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    int res = 0;
    while(n!=0){
        n = n - find_max_digit(n);  
        res++;
    }
    
    cout << res << endl;
    system("pause");
    return 0;
}