/*
  author : NGUYEN MANH CUONG
  created :
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 

long long find_min_EXP2_more_than(long long x){
	int shift =1;
	while(x!=1){
		x>>=1;
		shift++;
	}
	return (1<<shift);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		long long x;
		cin>>x
		long long k=find_min_EXP2_more_than(x);
		if(k-x)
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished:
*/

