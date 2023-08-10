/*
  author : NGUYEN MANH CUONG
  created : 02-09-22 21:25
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
int A[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		std::sort(A,A+n,greater<int>());
		for(int i=0;i<n;i++){
			cout<<A[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 02-09-22 21:27
*/

