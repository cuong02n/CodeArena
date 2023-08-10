/*
  author : NGUYEN MANH CUONG
  created : 02-09-22 21:44
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
int A[501][501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		for(int i=0;i<501;i++){
			for(int j=0;j<501;j++){
				A[i][j]=0;
			}
		}
	 	int n,k,r,c;
	 	cin>>n>>k>>r>>c;
	 	int mod =(r-c)%k;
	 	for(int z=0;z<n/k*2;z++){
	 		for(int i=z*k;i>z*k-n;i--){
	 			for(int j=0;j<n;j++){
	 				if(((i-j-mod)%k==0)&&(i>=0&&i<n)){
	 					A[i][j]=1;
					 }
				 }
			 }
		 }
		 for(int i=0;i<n;i++){
		 	for(int j=0;j<n;j++){
		 		if(A[i][j]){
		 			cout<<'X';
				 }else{
				 	cout<<'.';
				 }
				
			 }
			 cout<<endl;
		 }
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 02-09-22 22:13
*/

