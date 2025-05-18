/*
  author : NGUYEN MANH CUONG
  created : 04-09-22 22:09
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int n;
	cin>>n;
	while(n--){
		int num_even=0;
		int div_by3=0;
		int have0=0;
		string c;
		cin>>c;
		for(int i=0;i<c.length();i++){
			int x=c[i]-'0';
			if(x%2==0){
				num_even++;
			}
			if(x==0){
				have0=1;
			}
			div_by3+=x;
		}
		div_by3=(div_by3%3==0)?1:0;
		if(have0&&div_by3&&(num_even>=2)){
			cout<<"red"<<endl;
		}else{
			cout<<"cyan"<<endl;
		}
		cout<<std::flush;
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished:04-09-22 22:14
*/

