#include <bits/stdc++.h>
using namespace std;
int t;
char chess[8][8];
int main(){
	ios::sync_with_stdio(false);
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cin>>chess[i][j];
			}
		}
		f:for(int i=1;i<7;i++){
			for(int j=1;j<7;j++){
				if(chess[i][j]=='#'&&chess[i-1][j-1]=='#'&&chess[i-1][j+1]=='#'&&chess[i+1][j-1]=='#'&&chess[i+1][j+1]=='#'){
					printf("%d %d\n",i+1,j+1);
				}
			}
		}
	}
	return 0;
}
