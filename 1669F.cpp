#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
vector<int> A;
vector<int> B;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>t;
	while(t--){
		A.clear();
		B.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			A.push_back(x);
		}
		B=A;
		for(int i=1;i<n;i++){
			A[i]=A[i]+A[i-1];
		}
		for(int i=n-2;i>=0;i--){
			B[i]=B[i]+B[i+1];
		}
		int sum=0;
		for(int L=0,R=n-1;L<R;){
			if(A[L]==B[R]){
				sum=n-R+L+1;
				L++;
			}else if(A[L]>B[R]){
				R--;
			}else {
				L++;
			}
			
		}
		cout<<sum<<endl;
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


