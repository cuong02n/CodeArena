#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int is_prime(int n){
	if(!(n%2)){
		return 0;
	}
	if(!(n%3)){
		return 0;
	}
	int k=sqrt(n);
	for(int i=2;i<=k;i++){
		if(!(n%i)){
			return 0;
		}
	}
	return 1;
}
int find_prime_after(int n){
	if(n<=3){
		return 3;
	}
	while(1){
		if(is_prime(n)){
			return n;
		}
		n++;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		long d;
		cin>>d;
		if(d==1){
			cout<<6<<endl;
		}else if(d==2){
			cout<<15<<endl;
		}else {
			int i=find_prime_after(d+1);
			int i2=find_prime_after(i+d);
			cout<<i*i2<<endl;
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

