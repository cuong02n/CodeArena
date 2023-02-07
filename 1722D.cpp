#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int A[200001];
int B[200001];
int C[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long sum_now=0;
		for(int i=0;i<n;i++){
			char c;
			cin>>c;
			if(c=='L'){
				A[i]=i;
			}else {
				A[i]=n-1-i;
			}
			B[i]=n-1-A[i];
			C[i]=B[i]-A[i];
			sum_now+=A[i];
		}
		std::sort(C,C+n,greater<int>());
		for(int i=0;i<n;i++){
			sum_now+=(C[i]>0)?C[i]:0;
			cout<<sum_now<<' ';
		}
		cout<<endl;
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


