// Steven Kester Yuwono - UVa 10347

#include <cstdio>
#include <cmath>
using namespace std;

bool isTriangle(double a, double b, double c) {
	if (( a <= 0) || (b <= 0) || (c <= 0)) return false;
	if ( isnan(a) || isnan(b)|| isnan(c)) return false;
	if (a+b <= c) return false;
	if (b+c <= a) return false;
	if (a+c <= b) return false;
	return true;
}

int main() {
	double ma,mb,mc;
	while (scanf("%lf %lf %lf",&ma,&mb,&mc) == 3 ) {
		double a = sqrt(((8*mb*mb)+(8*mc*mc)-(4*ma*ma))/9.0);
		double b = sqrt(((8*ma*ma)+(8*mc*mc)-(4*mb*mb))/9.0);
		double c = sqrt(((8*mb*mb)+(8*ma*ma)-(4*mc*mc))/9.0);
		// printf("%lf %lf %lf\n",a,b,c);
		double p = (a+b+c)/2.0;
		double area = sqrt(p*(p-a)*(p-b)*(p-c));
		if(!isTriangle(a,b,c)) printf("-1.000\n");
		else printf("%.3lf\n",area);
	}
	return 0;
}