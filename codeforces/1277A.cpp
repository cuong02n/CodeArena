/*
  author : NGUYEN MANH CUONG
  created : 04-09-22 21:36
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 
int find_min_next_BT(int n){// n is BT
	if(n>=1111111111){
		return -1;
	}
	int div=1;
	int s=0;
	for(int i=1;i<10;i++){
		if(n/div<10){
			s=i;
			break;
		}
		div*=10;
	}
	if(n/div==9){
		return n/9*10+1;
	}else{
		return n/(n/div)*(n/div+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	vector<int> A;
	A.clear();
	int x=1;
	while(find_min_next_BT(x)!=-1){
		A.push_back(find_min_next_BT(x));
		x=find_min_next_BT(x);
	}
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int res=-1;
		for(int i=0;i<A.size();i++){
			if(n<A[i]){
				res=i+1;
				break;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 04-09-22 21:57
*/

