/*
  author : NGUYEN MANH CUONG
  created : 02-09-22 18:41
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i||j){
					cout<<'B';
				}else{
					cout<<'W';
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 02-09-22 18:43
*/

