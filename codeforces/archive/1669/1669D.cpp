#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
char c[100002];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>t;
	while(t--){
		int n;
		cin>>n;
		c[n+1]='W';
		c[0]='W';
		int flag =1;
		int haveR=0;
		int haveB=0;
		int Left_W=0;
		int Right_W=0;
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(c[i]=='R'){
				haveR=1;
			}else if(c[i]=='B'){
				haveB=1;
			}else {
				Left_W=Right_W;
				Right_W=i;
				if((haveR==0)&&(haveB==0)){
					haveR=0;
					haveB=0;	
				}else if((haveR==1)&&(haveB==1)){
					haveR=0;
					haveB=0;
				}else{
					flag =0;
				}
			}
		}
		Left_W=Right_W;
		Right_W=n+1;
		if((haveR==0)&&(haveB==0)){
			haveR=0;
			haveB=0;	
		}else if((haveR==1)&&(haveB==1)){
			haveR=0;
			haveB=0;
		}else{
			flag =0;
		}
		if(flag ){
			cout<<"YES"<<endl;
		}else {
			cout<<"NO"<<endl;
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


