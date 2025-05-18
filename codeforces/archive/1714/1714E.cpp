#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int A[200001];
vector<int> begin_not_0_5;
vector<int> begin_with_0_5;
//int plus[]={0,1,0,9,18,5,6,5,14,3};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int plus[]={0,1,0,9,18,5,6,5,14,3};
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int flag =1;
		for(int i=0;i<n;i++){
			cin>>A[i];
			if((A[i]%10)!=5&&(A[i]%10)!=0){
				A[i]=(A[i]+plus[A[i]%10])%20;
			}else if(A[i]%10){
				A[i]=A[i]+5;
			}
			if(i==0){
				continue;
			}
			if(A[i]!=A[i-1]){
				flag =0;
			}
		}	
		if(flag){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
		cout<<endl;
	}
	return 0;
}


