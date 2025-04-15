#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int A[200001];//A[k] number of W from i=0 to i=k

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int n;
		int k;
		cin>>n>>k;
		string c;
		cin>>c;
		for(int i=0;i<n;i++){
			if(c[i]=='W'){
				A[i]=1;
			}else {
				A[i]=0;
			}
		}
		for(int i=1;i<n;i++){
			A[i]=A[i]+A[i-1];
		}
		int _min=INT_MAX;
		for(int i=0;i<=n-k;i++){
			if(i==0){
				_min=A[i+k-1];
			}else{
				_min=min(_min,A[i+k-1]-A[i-1]);
			}
		}
		cout<<_min<<endl;
	}
	return 0;
}



