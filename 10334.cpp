// Steven Kester Yuwono - UVa 10334

#include <cstdio>
using namespace std;

unsigned long long fib[1001];

void init() {
	fib[0] = 1;
	fib[1] = 2;
	for(int i=2;i<=1000;i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
}

int main() {
	init();
	int n;
	while (scanf("%d",&n)==1) {
		printf("%lld\n",fib[n]);
	}
	return 0;
}
