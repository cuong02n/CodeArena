#include <bits/stdc++.h>
using namespace std;
int t=0;//test case
struct building{
	int times;
	int stt;
	int coordinates;
};
vector<building> points;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	while(t--){
		points.clear();
		int n;
		cin>>n;
		unsigned long long sum=0;
		for(int i=1;i<=n;i++){
			building v;
			cin>>v.times;
			v.stt=i;
			points.push_back(v);
		}
		std::sort(points.begin(),points.end(),[](building a, building b){
			return a.times>b.times;
		});
		
		for(int i=0;i<points.size();i++){
			int k=i+1;
			if(k%2){
		 		points[i].coordinates=k/2+1;
			}else{
				points[i].coordinates=-k/2;
			}
			sum+=2ULL*(points[i].times)*abs(points[i].coordinates);
		}
		std::sort(points.begin(),points.end(),[](building a, building b){
			return a.stt<b.stt;
		});
		
		cout<<sum<<endl; 
		cout<<0<< ' ';
		for(int i=0;i<points.size();i++){
			cout<<' '<<points[i].coordinates;
		}
		cout<<endl;
	}
	return 0;
}









/*

	 7MMM.     ,MMF       db       7MN.    7MF  7MMF    7MMF
	  MMMb    dPMM       ;MM:       MMN.    M    MM      MM
	  M YM   ,M MM      ,V^MM.      M YMb   M    MM      MM
	  M  Mb  M' MM     ,M  `MM      M  `MN. M    MMmmmmmmMM
	  M  YM.P'  MM     AbmmmqMA     M   `MM.M    MM      MM
	  M  `YM'   MM    A'     VML    M     YMM    MM      MM
	.JML. `'  .JMML .AMA.   .AMMA. JML.    YM  .JMML.  .JMML.

    .g8"""bgd  7MMF     7MF   .g8""8q.   7MN.   `7MF   .g8"""bgd
 .dP'     `M    MM       M  .dP'    `YM.  MMN.    M  .dP'     `M
 dM'       `    MM       M  dM'      `MM  M YMb   M  dM'       `
 MM             MM       M  MM        MM  M  `MN. M  MM
 MM.            MM       M  MM.      ,MP  M   `MM.M  MM.    `7MMF'
 `Mb.     ,'    YM.     ,M  `Mb.    ,dP'  M     YMM  `Mb.     MM
  `"bmmmd'      `bmmmmd"'    `"bmmd"'   .JML.    YM    `"bmmmdPY

*/

