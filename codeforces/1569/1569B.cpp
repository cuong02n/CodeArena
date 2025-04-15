#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int A[51];//type of players
		int mark[51];
		int B[51][51];//result with other players 
		for(int i=0;i<51;i++){
			for(int j=0;j<51;j++){
				B[i][j]=0;
			}
		}
		int n;
		cin>>n;
		int who_need_win =0;
		for(int i=1;i<=n;i++){
			char c;
			cin>>c;
			if(c=='2'){
				who_need_win++;
			}
			A[i]=(int)c-(int)'0';
		}
		for(int i=1;i<=n;i++){
			mark[i]=A[i];
		}
		if(who_need_win==1||who_need_win==2){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++){
				if(A[i]==1){// unbeaten
					for(int j=1;j<=n;j++){
						if(i!=j){
							B[i][j]=2;
							B[j][i]=2;
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(A[i]==2){//at least 1 win
				int has_win=0;
					for(int j=1;j<=n;j++){
						if(i!=j){
							if(B[i][j]==0){
								//try to at least 1 win
								if(has_win){
									B[i][j]=1;
									B[j][i]=3;
								}else {
									B[i][j]=3;
									B[j][i]=1;
									has_win=1;
								}
							}else if(B[i][j]==3){
								has_win=1;
							}
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j){
						cout<<'X';
					}else if(B[i][j]==1){
						cout<<'-';
					}else if(B[i][j]==2){
						cout<<'=';
					}else if(B[i][j]==3){
						cout<<'+';
					}
				}
				cout<<endl;
			}
			
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

