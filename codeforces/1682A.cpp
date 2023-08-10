#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
int count_palindrome(string c,int n){
	if(n%2){
		//n le:
		int count=1;
		char pivot =c.at(n/2);
		for(int i=n/2-1;i>=0;i--){
			if(pivot!=c.at(i)){
				break;
			}
			if(pivot==c.at(i)){
				count+=2;
			}
		}
		return count;
	}
	// n chan :
	char pivot =c.at(n/2);
	int count=0;
	for(int i=n/2;i<n;i++){
		if(pivot!=c.at(i)){
			break;
		}
		if(pivot==c.at(i)){
			count+=2;
		}
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string c;
		cin>>c;
		cout<<count_palindrome(c,n)<<endl;
	}
	return 0;
}


