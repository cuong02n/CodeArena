#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int A[5][5];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int I;
	int J;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>A[i][j];
			if(A[i][j]){
				I=i;
				J=j;
			}
		}
	}
	cout<<abs(I-2)+abs(J-2);
	return 0;
}



