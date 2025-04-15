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
	 	int count=0;
	 	int x=0;
	 	int xbefore=0;
	 	for(int i=0;i<n;i++){
	 		xbefore=x;
	 		cin>>x;
			if(xbefore>x){
				count++;
				xbefore=0;
				x=0;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}


