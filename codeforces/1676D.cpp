#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces
int check(int n,int m,int i,int j){
	if(i==-1||i==n){
		return 0;
	}
	if(j==-1||j==m){
		return 0;
	}
	return 1;
}
int calculate_bishop(int A[200][200],int n,int m,int x,int y){
	int sum=0;
	for(int i=x,j=y;check(n,m,i,j);i++,j++){
		sum+=A[i][j];
	}
	for(int i=x,j=y;check(n,m,i,j);i++,j--){
		sum+=A[i][j];
	}
	for(int i=x,j=y;check(n,m,i,j);i--,j--){
		sum+=A[i][j];	
	}
	for(int i=x,j=y;check(n,m,i,j);i--,j++){
		sum+=A[i][j];
	}
	sum-=3*A[x][y];
	return sum;
}
int A[200][200];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int n=0;
		int m=0;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>A[i][j];
			}
		}
		int _max=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int k =calculate_bishop(A,n,m,i,j);
				_max =max(_max,k);
			}
		}
		cout<<_max<<endl;
	}
	return 0;
}


