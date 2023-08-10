#include <bits/stdc++.h>

using namespace std;
int A[50];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int min=1e8;
		for(int i=0;i<n;i++){
			scanf("%d",&A[i]);
			min=(A[i]<min)?A[i]:min;
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=A[i]-min;
		}
		printf("%d\n",sum);
	}
	return 0;
}

