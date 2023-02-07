#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int A[200001];
int check(int A[],int i,int x,int &min_before,int &max_before){
	max_before=max(max_before,A[i]);
	min_before=min(min_before,A[i]);
	if(max_before-min_before>(x<<1)){
//		cout<<"changed i = "<<i<<endl;
		max_before =A[i];
		min_before =A[i];
		return 1;
		
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n=0;
		int x=0;
		cin>>n>>x;
		int min_before =INT_MAX;
		int max_before =0;
		int changed=0;
		for(int i=0;i<n;i++){
			cin>>A[i];
			if(check(A,i,x,min_before,max_before)){
				changed++;
			}	
		}	
		cout<<changed<<endl;
	}
	return 0;
}


