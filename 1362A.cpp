#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int is2exp(unsigned long long b){
	for(int i=0;i<63;i++){
		if((1ULL<<i)==b){
			return i;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>t;
	while(t--){
		unsigned long long a,b;
		cin>>a>>b;
		if(a<b){
			unsigned long long tmp=a;
			a=b;
			b=tmp;
		}
		if(a%b==0){
			
			int i=is2exp(a/b);
			if(i==-1){
				cout<<-1<<endl;
			}else if(i%3){
				cout<<i/3+1<<endl;
			}else{
				cout<<i/3<<endl;
			}
		}else{
			cout<<-1<<endl;
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

