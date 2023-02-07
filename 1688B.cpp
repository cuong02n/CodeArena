#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
int get_min_to_odd(int n){
	int _min=0;
	while(!(n%2)){
		n/=2;
		_min++;
	}
	return _min;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int min_to_odd =INT_MAX;
		int n;
		cin>>n;
		int odd=0;
		int even=0;
		int tmp;
		for(int i=0;i<n;i++){
			cin>>tmp;
			min_to_odd=min(min_to_odd,get_min_to_odd(tmp));
			if(tmp%2){
				odd++;
			}else{
				even++;
			}
		}
		if(odd!=0){
			cout<<even<<endl;
		}else{
			cout<<min_to_odd+even-1<<endl;
		}
	}
	return 0;
}


