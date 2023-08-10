#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int A[100001];
unsigned long long awe =0;
int n;
int m;
void long long query(int i,int x){
	if(A[i]==x){
		return;
	}
	if(i==1){
		if((A[i]!=A[i+1])){
			if(x==A[i+1]){
				awe-=i*(n-i);
			}
		}else{
			if(x!=A[i+1]){
				awe+=i*(n-i);
			}
		}
		A[i]=x;
		return;
	}
	if(i==n){
		if(A[i]!=A[i-1]){
			if(x==A[i-1]){
				awe-=(i-1)*(n-i+1);
			}
		}else{
			if(x!=A[i-1]){
				awe+=(i-1)*(n-i+1);
			}
		}
		A[i]=x;
		return;
	}
	if(A[i-1]==A[i+1]){
		if(A[i]!=A[i+1]){
			if(x==A[i+1]){
				awe-=(i-1+2*i*(n-i));
			}
		}else{
			if(x!=A[i+1]){
				awe+=(i-1+2*i*(n-i));
			}
		}
		A[i]=x;
		return;
	}
	if(A[i-1]==A[i]){
		if()
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	for(int i=1;i<=n;i++){
		if(A[i]!=i){
			query(i,A[i]);
		}
	}
	for(int i=0;i<m;i++){
		int i;
		int x;
		cin>>i>>x;
		query(i,x);
		cout<<awe<<endl;
	}
	return 0;
}



