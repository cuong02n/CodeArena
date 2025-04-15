#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int A[51];
int B[51];
int check(int A[],int B[],int n,int m){
	
	for(int i=n-m+1;i<n;i++){
		if(A[i] != B[i-(n-m)])
			return 0;
	}
	for(int i=0;i<=n-m;i++){
		if(A[i]==B[0]){
			return 1;
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n=0;
		int m=0;
		cin>>n>>m;
		char c;
		for(int i=0;i<n;i++){
			cin>>c;
			A[i]=(int)c-(int)'0';
		}
		for(int i=0;i<m;i++){
			cin>>c;
			B[i]=(int)c-(int)'0';
		}
		if(check(A,B,n,m)){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
		cout<<endl;
		
	}
	return 0;
}


