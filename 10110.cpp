// Steven Kester Yuwono - UVa 10110

#include <cstdio>
#include <cmath>
using namespace std;

bool isPerfectSq(unsigned long long n) {
	unsigned long long root = round(sqrt(n));
	if (n == root*root) return true;
	return false;
}

int main() {
	unsigned long long input;
	while ((scanf("%ld",&input)==1) && (input>0)) {
		if (isPerfectSq(input)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
