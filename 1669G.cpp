#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
char A[51][51];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>t;
	
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>A[i][j];
			}
		}
		for(int j=0;j<51;j++){
			A[n][j]='o';
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(A[i][j]=='*'){
					int lastdigit_dot=i;
					for(int k=i;k<=n;k++){
						if(A[k][j]=='o'){
							break;
						}
						if(A[k][j]=='.'){
							lastdigit_dot=k;
						}
					}
					A[i][j]='.';
					A[lastdigit_dot][j]='*';
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<A[i][j];
			}
			cout<<endl;
		}
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


