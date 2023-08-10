/*
  author : NGUYEN MANH CUONG
  created : 04-09-22 22:02
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		long long x;
		cin>>x;
		if(x%14>6||x%14==0||(x<15)){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 04-09-22 22:05
*/

