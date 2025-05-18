#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces

int main(){
	vector<int> v ;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	cin>>t;
	while(t--){
		v.clear();
		int n=0;
		int q=0;
		cin>>n>>q;
		for(int i=0;i<n;i++){
			int sugar=0;
			cin>>sugar;
			v.push_back(sugar);
		}
		std::sort(v.begin(),v.end(),greater<>());
		for(int i=1;i<n;i++){
			v[i]=v[i]+v[i-1];
		}
		for(int i=0;i<q;i++){
			int need =0;
			cin>>need;
			vector<int>::iterator it = upper_bound(v.begin(),v.end(),need-1);
			if(it==v.end()){
				cout<<-1<<endl;
			}else{
				cout<<it-v.begin()+1<<endl;
			}
		}
	}
	return 0;
}


