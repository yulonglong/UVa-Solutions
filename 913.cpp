// Steven Kester Yuwono - UVa 913

#include <cstdio>

int main() {
	unsigned long long input;
	while (scanf("%lld",&input)==1) {
		unsigned long long n = input/2 + 1;
		n = n*n;
		unsigned long long nthNumber = 1 + 2*(n-1);
		printf("%lld\n", nthNumber+(nthNumber-2)+(nthNumber-4));
	}
	return 0;
}
