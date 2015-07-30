// Steven Kester Yuwono - UVa 11296
#include <cstdio>

int main() {
	unsigned long long n;
	while (scanf("%llu",&n)==1) {
		if (n%2 == 1) n= (n+1)/2;
		else n = (n+2)/2;
		printf("%llu\n",n*(n+1)/2);
	}
	return 0;
}
