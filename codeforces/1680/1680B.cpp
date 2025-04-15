/*
  author : NGUYEN MANH CUONG
  created : 02-09-22 21:30
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
int A[5][5];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int I=-1,J=-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char x;
				cin>>x;
				if(x=='E'){
					
					A[i][j]=0;
				}else{
					if(I==-1&&J==-1){
						I=i;
						J=j;
					}
					A[i][j]=1;
				}
			}
		}
		int flag =1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(A[i][j]==1){
					if(i<I||j<J){
						flag =0;
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
  finished:02-09-22 21:35
*/

