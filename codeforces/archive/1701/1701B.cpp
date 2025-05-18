#include <stdio.h>
int t;// test case 
int n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);// length of array
		int first =1;
		int now=first;
		printf("2\n");
		for(int i=0;i<n;i++){
			printf("%d ",now);
			if(now*2<=n){
				now=now*2;
			}else{
				first+=2;
				now=first;
			}
		}
		printf("\n");
	}
}
