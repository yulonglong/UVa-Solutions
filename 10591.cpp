// Steven Kester Yuwono - UVa 10591
#include <cstdio>

long long getHappy(long long num) {
	long long s = 0;
	if (num <= 9) return num;
	while (num != 0) {
		long long currNum = num%10;
		s += currNum*currNum;
		num /= 10;
	}
	return getHappy(s);
}

int main() {
	int tc; scanf("%d",&tc);
	long long n;
	for(int d=1;d<=tc;d++) {
		scanf("%lld",&n);
		printf("Case #%d:",d);
		int currHappy = getHappy(n);
		if ((n==7) || (currHappy == 1) || (currHappy == 7)) {
			printf(" %lld is a Happy number.\n", n);
		}
		else {
			printf(" %lld is an Unhappy number.\n", n);
		}
	}
	return 0;
}
