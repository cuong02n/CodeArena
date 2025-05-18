// trien khai theo cap so cong

#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(m==1){
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++){
				cout<<i<<endl;
			}
		}else{
			if(n%2){
				//n le
				cout<<"NO"<<endl;
			}else{
				//n chan
				cout<<"YES"<<endl;
				for(int i=1;i<=n;i+=2){
					for(int count=0,j=(i/2)*2*m+1;count<m;j+=2,count+=1){
						cout<<j<<' ';
					}
					cout<<endl;
					for(int count=0,j=(i/2)*2*m+2;count<m;j+=2,count+=1){
						cout<<j<<' ';
					}
					cout<<endl;
				}
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



