#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int A[200001];
int mark[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int pos=-1;
		int n =0;
		cin>> n;
		memset(mark,0,200001);
		for(int i=0;i<n;i++){
			cin>>A[i];
		}	
		for(int i=n-1;i>=0;--i){
			if(mark[A[i]]){
				pos=i;
				break;
			}
			mark[A[i]]=1;
		}
		cout<<pos+1<<endl;
	}
	return 0;
}


