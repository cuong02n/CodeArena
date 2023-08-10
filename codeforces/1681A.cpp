/*
  author : NGUYEN MANH CUONG
  created :
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int MAXBOB=INT_MIN;
		int MAXALICE=INT_MIN;
		int n,m;
		cin>>n;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			MAXALICE=max(MAXALICE,x);
		}	
		cin>>m;
		for(int i=0;i<m;i++){
			int y;
			cin>>y;
			MAXBOB=max(MAXBOB,y);
		}
		if(MAXALICE==MAXBOB){
			cout<<"Alice\nBob\n";
		}else if(MAXALICE>MAXBOB){
			cout<<"Alice\nAlice\n";
		}else{
			cout<<"Bob\nBob\n";
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished:
*/

