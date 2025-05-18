 //timelimit exceeded 11 :(((

#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces

void get_L_and_R(set<pair<int,int>> map){
	int res=0;
	int tmp=1;//tong so thoa man : tmp = L-R+1;
	int left=(map.begin())->first;
	int F_left=0;
	int right=left;
	int F_right=0;
	for(set<pair<int,int>>::iterator v =map.begin();v!=map.end();v++){
		if(v==map.begin()){
			continue;
		}
		set<pair<int,int>>::iterator prev =--v;
		v++;
		if((v->first)==(prev->first)+1){
			tmp++;//cong them 1 vao so thoa man
			right=(v->first);
			if(res<tmp){
				F_left=left;
				F_right=right;
				res=tmp;
			}
		}else{
			left=v->first;
			right=v->second;
			tmp=1;
		}
	}
	if(res!=0){
		
		cout<<F_left<<' '<<F_right<<endl;
	}else{
		if(map.size()!=0){
			cout<<((map.begin())->first)<<' '<<((map.begin())->first)<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	set<pair<int,int>> map;
	set<int> exist;
	cin>>t;
	while(t--){
		map.clear();
		exist.clear();
		int n=0;
		int k=0;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int founded=1;
			int x;
			cin>>x;
			if(exist.find(x)==exist.end()){
				//chua tim thay
				founded=0;	
			}
			if(founded){
				pair<int,int> v1= {x,-1};
				set<pair<int,int>>::iterator v =upper_bound(map.begin(),map.end(),v1);
				v1={x,(v->second)+1};
				map.erase(v);
				map.insert(v1);
			}else{
				exist.insert(x);
				map.insert({x,1});
			}
		}
		set<pair<int,int>> tmp;
		for(set<pair<int,int>>::iterator v =map.begin();v!=map.end();v++){
			if((v->second)>=k){
				tmp.insert(*v);
//				cout<<"insert : "<<(v->first)<<' '<<(v->second)<<endl;
			}
		}
//		for(set<pair<int,int>>::iterator v =map.begin();v!=map.end();v++){
//			cout<<(v->first)<<' '<<v->second<<endl;
//		}
		get_L_and_R(tmp);
	}
	return 0;
}


