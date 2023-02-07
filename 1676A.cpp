#include <bits/stdc++.h>

using namespace std;
int sum(int t){
	return t/100+(t/10)%10+t%10; 
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(sum(n/1000)==sum(n%1000)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}

