/*
  author : NGUYEN MANH CUONG
  created : 05-09-22 01:04
*/
#include <bits/stdc++.h>

using namespace std;
int t=0;//test case 

int A[100001];
int B[100001];
int C[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int flag =1;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		for(int i=0;i<n;i++){
			cin>>B[i];
			C[i]=B[i]-A[i];
		}
		int piv=-1;
		int changed=0;
		for(int i=0;i<n;i++){
			if(C[i]<0){
				flag =0;
				break;
			}
			if(piv==-1){
				if(C[i]>0){
					piv=C[i];
				}
			}else{
				if(C[i]>0&&C[i]!=piv){
					flag=0;
					break;
					
				}
				if(C[i]==0){
					changed++;
				}
			}
			if(changed&&(C[i]>0)){
				flag=0;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished: 05-09-22 01:10
*/

