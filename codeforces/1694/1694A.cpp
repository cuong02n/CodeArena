#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int a;
		int b;
		cin>>a>>b;
		int m=min(a,b);
		for(int i=0;i<m;i++){
			cout<<"10";
		}
		if(b>a){
			for(int i=0;i<b-m;i++){
				cout<<"1";
			}
		}else{
			for(int i=0;i<a-m;i++){
				cout<<"0";
			}
		}
		cout<<endl;
	}
	return 0;
}


