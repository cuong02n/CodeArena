#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
int come[200001];
int finish[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>come[i];
		}
		for(int i=0;i<n;i++){
			cin>>finish[i];
		}
		cout<<finish[0]-come[0]<<' ';
		for(int i=1;i<n;i++){
			cout<<finish[i]-max(finish[i-1],come[i])<<' ';
		}
		cout<<endl;
	}
	return 0;
}


