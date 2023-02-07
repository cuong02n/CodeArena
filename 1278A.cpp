/*
  author : NGUYEN MANH CUONG
  created : 04-09-22 10:55
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int B[26];
int B_[26];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		string p;
		cin>>p;
		string p_;
		cin>>p_;
		
		for(int i=0;i<26;i++){
			B[i]=0;
			B_[i]=0;
		}
		for(int i=0;i<p.length();i++){
			B[p[i]-'a']++;
		}
//		for(int i=0;i<26;i++){
//			cout<<"B["<<i<<"]" <<" :"<<B[i]<<endl;
//		}
		int have=0;
		for(int i=-1;i<(int)(p_.length()-p.length());i++){
			for(int j=0;j<26;j++){
				B_[j]=0;
			}
			for(int j=i+1;j<i+1+p.length();j++){
				B_[p_[j]-'a']++;
			}
			int flag =1;
			for(int j=0;j<26;j++){
				if(B[j]!=B_[j]){
					flag=0;
				}
			}
//			for(int j=0;j<26;j++){
//				cout<<"i== "<<i<<"B_["<<j<<"]" <<" :"<<B_[j]<<endl;
//			}
			if(flag){
				have=1;
			}
		}
		if(have){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 04-09-22 11:15	
*/

