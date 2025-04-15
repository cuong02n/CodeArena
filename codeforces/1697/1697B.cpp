#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
vector <long long>cost;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cost.clear();
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		int tmp=0;
		cin>>tmp;
		cost.push_back(tmp);
	}
	
	std::sort(cost.begin(),cost.end(),greater<long long>());
	for(int i=1;i<n;i++){
		cost[i]+=cost[i-1];
	}
	
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<cost[x-1]<<endl;
		}else{
			cout<<cost[x-1]-cost[x-y-1]<<endl;
		}
	}
	return 0;
}



