#include <stdio.h>
#include <string.h>
int mark[1440];
int ispalindrome(int t){
	int hour =t/60;
	int minute =t%60;
	if((hour/10==minute%10)&&(hour%10==minute/10)){
		return 1;
	}
	return 0;
}
int addtotime(int t , int add){
	return (t+add)%1440;
}
int main(){

	int t;// test case;
	scanf("%d",&t);
	
	int bonus;
	while(t--){
		char c[6];
		int palindrome=0;
		memset(mark,0,1440*sizeof(int));
		scanf("%s",c);
		scanf("%d",&bonus);
		int hour =((int)(c[0]-'0'))*10+((int)(c[1]-'0'));
		int minute = ((int)(c[3]-'0'))*10+((int)(c[4]-'0'));
		int timenow =hour*60+minute;
		for(int i=0;i<1440;i++){
			if(mark[timenow]==1){
				break;
			}
			mark[timenow]=1;
			if(ispalindrome(timenow)){
				palindrome++;
			}
			timenow=addtotime(timenow,bonus);
		}
		printf("%d\n",palindrome);
	}
	return 0;
}

