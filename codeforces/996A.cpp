#include <bits/stdc++.h>
using namespace std;
int deno[5] = {1,5,10,20,100};
void solve(){
	int n=0;
	cin>>n;
	int res=0;
	for(int i=4;i>=0;i--){
		res+=n/deno[i];
		n=n%deno[i];
	}
	cout<<res<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}


