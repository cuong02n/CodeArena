#include <stdio.h>
#include <string.h>
int t;// test case 
int n;
int m;
int res[51][51];

void putfirst1(int i,int j){
	res[i][j]=1;
	res[i+1][j+1]=1;
	res[i][j+1]=0;
	res[i+1][j]=0;
}

void putfirst0(int i,int j){
	res[i][j]=0;
	res[i+1][j+1]=0;
	res[i][j+1]=1;
	res[i+1][j]=1;
}

void solution(int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		memset(res,0,2500*(sizeof(int)));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n/2;i++){
			for(int j=0;j<m/2;j++){
				if(!((i+j)%2)){
					putfirst1(i*2,j*2);
				}else{
					putfirst0(i*2,j*2);
				}
			}
		}
		solution(n,m);
	}
	return 0;
}
