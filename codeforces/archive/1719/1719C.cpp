#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int place[200001];//start index 0
int times_win[200001];//start index 0
struct info{
	//info each round ;
	int round;
	int place_win;
};
struct cmp{
	bool operator ()(const pair<info,int>& i1,const pair<info,int>& i2) const {
		if(i1.first.place_win==i2.first.place_win){
			return i1.first.round>i2.first.round;
		}
		
		return i1.first.place_win>i2.first.place_win;
		
	}
};

set<pair<info,int> ,cmp> demo;
deque<int> A;
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		demo.clear();
		A.clear();
		int n,q;
		cin>>n>>q;
		for(int i=0;i<=n;i++){
			times_win[i]=0;
		}
		int f=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			A.push_back(x);
			if(x==n){
				f=i;
			}
			place[x]=i;
		}
		//f : index where the strongest A first
		//0<= f <= n-1
		for(int i=1;i<=f;i++){// O(n) time complexity
			int x=A.front();
			A.pop_front();
			int y=A.front();
			A.pop_front();
			if(x>y){
				//x win:
				A.push_back(y);
				A.push_front(x);
				times_win[place[x]]++;
				demo.insert({{i,1+place[x]},times_win[place[x]]});
			}else {
				
				A.push_front(y);
				A.push_back(x);
				times_win[place[y]]++;
				demo.insert({{i,1+place[y]},times_win[place[y]]});
			}
		}
//		for(auto it =demo.begin();it!=demo.end();it++){
//			cout<<"{ round :"<<(it->first).round<<"  place _win:"<<(it->first).place_win<<"} , times_win: "<<(it->second)<<endl;
//		}
//		cout<<endl;
		for(int i=0;i<q;i++){
			int p,r;
			cin>>p>>r;
			if(r>f&&(p-1==f)){
				cout<<times_win[f]+r-f<<endl;
			}else{
				r=min(r,f);
				auto it=demo.lower_bound({{r,p},-1});
				
				if((it->first).place_win!=p){
					cout<<0<<endl;
				}else{
					cout<<(it->second)<<endl;
				}
			}
			
		}
		
	}
	return 0;
	//02-09-22 17:24
}
















/*

	 7MMM.     ,MMF       db       7MN.    7MF  7MMF    7MMF
	  MMMb    dPMM       ;MM:       MMN.    M    MM      MM
	  M YM   ,M MM      ,V^MM.      M YMb   M    MM      MM
	  M  Mb  M' MM     ,M  `MM      M  `MN. M    MMmmmmmmMM
	  M  YM.P'  MM     AbmmmqMA     M   `MM.M    MM      MM
	  M  `YM'   MM    A'     VML    M     YMM    MM      MM
	.JML. `'  .JMML .AMA.   .AMMA. JML.    YM  .JMML.  .JMML.

    .g8"""bgd  7MMF     7MF   .g8""8q.   7MN.   `7MF   .g8"""bgd
 .dP'     `M    MM       M  .dP'    `YM.  MMN.    M  .dP'     `M
 dM'       `    MM       M  dM'      `MM  M YMb   M  dM'       `
 MM             MM       M  MM        MM  M  `MN. M  MM
 MM.            MM       M  MM.      ,MP  M   `MM.M  MM.    `7MMF'
 `Mb.     ,'    YM.     ,M  `Mb.    ,dP'  M     YMM  `Mb.     MM
  `"bmmmd'      `bmmmmd"'    `"bmmd"'   .JML.    YM    `"bmmmdPY

*/


