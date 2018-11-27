// Steven Kester Yuwono -  UVa 11774
// GCD

#include<bits/stdc++.h>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (b > a) {
		unsigned long long c = b;
		b = a;
		a = c;
	}
	unsigned long long r = a%b;
	return gcd(b, r);
}

int main() {
	int n; scanf("%d", &n);
	int t = n;
	while (t--) {
		unsigned long long a,b; scanf("%lld %lld", &a, &b);
		printf("Case %d: %lld\n", n-t, (a+b) / gcd(a,b));
	}
	return 0;
}
