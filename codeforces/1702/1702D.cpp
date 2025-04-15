#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

vector<int> all;

vector<int> all2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		all.clear();
		all2.clear();
		string c;
		cin>>c;
		int p;
		cin>>p;
		int sum=0;
		for(int i=0;i<c.length();i++){
			all.push_back((int)c[i]-(int)'a'+1);
			sum+=(int)c[i]-(int)'a'+1;
		}
		std::sort(all.begin(),all.end());
		int c1=0;
		int I=0;
		for(int i=all.size()-1;i>=0;i--){
			if(sum<=p){
				I=i;
				c1=all[i];
				break;
			}
			sum-=all[i];
		}
		int count=0;
		for(int i=0;i<=I;i++){
			if(all[i]==c1){
				count++;
			}
		}
		sum=0;
		
		if(c1==0){
			cout<<endl;
		}else{
			for(int i=0;i<c.length();i++){
				if(((int)c[i]-(int)'a'+1)<c1){
					cout<<c[i];
					sum+=(int)c[i]-(int)'a'+1;
				}else if(((int)c[i]-(int)'a'+1)==c1){
					if(count){
						cout<<c[i];
						count--;
					}
				}
			}
			cout<<endl;
		}
	}
	return 0;
}



