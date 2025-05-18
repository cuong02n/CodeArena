#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int res =0;
		if(n==1){
			res =2;
		}else if(n==0){
			res =0;
		}else if(n==-1){
			res =2;
		}else{
			if(!(n%3)){
				res =abs(n/3);
			}else{
				res =abs(n/3)+1;
			}
		}
		cout<<res<<endl;	
	}
	return 0;
}


