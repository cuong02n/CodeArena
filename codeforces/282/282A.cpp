#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x=0;
	cin>>t;
	while(t--){
		char a,b,c;
		cin>>a>>b>>c;
		if(b=='+'){
			x++;
		}else{
			x--;
		}
	}
	cout<<x;
	return 0;
}



