#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int _max =INT_MIN;
		int I=0;
		int J=0;
		int x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>x;
				if(_max<x){
					_max = x;
					I=i;
					J=j;
				}
			}
		}
		cout<<max(I,n-I+1)*max(J,m-J+1)<<endl;
	}
	return 0;
}


