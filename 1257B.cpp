/*
  author : NGUYEN MANH CUONG
  created : 05-09-22 00:46
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		if((x<=3&&y>3)||(x==1)&&(y>x)){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 05-09-22 00:52
*/

