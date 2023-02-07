#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
vector<char> A;
vector<char> B;
vector<char> C;
void putA(){
	char c =A.back();
	A.pop_back();
	C.push_back(c);
}
void putB(){
	char c =B.back();
	B.pop_back();
	C.push_back(c);
}
void put(int k,int n,int m){
	int _k=0;
	char before='0';
	while(!(A.empty())&&!(B.empty())){
		if(_k==k){
			if(before=='A'){
				putB();
				before='B';
			}else{
				putA();
				before='A';
			}
			_k=1;
		}else{
			if(A.back()<B.back()){
				putA();
				if(before=='A'){
					_k++;
				}else{
					_k=1;
				}
				before='A';
			}else{
				putB();	
				if(before=='B'){
					_k++;
				}else{
					_k=1;
				}
				before='B';
			}
		}
	}
	for(int i=0;i<C.size();i++){
		cout<<C[i];
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		A.clear();
		B.clear();
		C.clear();
		int n;
		int m;
		int k;
		cin>>n>>m>>k;
		char tmp;
		for(int i=0;i<n;i++){
			cin>>tmp;
			A.push_back(tmp);
		}
		for(int i=0;i<m;i++){
			cin>>tmp;
			B.push_back(tmp);
		}
		sort(A.begin(),A.end(),greater<char>());
		sort(B.begin(),B.end(),greater<char>());
		put(k,n,m);
	}
	return 0;
}


