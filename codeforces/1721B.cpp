#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int check(int n,int m,int sx,int sy,int d){
	if((sx+d<n)&&(sy-d>1)){
		return n+m-2;
	}
	if((sx-d>1)&&(sy+d<m)){
		return n+m-2;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int n=0,m=0,sx=0,sy=0,d=0;
		cin>>n>>m>>sx>>sy>>d;
		cout<<check(n,m,sx,sy,d)<<endl<<std::flush;
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

