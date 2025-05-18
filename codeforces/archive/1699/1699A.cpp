#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;//test case ;
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n%2){
			printf("-1\n");
		}else{
			printf("%d 0 0\n",n/2);
		}
	}
	return 0;
}
