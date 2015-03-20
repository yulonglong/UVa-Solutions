// Steven Kester Yuwono - UVa 12848

#include <cstdio>
#include <algorithm>
using namespace std;

int main (){
	int tc;
	scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		int h1,s,h2;
		scanf("%d %d %d",&h1,&s,&h2);
		int numerator = (h2-1)*s;
		int divisor = h1-1;
		int quotient = numerator/divisor;
		int remainder = numerator%divisor;
		int gcd = __gcd(remainder,divisor);
		printf("Case %d:",d);
		if(quotient> 0){
			printf(" %d",quotient);
		}
		if(remainder > 0) {
			printf(" %d/%d",remainder/gcd,divisor/gcd);
		}
		printf("\n");
	}
}