// Steven Kester Yuwono - UVa 10451
#include <cstdio>
#include <cmath>
#define PI acos(-1.0)

int main() {
	int n; double area;
	int tc = 1;
	while ((scanf("%d %lf",&n,&area)==2) && (n >= 3)) {
		double triangleArea = area/(double)n;
		double angle = 2.0*PI/(double)n;
		double outerRadius = sqrt(2.0*triangleArea/sin(angle));
		double polySide = sqrt((2.0*outerRadius*outerRadius)*(1.0-cos(angle)));
		double height = 2.0*triangleArea/polySide;

		double smallCircleArea = PI*height*height;
		double largeCircleArea = PI*outerRadius*outerRadius;

		printf("Case %d: %.5lf %.5lf\n",tc++,largeCircleArea-area,area-smallCircleArea);
	}
	return 0;
}