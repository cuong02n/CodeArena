#include <stdio.h>
int t;// test case 
int a[100001];
int main(){
	scanf("%d",&t);
	while(t--){
		int n =0;
		scanf("%d",&n);
		int odd=0;
		int even=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]%2){
				odd++;
			}else{
				even++;
			}
		}
		if(n==1){
			if(a[0]%2){
				printf("1\n");
			}else{
				printf("0\n");
			}
		}else{
			printf("%d\n",(odd>even)?even:odd);
		}
	}
	return 0;
}
// increase hard : sum of 3 elements consecutive is even : : : : : 
