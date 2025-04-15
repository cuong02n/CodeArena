#include <bits/stdc++.h>
#include <set>
using namespace std;
int t=0;//test case if codeforces
set<pair<int,int>> alarm ;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		alarm.clear();
		int n=0;
		int H=0;
		int M=0;
		cin>>n>>H>>M;
		int flag =0;
		for(int i=0;i<n;i++){	
			int H_alarm=0;
			int M_alarm=0;
			cin>>H_alarm>>M_alarm;
			if(H_alarm==H&&M_alarm==M){
				flag =1;
			}else{
				alarm.insert({H_alarm,M_alarm});
			}
		}
		if(flag){
			cout<<0<<' '<< 0<<endl;
		}else{
			set<pair<int,int>> :: iterator it;
			pair<int,int> sleep ={H,M};
			it = upper_bound(alarm.begin(),alarm.end(),sleep);
			if(it!=alarm.end()){
				int x1=((*it).first)*60+(*it).second;
				int x2=H*60+M;
				int x3 = x1-x2;
				cout<<(x3/60)<<' '<<(x3%60)<<endl;
			}else{
				pair<int,int> x = *(alarm.begin());
				int x1=(x.first)*60+x.second;
				int x2=H*60+M;
				int x3=x1-x2+1440;
				cout<<(x3/60)<<' '<<(x3%60)<<endl;
			}
		}
		
	}
	return 0;
}


