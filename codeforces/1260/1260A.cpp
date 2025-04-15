/*
  author : NGUYEN MANH CUONG
  created : 05-09-22 00:29
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int c;
		int sum;
		cin>>c>>sum;
		int div =sum/c;
		int r=sum%c;
		cout<<1LL*r*(div+1)*(div+1)+1LL*(c-r)*div*div<<endl;
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 05-09-22 00:34
*/

