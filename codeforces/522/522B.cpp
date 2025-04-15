#include <bits/stdc++.h>
using namespace std;
int t=0;//test case if codeforces

int W[200001];//width without wi
int H[200001];//height without hi
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n=0;
	cin>>n;
	int h1=0;
	int h2=0;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>W[i]>>H[i];
		sum+=W[i];
		if(h1<H[i]){
			h2=h1;
			h1=H[i];//h1 : max height
		}else if(h2<H[i]){
			h2=H[i];
		}
	}
	for(int i=0;i<n;i++){
		if(H[i]!=h1){
			cout<<(sum-W[i])*h1<<' ';
		}else{
			cout<<(sum-W[i])*h2<<' ';
		}
	}
	return 0;
}


