#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int A[100001];
long long damage[100001];
long long solve(int x ,int y){
	if(x==1){
		return damage[y];
	}
	if(x==y){
		return 0;
	}
	if(x>y){
		return solve(y,x)-A[y]+A[x];
	}
	return solve(1,y)-solve(1,x);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
//	cin>>t;
//	while(t--){
	 	int n,m;
	 	cin>>n>>m;
	 	for(int i=1;i<=n;i++){
	 		cin>>A[i];
	 		if(i==1){
	 			damage[1]=0;
	 			continue;
			}
			if(A[i]<A[i-1]){
				damage[i]=damage[i-1]+A[i-1]-A[i];
			}else{
				damage[i]=damage[i-1];
			}
		}
		for(int i=0;i<m;i++){
			int x=0;
			int y=0;
			cin>>x>>y;
			cout<<solve(x,y)<<endl;
		}
//	}
	return 0;
}


