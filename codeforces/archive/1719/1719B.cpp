#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		k=k%4;
		if(k==0){
			cout<<"NO"<<endl;
		}else if(k==2){
			cout<<"YES"<<endl;
			for(int i=1;i<=n/2;i++){
				if(i%2){
					cout<<2*i<<' '<<2*i-1<<endl;
				}else{
					cout<<2*i-1<<' '<<2*i<<endl;
				}
			}
		}else {
			cout<<"YES"<<endl;
			for(int i=1;i<=n/2;i++){
				cout<<2*i-1<<' '<<2*i<<endl;
			}
		}
	}
	return 0;
}


