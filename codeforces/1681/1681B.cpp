#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
int A[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		cin>>m;
		int tmp=0;
		long long sum=0;
		for(int i=0;i<m;i++){
			cin>>tmp;
			sum+=tmp;
		}
		cout<<A[sum%n]<<endl;
	}
	return 0;
}


