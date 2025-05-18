#include <stdio.h>
int t; //test case 
int left[200001];
int right[200001];
int main(){
	scanf("%d",&t);
	while(t--){
		int n;
		int s;
		scanf("%d %d",&n,&s);
		int numberofbit1=0;
		for(int i=0;i<n;i++){
			int bit;
			scanf("%d",&bit);
			if(bit){
				
				numberofbit1++;	
				left[numberofbit1]=i+1;
			}
		}
		for(int i=1;i<=numberofbit1;i++){
			right[i]=n+1-left[numberofbit1+1-i];
		}
//		for(int i=0;i<=numberofbit1;i++){
//			printf("%d ",left[i]);
//		}
//		printf("\n");
//		for(int i=0;i<=numberofbit1;i++){
//			printf("%d ",right[i]);
//		}
		int minimumresult=200001;Rc
		if(s>numberofbit1){
			printf("-1\n");
		}else if(s==numberofbit1){
			printf("0\n");
		}else {
			int wanttoremove =numberofbit1-s;
			for(int i=0;i<=wanttoremove;i++){
				int resultnow = left[i]+right[wanttoremove-i];
				minimumresult=(minimumresult<resultnow)?minimumresult:resultnow;
			}
			printf("%d\n",minimumresult);
		}
		
	}
}
