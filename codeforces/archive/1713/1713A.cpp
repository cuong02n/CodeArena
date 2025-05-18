/*
  author : NGUYEN MANH CUONG
  created : 05-09-22 12:47
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
		int XMAX=INT_MIN;
		int YMAX=INT_MIN;
		int XMIN=INT_MAX;
		int YMIN=INT_MAX;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			XMAX=max(x,XMAX);
			YMAX=max(y,YMAX);
			XMIN=min(x,XMIN);
			YMIN=min(y,YMIN);
		}
		
		int moved=0;
		if(XMAX*XMIN>=0){
			moved+=2*max(abs(XMAX),abs(XMIN));
		}else {
			moved+=2*(XMAX-XMIN);
		}
		if(YMAX*YMIN>=0){
			moved+=2*max(abs(YMAX),abs(YMIN));
		}else{
			moved+=2*(YMAX-YMIN);
		}
		cout<<moved<<endl;
		
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished:
*/

