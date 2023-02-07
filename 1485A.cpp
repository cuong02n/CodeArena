#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int integer_part_log(long long a,long long b){
	//log_a(b);
	long long _a=a;
	for(int i=1;i<1000;i++){
		if(a==b){
			return i;
		}
		if(a>b){
			return i-1;
		}
		a*=_a;
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int a;
		int b;
		cin>>a>>b;
		int _min=INT_MAX;
		if(b!=1){
			for(int i=0;i<10;i++){
				_min=min(_min,integer_part_log(b+i,a)+1+i);
			
			}	
			cout<<_min<<endl;
		}else{
			if(a==1){
				cout<<2<<endl;
			}else{
				b=2;
				for(int i=0;i<10;i++){
					_min=min(_min,integer_part_log(b+i,a)+1+i);
				}	
				cout<<_min+1<<endl;
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

