#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
int A[50];
int check(int n,int sum){
	for(int i=0;i<n;i++){
		if((1.0*(sum-A[i])/(n-1))==A[i]){
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
		int n;
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>A[i];
			sum+=A[i];
		}
		
		if(check(n,sum)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}


