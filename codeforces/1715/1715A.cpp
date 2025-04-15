#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n<m){
			int tmp=m;
			m=n;
			n=tmp;
		}
		if(n==1&&m==1){
			cout<<0<<endl;
		}else{
		
			cout<<n-1+2*(m-1)+1<<endl;
		}
	}
	return 0;
}



