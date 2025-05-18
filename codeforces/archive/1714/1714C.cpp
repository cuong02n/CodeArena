#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int make(int s){
	int mod =1;
	int res =0;
	for(int i=9;i>=1;i--){
		if((s-i)>=0){
			res+=i*mod;
			s-=i;
			mod*=10;
		}
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int s=0;
		cin>>s;
		cout<<make(s)<<endl;
	}
	return 0;
}


