#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int a,b,c;
	int count=0;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		if(a+b+c>=2){
			count++;
		}
	}
	cout<<count;
	
	return 0;
}



