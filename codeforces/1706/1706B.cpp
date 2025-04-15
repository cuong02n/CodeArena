#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N],b[N],c[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i] = 0;
		c[i] = 0;
	}
	for(int i=1;i<=n;i++){
		if(b[a[i]]==0)
			c[a[i]]++;
		if(b[a[i]]!=0&&(i-b[a[i]]-1)%2==0)
			c[a[i]]++;
		b[a[i]] = i;
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
} 
