#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		long long c=n+m;
		if(c%2){
			cout<<"Burenka"<<endl;
		}else{
			cout<<"Tonya"<<endl;
		}
	}
	return 0;
}


