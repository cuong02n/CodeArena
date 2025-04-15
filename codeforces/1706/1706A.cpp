#include <bits/stdc++.h>
int A[51];// dau bai
int B[51];// truong hop con lai : Ai+Bi =m+1
char S[51];
int main(){
	int t;
	//test case ;
	scanf("%d",&t);
	while(t--){
		int n;int m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&A[i]);
			B[i]=m+1-A[i];
			if(A[i]>B[i]){
				int tmp=A[i];
				A[i]=B[i];
				B[i]=tmp;
			}
		}
		for(int i=0;i<51;i++){
			S[i]='B';
		}
		for(int i=0;i<n;i++){
			if(S[A[i]]=='B'){
				S[A[i]]='A';
			}else{
				S[B[i]]='A';
			}
		}
		for(int i=1;i<=m;i++){
			printf("%c",S[i]);
		}
		printf("\n");
	}
//	char c1[2]="A";
//	char c2[2]="B";
// 	printf("%d",strcmp(c1,c2));
	return 0;
}

