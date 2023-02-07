#include <bits/stdc++.h>
#define forin for(int i=0;i<n;i++)
#define forjn for(int j=0;j<n;j++)
#define sws ios_base::sync_with_stdio(false)
#define ct0 cin.tie(0)
using namespace std;
int height[100001];
long long cost_each[100001];
int t=0;//test case

int main(){
	sws;
	ct0;
	cin>>t;
	while(t--){
		long long cost =0;
		int n=0;//number of building::0->n-1
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>height[i];
		}
		for(int i=1;i<n-1;i++){
			cost_each[i]=(height[i]>(max(height[i-1],height[i+1]))?0:(max(height[i-1],height[i+1])-height[i]+1));
		}
		//if n is odd
		if(n%2){
			for(int i=1;i<n;i+=2){
				cost+=cost_each[i];
			}
		}else{//if n is even
			long long tmp_ans=0;
			for(int i=1;i<n-1;i+=2){
				tmp_ans +=cost_each[i];
			}
			cost=tmp_ans;
			for(int i=n-2;i>=1;i-=2){			
				tmp_ans+=cost_each[i];
				tmp_ans-=cost_each[i-1];
				cost=min(tmp_ans,cost);
			}
		}
		cout<<cost<<endl;
	}
	return 0;
}


