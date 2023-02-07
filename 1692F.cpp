#include <bits/stdc++.h>
using namespace std;
set<int> exist;
set<int> need;
int main(){
	int t;// test case 
	cin>>t;
	while(t--){
		int flag =0;
		exist.clear();
		need.clear();
		int n=0;
		cin>>n;
		int number=0;
		cin>>number;
		n--;
		exist.insert(number%10);
		while(n--){
			
			cin>>number;
			number=number%10;
			if(need.find(number%10)!=need.end()){
				flag =1;
			}
			for(set<int>:: iterator i =exist.begin();i!=exist.end();i++){
				need.insert((13-((*i)+number)%10)%10);
//				printf(" \n put : *i :%d number %d need :%d",(*i),number,(13-((*i)+number)%10)%10);
			}
//			for(set<int>:: iterator i =need.begin();i!=need.end();i++){
//				printf("need : %d\n",(*i));
//			}
			exist.insert(number);
			
		}
		
		if(flag ==1){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
