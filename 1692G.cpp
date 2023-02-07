#include <stdio.h>
int t;//test case 
int a[200001];
int number_increase[200001];
int main(){
	int t;//test case ;
	scanf("%d",&t);
	while(t--){
		int n=0;
		int k=0;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		number_increase[0]=1;
		int count=0;
		for(int i=1;i<n;i++){
			number_increase[i]=(a[i-1]<a[i]*2)?(number_increase[i-1]+1):1;
			if(number_increase[i]>=k+1){
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
