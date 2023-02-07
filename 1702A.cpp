#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;//test case ;
	scanf("%d",&t);
	while(t--){
		int m;
		scanf("%d",&m);
		int	roundnumber=1;
		while(roundnumber*10<=m){
			roundnumber*=10;
		}
		printf("%d\n",m-roundnumber);
	}	
	return 0;
}

