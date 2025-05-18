#include <bits/stdc++.h>
#define forin for(int i=0;i<n;i++)
#define forjn for(int j=0;j<n;j++)
#define sws ios_base::sync_with_stdio(false)
#define ct0 cin.tie(0)
using namespace std;
int t=0;//test case
int main(){
	sws;
	ct0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		cout<<n<<' ';
		for(int i=1;i<=n-1;i++){
			cout<<i<<' ';
		}
		cout<<endl;
	}
	return 0;
}


