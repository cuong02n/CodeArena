#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a;
	string b;
	cin>>a;
	cin>>b;
	for(int i=0;i<a.length();i++){
		if(a[i]<='Z'&&a[i]>='A'){
			a[i]+=32;
		}
		if(b[i]<='Z'&&b[i]>='A'){
			b[i]+=32;
		}
	}
	cout<<a.compare(b);
	return 0;
}



