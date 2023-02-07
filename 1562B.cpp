#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
vector<int> D;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		D.clear();
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			char c;
			cin>>c;
			D.push_back((int)c-(int)'0');
		}
		
		int count=0;
		int res =0;
		if(k==1){
			count=1;
			res=D[0];
		}
		if(count==0){
			for(int i=0;i<k;i++){
				if(D[i]==4||D[i]==1||D[i]==6||D[i]==8||D[i]==9){
					count=1;
					res=D[i];
					break;
				}
			}
		}
		if(count==0){
			for(int i=0;i<k;i++){
				if(i==0){
					continue;
				}
				if(D[i]==2||D[i]==5){
					count=2;
					res =D[i-1]*10+D[i];
				}
			}
		}
		if(count==0){
			if(D[0]==2||D[0]==5){
				for(int i=1;i<k;i++){
					if(D[i]==7){
						count=2;
						res=D[0]*10+7;
						break;
					}
				}
				if(count==0){
					count=2;
					res=33;
				}
			}else {
				if(D[0]==3){
					if(D[1]==3){
						count=2;
						res=33;
					}else {//D[1]==7
						if(D[2]==7){
							count=2;
							res=77;
						}else{
							count=2;
							res=33;
						}
					}
				}else{
					if(D[1]==7){
						count=2;
						res=77;
					}else{
						if(D[2]==3){
							count=2;
							res=33;
						}else{
							count=2;
							res=77;
						}
					}
				}
			}
		}
		cout<<count<<endl<<res<<endl<<std::flush;
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

