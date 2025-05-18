#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int res;
		cin>>res;
		int x=0;
		int _max=0;
		for(int i=0;i<n;i++){
			cin>>x;
			_max=max(_max,res|x);
		}
		cout<<_max<<endl;
	}
	
	return 0;
}


