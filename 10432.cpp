// Steven Kester Yuwono - UVa 10432

#include <cstdio>
#include <cmath>
#define PI acos(-1.0)

int main() {
	double r, n;
	while (scanf("%lf %lf",&r,&n) == 2) {
		printf("%.3lf\n", n* 0.5*r*r*sin(2.0*PI/n) );
	}
	return 0;
}