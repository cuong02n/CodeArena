#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int A[17577];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>t;
	while(t--){
		for(int i=0;i<17577;i++){
			A[i]=0;
		}
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int hash=0;
			char x1;
			char x2;
			char x3;
			cin>>x1>>x2>>x3;
			hash=(x1-'a')*26*26+(x2-'a')*26+x3-'a';
			A[hash]++;
		}
		for(int i=0;i<n;i++){
			int hash=0;
			char x1;
			char x2;
			char x3;
			cin>>x1>>x2>>x3;
			hash=(x1-'a')*26*26+(x2-'a')*26+x3-'a';
			A[hash]+=3;
		}
		for(int i=0;i<n;i++){
			int hash=0;
			char x1;
			char x2;
			char x3;
			cin>>x1>>x2>>x3;
			hash=(x1-'a')*26*26+(x2-'a')*26+x3-'a';
			A[hash]+=5;
		}
		int s1=0,s2=0,s3=0;
		for(int i=0;i<=17576;i++){
			switch( A[i]){
				case 0:
					break;
				case 1:
					s1+=3;
					break;
				case 3:
					s2+=3;
					break;
				case 5:
					s3+=3;
					break;
				case 4:
					s1+=1;
					s2+=1;
					break;
				case 6:
					s1+=1;
					s3+=1;
					break;
				case 8:
					s2+=1;
					s3+=1;
					break;
				default:
					break;
			}
		}
		cout<<s1<<' '<<s2<<' '<<s3<<endl;
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


