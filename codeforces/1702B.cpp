#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(){
	set<char> s ;
	int t;// test cases;
	char c;
	scanf("%d",&t);
	while(t--){
		scanf("\n");
		int day=1;
		while(1){
			scanf("%c",&c);
			if(c==32||c==10){
				break;
			}
//			printf("%c ",c);
			if(s.size()==3){
//				printf("size==3 roi");
				if(s.find(c)==s.end()){
					s.clear();
					s.insert(c);
					day++;
				}
			}else{
				if(s.find(c)==s.end()){
					s.insert(c);
//					printf(" inserted %d",s.size());
				}
			}
			
		}
		printf("%d\n",day);
		s.clear();
	}
	return 0;
}

