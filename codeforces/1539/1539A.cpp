#include <bits/stdc++.h>
using namespace std;
int k=0;//test case
void solve(int n,int x,int t){
	if(x>t){
		cout<<0<<endl;
		return ;
	}

	if(n==1){
		cout<<0<<endl;
		return;
	}
	
	int time_per_each=0;
	time_per_each=t/x;
	
	if((n-time_per_each)>=0){
	
		cout<<(1ULL*(n-time_per_each)*time_per_each+1ULL*time_per_each*(time_per_each-1)/2)<<endl;
	}else {
	
		cout<<1ULL*(n)*(n-1)/2<<endl;
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>k;
	while(k--){
		int n,t,x;
		cin>>n>>x>>t;
		solve(n,x,t);
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

