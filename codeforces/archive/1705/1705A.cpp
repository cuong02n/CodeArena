#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int t=0;//test case if codeforces
int A[202];
int check(int A[],int n,int x){
	for(int i=0;i<n;i++){
		if(A[i+n]-A[i]<x){
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
		int n=0;
		int x=0;
		cin >> n >> x;
		for(int i=0;i<2*n;i++){
			cin>>A[i];
		}
		std::sort(A,A+2*n);
		if(check(A,n,x)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}


