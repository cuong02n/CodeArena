#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		switch (n%3){
			case 0:
				cout<<n/3<<' '<<n/3+1<<' '<<n/3-1<<endl;
				break;
			case 1:
				cout<<n/3<<' '<<n/3+2<<' '<<n/3-1<<endl;
				break;
			case 2:
				cout<<n/3+1<<' '<<n/3+2<<' '<<n/3-1<<endl;
				break;
			default:
				break;
		}
		
	}
	return 0;
}


