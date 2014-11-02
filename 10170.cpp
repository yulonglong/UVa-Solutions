//Steven Kester Yuwono - UVa 10170
//Mathematics, number pattern.
//Solve (n*(n+1))/2 - (extra) = D

#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	long long S, D;
	while((scanf("%lld %lld",&S,&D))==2){
		double extra = ((S-1)*S)/2.0;
		double rhs = ((double) D + extra)*2;
		double right = ((sqrt((rhs*4)+1))/2.0)+0.5;
		int ans = right;
		if(right-ans<1e-7){
			ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}