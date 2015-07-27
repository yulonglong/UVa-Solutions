// Steven Kester Yuwono - UVa 10079

#include <cstdio>

int main() {
	long long n;
	while ((scanf("%lld",&n)==1) && (n>=0)){
		printf("%lld\n",(n*(n+1))/2+1);
	}
	return 0;
}
