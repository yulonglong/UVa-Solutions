// Steven Kester Yuwono - UVa 10784
#include <cstdio>
#include <cmath>

int main() {
	double n; int d = 1;
	while ((scanf("%lf",&n)==1) && (n>0)) {
		double x = ceil((3 + sqrt(8*n+9)) / 2);
		printf("Case %d: %.0lf\n",d++,x);
	}
	return 0;
}
