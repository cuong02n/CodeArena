#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int A[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int tall=0;
		if(k!=1){
		for(int i=1;i<=n;i++){
				cin>>A[i];
				if(i==1||i==2){
					continue;
				}
				if(A[i-1]>(A[i]+A[i-2])){
					tall++;
				}
			}	
			cout<<tall<<endl;
		}else{
			for(int i=1;i<=n;i++){
				cin>>A[i];
			}
			
			cout<<(n-1)/2<<endl;
		}
	}
	return 0;
}


