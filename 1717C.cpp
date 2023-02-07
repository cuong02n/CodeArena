/*
  author : NGUYEN MANH CUONG
  created : 02-09-22 22:29
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
int A[200001];
int B[200001];
int need[200001];
int add1(int i,int n){
	if(i==n-1){
		return 0;
	}
	return i+1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		for(int i=0;i<n;i++){
			cin>>B[i];
		}
		int flag =1;
		for(int i=0;i<n;i++){
			if(B[i]-A[i]<0){
				flag =0;
				break;
			}else if(B[i]-A[i]==0){
				need[i]=0;
			}else{
				need[i]=1;
			}
		}
		if(flag){
			for(int i=0;i<n;i++){
				if(need[i]==1){
					if(need[add1(i,n)]==1){
						if(B[i]-B[add1(i,n)]>=2){
							flag =0;
							
						}
					}else{
						if(B[i]-B[add1(i,n)]>=2){
							flag =0;
							
						}
						
					}
				}
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 02-09-22 22:46
*/

