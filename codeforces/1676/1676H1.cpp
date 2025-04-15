#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
struct edge{
	int a;
	int b;
};
edge e[200001];
int intersection(edge edge1,edge edge2){
	if(edge1.a==edge2.a){
		return 1;
	}
	if(edge1.b==edge2.b){
		return 1;
	}
	if(edge1.a<edge2.a){
		return edge1.b>edge2.b;
	}
	return edge1.b<edge2.b;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int crossing=0;
		for(int i=1;i<=n;i++){
			int b;
			cin>>b;
			e[i]={i,b};
			for(int j=1;j<i;j++){
				crossing+=intersection(e[j],e[i]);
			}
		}
		cout<<crossing<<endl;
	}
	return 0;
}


