#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
vector<int> num;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string c;
	cin>>c;
	for(int i=0;i<c.length();i+=2){
		num.push_back((int)c[i]-(int)'0');
	}
	std::sort(num.begin(),num.end());
	cout<<num[0];
	for(int i=1;i<num.size();i++){
		cout<<'+'<<num[i];
	}
	return 0;
}



