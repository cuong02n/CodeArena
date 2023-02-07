#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
vector<int> A;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		A.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			A.push_back(x);
		}
		if((A[0] - n)&&(A[n-1] - n)){
			cout<<-1<<endl;
		}else{
			if(A[0] - n){
				for(int i=n-2;i>=0;i--){
					cout<<A[i]<<' ';
				}
				cout<<A[n-1]<<endl;
			}else{
				cout<<A[0]<<' ';
				for(int i=n-1;i>=1;i--){
					cout<<A[i]<<' ';
				}
				cout<<endl;
			}
		}
	}
	return 0;
}


