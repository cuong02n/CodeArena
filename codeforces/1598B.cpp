#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int A[1001][6];
void solve(int n){

	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			if(i==j){
				continue;
			}
			int both1=0;
			int onlyi=0;
			int onlyj=0;
			for(int k=0;k<n;k++){
				if(A[k][i]==A[k][j]&&A[k][i]==1){
					both1++;
				}else if(A[k][i]==1){
					onlyi++;
				}else if(A[k][j]==1){
					onlyj++;
				}
			}
			if(min(onlyi,n/2)+min(onlyj,n/2)+both1>=n){
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=1;j<=5;j++){
				cin>>A[i][j];
			}
		}
		solve(n);
	}
	return 0;
}















/*

	 7MMM.     ,MMF       db       7MN.    7MF  7MMF    7MMF
	  MMMb    dPMM       ;MM:       MMN.    M    MM      MM
	  M YM   ,M MM      ,V^MM.      M YMb   M    MM      MM
	  M  Mb  M' MM     ,M  `MM      M  `MN. M    MMmmmmmmMM
	  M  YM.P'  MM     AbmmmqMA     M   `MM.M    MM      MM
	  M  `YM'   MM    A'     VML    M     YMM    MM      MM
	.JML. `'  .JMML .AMA.   .AMMA. JML.    YM  .JMML.  .JMML.

    .g8"""bgd  7MMF     7MF   .g8""8q.   7MN.   `7MF   .g8"""bgd
 .dP'     `M    MM       M  .dP'    `YM.  MMN.    M  .dP'     `M
 dM'       `    MM       M  dM'      `MM  M YMb   M  dM'       `
 MM             MM       M  MM        MM  M  `MN. M  MM
 MM.            MM       M  MM.      ,MP  M   `MM.M  MM.    `7MMF'
 `Mb.     ,'    YM.     ,M  `Mb.    ,dP'  M     YMM  `Mb.     MM
  `"bmmmd'      `bmmmmd"'    `"bmmd"'   .JML.    YM    `"bmmmdPY

*/

