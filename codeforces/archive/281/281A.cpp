#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string c;
	cin>>c;
	if(c[0]<='z'&&c[0]>='a'){
		c[0]-=32;
	}
	cout<<c;
	return 0;
}



