// Steven Kester Yuwono - UVa 11490

#include <cstdio>
#include <cmath>
#define MODCONST 100000007

int main () {
	long long S;
	while ((scanf("%lld", &S) == 1) && (S > 0)) {
		long long max = sqrt((double)S + 0.5);
		bool noAnswer = true;
		for (long long i = 1; i <= max; i++) {
			if (S%i != 0) continue;
			long long temp = (S/i) - (i*6);
			if ((temp%7 > 0)|| (temp <= 0)) continue;
			long long side = (temp/7) % MODCONST;
			long long ans = (side*side*2) % MODCONST;
			if (ans > 0) {
				noAnswer = false;
				printf("Possible Missing Soldiers = %lld\n", ans);
			}
		}
		if (noAnswer) printf("No Solution Possible\n");
		printf("\n");
	}
	return 0;
}