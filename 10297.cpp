// Steven Kester Yuwono - UVa 10297

#include <cstdio>
#include <cmath>

int main() {
	double PI = acos(-1.0);
	double D,V;
	while ((scanf("%lf %lf",&D,&V)==2) && (D>0) && (V>0)) {
		printf("%.3lf\n",pow(((D*D*D)-(6*V/PI)),1.0/3.0));
	}
	return 0;
}
