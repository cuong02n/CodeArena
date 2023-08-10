#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
int getGCD(int a,int b){
	if (a%b==0){
		return b;
	}
	if(b%a==0){
		return a;
	}
	if(a>b) return getGCD(b,a%b);
	return getGCD(a,b%a);
}
void PSTG(int &a,int &b){
	if(getGCD(a,b)==1){
		return ;
	}
	int _a=a;
	int _b=b;
	a=a/getGCD(_a,_b);
	b=b/getGCD(_a,_b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
//		if(a==0){
//			if(c==0){
//				cout<<0<<endl;
//			}else{
//				cout<<1<<endl;
//			}
//		}else{
//			if(c==0){
//				cout<<1<<endl;
//			}else{
//				PSTG(a,b);
//				PSTG(c,d);
//				int count=0;
//				if(a!=c){
//					if(a%c==0||c%a==0){
//						count++;
//					}else{
//						count+=2;
//					}
//				}
//				if(b!=d){
//					if((b%d==0)||(d%b)==0){
//						count++;
//					}else{
//						count+=2;
//					}
//				}
//				cout<<count<<endl;
//			}
//		}
		
		if(a==0){
			if(c==0){
				cout<<0<<endl;		
			}else{
				cout<<1<<endl;
			}
		}else{
			//a!=0;
			if(c==0){
				cout<<1<<endl;
			}else{
				if((a*d)==(b*c)){
					cout<<0<<endl;
				}else if((a*d)%(b*c)==0){
					cout<<1<<endl;
				}else if((b*c)%(a*d)==0){
					cout<<1<<endl;
				}else{
					cout<<2<<endl;
				}
			}
		}
	}

	return 0;
}



