/*
  author : NGUYEN MANH CUONG
  created : 05-09-22 11:09
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 
vector<char> A;
int good[26];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		for(int i=0;i<26;i++){
			good[i]=0;
		}
		A.clear();
		string c;
		cin>>c;
		for(int i=0;i<c.length();i++){
			if(!A.empty()){
				if(A.back()==c[i]){
					A.pop_back();
				}else{
					good[A.back()-'a']=1;
					A.clear();
					A.push_back(c[i]);
				}
			}else{
				A.push_back(c[i]);
			}
		}
		if(A.size()==1){
			good[A[0]-'a']=1;
		}
		
		for(int i=0;i<26;i++){
			if(good[i]){
				cout<<(char)(i+(int)'a');
			}
		}
		cout<<endl;
		
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 05-09-22 12:40
*/

