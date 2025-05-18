#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int A[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int n;
		int m;
		cin>>n>>m;
		int negative =0;
		int _min=INT_MAX;
		for(int i=0;i<n*m;i++){
			cin>>A[i];
			_min=min(_min,abs(A[i]));
			if(A[i]<0){
				negative++;
			}
		}
		if(negative%2){
			int sum=0;
			for(int i=0;i<n*m;i++){
				sum+=abs(A[i]);
			}
			sum-=2*_min;
			cout<<sum<<endl;
		}else{
			int sum=0;
			for(int i=0;i<n*m;i++){
				sum+=abs(A[i]);
			}
			cout<<sum<<endl;
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

