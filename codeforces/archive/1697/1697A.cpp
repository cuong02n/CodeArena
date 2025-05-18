#include <bits/stdc++.h>
int t; //test case 
int n;
int m;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int cost=0;
		while(n--){
			scanf("%d",&cost);
			m-=cost;
		}
		printf("%d\n",(m>=0)?0:(-m));
	}
	return 0;
}
