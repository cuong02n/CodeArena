#include<bits/stdc++.h>
using namespace std;
int a[20001];
int check(int A[],int n){
	for(int i=0;i<n-1;i++){
		if(A[i]<0){
			return 0;
		}
		A[i+1]=A[i+1]+(A[i]-1);
	}
	return 1;
}
int main(){
	int t;//test case 
	scanf("%d",&t);
	int n;// arr length
	while(t--){
		int sum=0;
		int flag =0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
			if(a[i]){
				flag =1;
			}
			a[i]++;
		}
		a[0]--;//add 1 to all elements which not at the first , mean the pointer should be 
				// at the last element
				// change algorithm
		if((flag==0)||(sum==0&&check(a,n))){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
