#include <cstdio>// the longest increase subsequence
#include <set>
using namespace std;
int t;//test case
int n;
int x;//temporatory
set<int> c;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			c.insert(x);
		}
		
		if((n-c.size())%2){
			printf("%d\n",c.size()-1);
		}else {
			printf("%d\n",c.size());
		}
		c.clear();
	}
	return 0;
}

