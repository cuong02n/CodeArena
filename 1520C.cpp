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
		if(n==1){
			cout<<1<<endl;
		}else if(n==2){
			cout<<-1<<endl;
		}else if(n==3){
			cout<<"2 9 7\n4 6 3\n1 8 5\n";
		}else if(n==4){
			cout<<"1 10 7 11\n9 2 12 6\n16 13 3 14\n8 5 15 4"<<endl;
		}else {
			for(int i=0;i<n;i++){
				for(int j=n*i+1;j<=n*(i+1);j+=2){
					cout<<j<<' ';
				}
				for(int j=n*i+2;j<=n*(i+1);j+=2){
					cout<<j<<' ';
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

