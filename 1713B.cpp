#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int A[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>A[i];
		}
		int pre=1;
		while(pre<n&&(A[pre]<=A[pre+1])){
			pre++;
		}
		int end=1;
		while(end<(n)&&(A[n-end+1]<=A[n-end])){
			end++;
		}
		if(pre+end>=n+1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}



