#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int check_equal(string a,string b , int a_start,int b_start,int length){
	for(int i=0;i<length;i++){
		if(a[i+a_start]!=b[i+b_start]){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>t;
	while(t--){
		string a;
		string b;
		cin>>a>>b;
		int _maxStr=0;
		for(int i=0;i<a.length();i++){
			for(int j=1;j<=a.length()-i;j++){
				for(int k=0;k<=(int)b.length()-j;k++){
//					cout<<"checking a_start ="<<i<<" b_start = "<<k<<" length = "<<j<<endl;
					if(check_equal(a,b,i,k,j)){
						_maxStr=max(_maxStr,j);
					}
				}
			}
		}
		cout<<a.length()+b.length()-_maxStr*2<<endl;
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

