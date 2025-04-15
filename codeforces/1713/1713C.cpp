#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int A[100001];

void solve(int i,int max , int pivot){//position : n-1
	
	int I=0;
	int done =0;
	for(int j=i;j>=0;j--){
		if(pivot -j >max){
			I=j;
			break;
		}else{
			if(j==0){
				done=1;
			}
			A[j]=pivot-j;
		}
	}
	if((int)sqrt(I)==sqrt(I)){
		pivot =I;
	}else{
		pivot=((int)sqrt(I)+1)*((int)sqrt(I)+1);
	}
	if(!done)
		solve(I,I,pivot);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int pivot=0;
		if((int)sqrt(n-1)==sqrt(n-1)){
			pivot =n-1;
		}else{
			pivot=((int)sqrt(n-1)+1)*((int)sqrt(n-1)+1);
		}
		
		solve(n-1,n-1,pivot);//0-->n-1
		for(int i=0;i<n;i++){
			cout<<A[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}



