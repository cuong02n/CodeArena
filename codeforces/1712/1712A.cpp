#include <bits/stdc++.h>
#define forin for(int i=0;i<n;i++)
#define forjn for(int j=0;j<n;j++)
#define sws ios_base::sync_with_stdio(false)
#define ct0 cin.tie(0)
using namespace std;
int t=0;//test case;
int p[101];
int main(){
	sws;
	ct0;
	cin>>t;
	while(t--){
		int count=0;
		int n=0;
		int k=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>p[i];
			if(i>k){
				if(p[i]<=k){
					count++;
				}
			}
		}		
		cout<<count<<endl;
	}
	return 0;
}


