/*
  author : NGUYEN MANH CUONG
  created :02-09-22 21:40
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<1<<endl;
		}else if(n==2){
			cout<<4<<endl;
		}else{
			cout<<n+n/2*2+n/3*2<<endl;
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 02-09-22 21:40
*/

