// Steven Kester Yuwono - UVa 10387

#include <cstdio>
#include <cmath>
#define PI acos(-1.0)

double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

int main () {
	int a,b,s,m,n;
	while ((scanf("%d %d %d %d %d",&a,&b,&s,&m,&n)==5) && (!(!a&&!b&&!s&&!m&&!n))) {
		double horzSpeed = (double)n*b/(double)s;
		double vertSpeed = (double)m*a/(double)s;
		double speed = sqrt(horzSpeed*horzSpeed + vertSpeed*vertSpeed);
		double angle = acos((vertSpeed*vertSpeed + speed*speed - horzSpeed*horzSpeed) / (2.0*vertSpeed*speed));
		printf("%.2f %.2f\n", RAD_to_DEG(angle), speed);
	}
	return 0;
}