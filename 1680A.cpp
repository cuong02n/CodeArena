/*
  author : NGUYEN MANH CUONG
  created : 05-09-22 13:37
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 
int intersection(int l1,int r1,int l2,int r2){
	if(r1==r2){
		return max(l1,l2);
	}else if(r1>r2){
		if(l1>r2){
			return 0;
		}else {
			return max(l1,l2);
		}
	}else {
		//r1<r2
		if(l2>r1){
			return 0;
		}else{
			return max(l2,l1);
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(intersection(l1,r1,l2,r2)){
			cout<<intersection(l1,r1,l2,r2)<<endl;
		}else{
			cout<<l1+l2<<endl;
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 05-09-22 13:42
*/

