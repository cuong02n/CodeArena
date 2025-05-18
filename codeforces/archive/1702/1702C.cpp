#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
struct station{
	int begin;
	int value;
	int index;
}; 
bool operator < (station station1,station station2){
	return station1.begin>station2.begin;
}
set<station,less<>> all;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		all.clear();
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;++i){
			
		}
	}
	return 0;
}


