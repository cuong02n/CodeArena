#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int compare_str(string s1,string s2,int left,int right){
	//with s1 contains s2;
	for(int i=left;i<=right;i++){
		if(!(s1[i]==s2[i-left])){
			return 0;
		}
	}
	return 1;
}
int divisible(string &s1,string &s2){
	if(s1.length()<=s2.length()){
		string tmp	=s1;
		s1=s2;
		s2=tmp;
	}
	if(s1.length()%s2.length()){
		return 0;
	}
	for(int i=0;i<s1.length();i+=s2.length()){
		if(!compare_str(s1,s2,i,i+s2.length()-1)){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		string s;
		string t;
		cin>>s;
		cin>>t;
		if(s.length()<=t.length()){
			string _s=s;
			s=t;
			t=_s;
		}
		string tmp=s;
		int flag =0;
		for(int i=0;i<t.length();i++){
			if(divisible(s,t)){
				flag =1;
				break;		
			}
			s+=tmp;
		}
		if(flag){
			cout<<s<<endl;
		}else{
			cout<<-1<<endl;
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

