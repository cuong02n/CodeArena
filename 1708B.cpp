#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int inDivisor(int i,int l,int r){
	if(r/i*i<=r&&r/i*i>=l){
		return 1;
	}
	return 0;
}
int check(int n,int l,int r){
	for(int i=2;i<=n;i++){
		if(!inDivisor(i,l,r)){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n,l,r;
		cin>>n>>l>>r;
		if(check(n,l,r)){
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++){
				cout<<r/i*i<<' ';
			}
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}


