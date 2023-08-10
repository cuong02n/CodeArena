#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int A[101];
void swap_and_print(int A[],int &x,int n){
	int tmp = A[x];
	A[x]=A[x+1];
	A[x+1]=tmp;
	x++;
	for(int i=1;i<=n;i++){
		cout<<A[i]<<' ';
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		memset(A,0,100);
		int n=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			A[i]=i;
		}
		int x=1;
		cout<<n<<endl;
		for(int i=1;i<=n;i++){
			cout<<A[i]<<' ';
		}
		cout<<endl;
		while(A[n]!=1){
			swap_and_print(A,x,n);
		}
	}
	return 0;
}


