#include <bits/stdc++.h>
using namespace std;
int t=0;//test case

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int k;
	cin>>n>>k;
	int a;
	int count=0;
	int pivot=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a;

		if(k==i){
			pivot = a;
		}
		if(pivot==INT_MIN&&a>0){
			count++;
		}else{
			if((pivot==a)&&(a>0)){
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}



