#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int par[4004];
struct node{
	int par;
	int sumcolor;
};
node Tree[4004];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		Tree[1].par=-1;
		for(int i=2;i<=n;i++){
			cin>>Tree[i].par;
		}
		char c;
		for(int i=1;i<=n;i++){
			cin>>c;
			Tree[i].sumcolor=(c=='W')?1:-1;
		}
		int res=0;
		for(int i=n;i>=2;i--){
			Tree[Tree[i].par].sumcolor+=Tree[i].sumcolor;
			if(Tree[i].sumcolor==0){
				res++;
			}
		}
		if(Tree[1].sumcolor==0){
			res++;
		}
		cout<<res<<endl;
	}
	return 0;
}


