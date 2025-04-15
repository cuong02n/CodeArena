/*
  author : NGUYEN MANH CUONG
  created :04-09-22 10:08
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
vector<int> A;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		A.clear();
		int n;
		cin>>n;
		for(int i=0;i<2*n;i++){
			int x;
			cin>>x;
			A.push_back(x);
		}
		std::sort(A.begin(),A.end());
		cout<<A[n]-A[n-1]<<endl;
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 04-09-22 10:37
*/

