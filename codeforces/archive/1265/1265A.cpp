/*
  author : NGUYEN MANH CUONG
  created : 04-09-22 22:18
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		string c;
		cout<<std::flush;
		cin>>c;
		int flag=1;
		for(int i=1;i<c.length()-1;i++){
			if(c[i]=='?'){
				int ia=0;
				int ib=0;
				int ic=0;
				if(c[i-1]=='a'||c[i+1]=='a'){
					ia=1;
				}
				if(c[i-1]=='b'||c[i+1]=='b'){
					ib=1;
				}
				if(c[i-1]=='c'||c[i+1]=='c'){
					ic=1;
				}
				if(ia==0){
					c[i]='a';
				}else if(ib==0){
					c[i]='b';
				}else{
					c[i]='c';
				}
			}else{
				if(c[i-1]==c[i]||c[i]==c[i+1]){
					flag=0;
				}
			}
		}
		if(c.length()==2){
			if(c[1]==c[0]&&c[0]!='?'){
				flag =0;
			}
		}
		if(c[0]=='?'){
			if(c.length()==1){
				c="a";
			}else{
				if(c[1]=='a'){
					c[0]='b';
				}else{
					c[0]='a';
				}
			}
		}
		if(c[c.length()-1]=='?'){
			if(c.length()==1){
				c="a";
			}else{
				if(c[c.length()-2]=='a'){
					c[c.length()-1]='b';
				}else{
					c[c.length()-1]='a';
				}
			}
		}
		
		if(flag){
			cout<<c<<endl;
		}else{
			cout<<-1<<endl;	
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 04-09-22 23:24
*/

