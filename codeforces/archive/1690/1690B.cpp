#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int A[50001];
int B[50001];
int sol(int n,int _max){
	for(int i=0;i<n;i++){
		if(A[i]<B[i]){
			return 0;
		}
		if(B[i]==0){
			continue;
		}
		if((A[i]-B[i])!=_max){
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
		int n;
		cin>>n;
		int _max=INT_MIN;
		for(int i=0;i<n;i++){
			cin>>A[i];	
		}
		for(int i=0;i<n;i++){
			cin>>B[i];
			_max=max(A[i]-B[i],_max);
		}
		if(sol(n,_max)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}


