#include <bits/stdc++.h>
using namespace std;
int k=0;//test case

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>k;
	while(k--){
		string t="";
		string s="";
		cin>>t;
		cin>>s;
		if(s.length()>1&&(s.find("a") != std::string::npos)){
			cout<<-1<<endl;
		}else{
			if(s.compare("a")==0){
				cout<<1<<endl;
			}else{
				cout<<(unsigned long long)(1ULL<<t.length())<<endl;
			}
		}
	}
	return 0;
}



