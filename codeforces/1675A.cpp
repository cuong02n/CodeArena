/*
  author : NGUYEN MANH CUONG
  created : 03-09-22 00:31
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int a,b,c,x,y;
		cin>>a>>b>>c>>x>>y;
		if(min(a,x)+min(b,y)+c>=x+y){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 03-09-22 00:33
*/

