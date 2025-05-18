/*
  author : NGUYEN MANH CUONG
  created : 05-09-22 00:57
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		long long a,b,n,S;
		cin>>a>>b>>n>>S;
		if(a*n+b<S){
			cout<<"NO"<<endl;
		}else{
			if((S%n)<=b){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 05-09-22 00:58
*/

