#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		int n;
		int max1=INT_MIN;
		int max2=INT_MIN;
		int min1=INT_MAX;
		int min2=INT_MAX;
		cin>>n;
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			if(max1<=tmp){
				max2=max1;
				max1=tmp;
			}else if(max2<=tmp){
				max2=tmp;
			}
			if(min1>=tmp){
				min2=min1;
				min1=tmp;
			}else if(min2>=tmp){
				min2=tmp;
			}
		}
		cout<<max1+max2-min1-min2<<endl;
	}
	return 0;
}



