// Steven Kester Yuwono - UVa 10212
#include <cstdio>
 
int main() {
	long long N,M;
	while (scanf("%lld%lld",&N,&M)==2) {
		long long ans = 1;
		for (long long i=N; i>N-M; i--) {
			ans = ans*i;
			while (ans%10==0) ans/=10;
			ans %= 1000000000;
		}
		printf("%lld\n", ans%10);
	}
	return 0;
}
