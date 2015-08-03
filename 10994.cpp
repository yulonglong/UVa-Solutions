// Steven Kester Yuwono - UVa 10994
#include <cstdio>

long long summation (long long n) {
	return (n*(n+1))/2;
}

long long sumF(long long x){
	if(x==0) return 0;
	else if(x<10) return summation(x);
	else return sumF(x/10)+(x/10*45)+summation(x%10);
}

int main() {
	long long lower, upper;
	while ((scanf("%lld %lld",&lower,&upper)==2) && (lower>=0 && upper>=0)) {
		printf("%lld\n",sumF(upper)-sumF(lower-1));
	}
	return 0;
}
