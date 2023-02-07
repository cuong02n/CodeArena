/*
  author : NGUYEN MANH CUONG
  created : 04-09-22 12:55
*/
#include <bits/stdc++.h>
#define cout(flag) if(flag){cout<<"YES<<endl;}else{cout<<"NO<<endl;}
#define cout_debug(A) for(auto zzz: A){cout<<x<<' ';} cout<<endl;
using namespace std;
int t=0;//test case 
template<typename T>
T find_MEXP(T d){
	if(d==0){
		return 0;
	}
	T shifted_bit=0;
	while(d!=1){
		d>>=1;
		shifted_bit++;
	}
	return d<<shifted_bit;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int A[100001];
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<n-1;i++){
		int _2_t=find_MEXP(n-1-i);
		if(i!=0){
			A[i]+=A[i-1];
		}
		A[i+_2_t]+=A[i];
	}
	for(int i=0;i<n-1;i++){
		cout<<A[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished:
*/


