#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
/*
_____1___rec
|       |
|       |
|2      |3
|___0___|


*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int x;
		int y;
		cin>>x;
		cin>>y;
			
		int k;
		cin>>k;
		long long max_0=0;
		int tmp0;
		int tmp1;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			if(i==0){
				tmp0=x;
			}else if(i==k-1){
				tmp1=x;
			}
		}
		max_0=tmp1-tmp0;
		
		long long max_1;
		cin>>k;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			if(i==0){
				tmp0=x;
			}else if(i==k-1){
				tmp1=x;
			}
		}
		max_1=tmp1-tmp0;
		
		long long max_2;
		cin>>k;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			if(i==0){
				tmp0=x;
			}else if(i==k-1){
				tmp1=x;
			}
		}
		max_2=tmp1-tmp0;
		
		long long max_3;
		cin>>k;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			if(i==0){
				tmp0=x;
			}else if(i==k-1){
				tmp1=x;
			}
		}
		max_3=tmp1-tmp0;
		
		long long maxX=max(max_0,max_1);
		long long maxY=max(max_2,max_3);
		cout<<max(maxY*x,maxX*y)<<endl;
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

