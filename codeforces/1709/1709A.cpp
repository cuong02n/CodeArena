#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int A[4];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int x;
		int a,b,c;
		cin>>x>>A[1]>>A[2]>>A[3];
		if(A[x]!=0&&A[A[x]]!=0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}


