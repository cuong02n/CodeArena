#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int getDistance(string a,string b,int length){
	int res=0;
	for(int i=0;i<length;i++){
		res+=abs(a.at(i)-b.at(i));
	}
	return res;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int _min = INT_MAX;
		string A[51];
		int n=0;
		int m=0;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>A[i];
			for(int j=0;j<i;j++){
				int z=getDistance(A[i],A[j],m);
				_min=min(_min,z);
			}
		}
		cout<<_min<<endl;
	}
	return 0;
}


