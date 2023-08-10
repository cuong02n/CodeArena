#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 
vector <int> A;
int main(){//consecutive
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		A.clear();
		int n;
		cin >>n;
		if(n==1){
			int x;
			cin>>x;
			cout<<x<<endl;
		}else {
			int _min =INT_MAX;
			for(int i=0;i<n;i++){
				int x;
				cin>>x;
				A.push_back(x);
				_min=min(_min,x);
			}
			std::sort(A.begin(),A.end());
			int _max =INT_MIN;
			for(int i=0;i<n;i++){
				if(i==0){
					continue;
				}
				_max =max (_max , A[i] - A[i-1]);
				
			}
			cout<<max( _min , _max )<<endl;
		}
	}
	return 0;
}


