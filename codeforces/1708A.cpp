#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int first;
		cin>>first;
		int x;
		int flag =1;
		for(int i=1;i<n;i++){
			cin>>x;
			if(x%first){
				flag =0;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}


