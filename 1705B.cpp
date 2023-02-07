#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int indexstart=0;
		long long cost=0;
		int tmp=0;
		for(int i=0;i<n;i++){
			
			cin>>tmp;
			if(i==n-1){
				break;
			}
			if(indexstart){
				if(tmp){
					cost+=tmp;
				}else{
					cost+=1;
				}
			}else{
				if(tmp){
					indexstart=1;
					cost+=tmp;
				}
			}
			
		}
		cout<<cost<<endl;			
	}
	return 0;
}


