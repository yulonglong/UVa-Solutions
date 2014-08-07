//Steven Kester Yuwono - UVa 12079

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define PI 3.1415926535897932384626433832795 

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		double pie[10010];
		int N,F;
		scanf("%d %d",&N,&F);
		F++;
		int i=0;
		double max=0;
		for(i=0;i<N;i++){
			double r;
			scanf("%lf",&r);
			pie[i]=PI*r*r;
			max=(max > pie[i] ? max : pie[i]);
		}
		//cout << max << endl;
		double hi=max;
		double lo=0;
		double ans=0;
		while(fabs(hi-lo) > 0.0001){
			//printf("A");
			double mid= ((hi+lo)/2.0);
			int count=0;
			for(int i=0;i<N;i++){
				count = count + (pie[i]/mid);
				if(count>=F){
					break;
				}
			}
			if(count>=F){
				ans=mid;
				lo=mid;
			}
			else{
				hi=mid;
			}	
		}
		printf("%.4f\n",ans);
	}
}
