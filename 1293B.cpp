/*
  author : NGUYEN MANH CUONG
  created : 04-09-22 10:51
*/
#include <bits/stdc++.h>
using namespace std;
int t=0;//test case 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	
	int n;
	cin>>n;
	double sum=0;
	for(int i=1;i<=n;i++){
		sum+=1.0/i;
	}
	cout<<sum<<endl;

	return 0;
}
/*
  author: NGUYEN MANH CUONG
  finished:
*/

