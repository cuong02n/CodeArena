#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int A[11][11];
int first[11];
int last[11];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>t;
	while(t--){
		for(int i=0;i<11;i++){
			first[i]=0;
			last[i]=0;
			for(int j=0;j<11;j++){
				A[i][j]=0;
			}
		}
		int n;
		long long sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			char f;
			char l;
			cin>>f;
			cin>>l;
			sum=sum-2LL*A[f-'a'][l-'a']+last[l-'a']+first[f-'a'];	
			first[f-'a']++;
			last[l-'a']++;
			A[f-'a'][l-'a']++;
			
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


