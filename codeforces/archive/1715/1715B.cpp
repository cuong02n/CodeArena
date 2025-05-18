#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
unsigned long long A[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		unsigned long long n=0,k=0,b=0,s=0;
		
		cin>>n>>k>>b>>s;
		if((b*k<=s)&&(s<=b*k+n*(k-1))){
			unsigned long long surplus =s-b*k;
			for(int i=0;i<n;i++){
				A[i]=0;
			}
			A[0]=b*k;
			for(int i=0;i<n;i++){
				if(surplus==0){
					break;
				}
				if(surplus<=k-1){
					A[i]+=surplus;
					surplus=0;
				}
				if(surplus>=k){
					A[i]+=k-1;
					surplus-=k-1;
				}
			}
			for(int i=0;i<n;i++){
				cout<<A[i]<<' ';
			}
			cout<<endl;
			
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}



