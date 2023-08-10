#include <stdio.h>
int t;
int a[2][2];
int main(){
	scanf("%d",&t);
	while(t--){
		int flag =0;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				scanf("%d",&a[i][j]);
				flag +=a[i][j];
			}
		}
		if(flag ==0){
			printf("0\n");
		}else if(flag ==4){
			printf("2\n");
		}else {
			printf("1\n");
		}
	}
}
