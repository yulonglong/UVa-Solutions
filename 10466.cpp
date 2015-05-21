// Steven Kester Yuwono - UVa 10466

#include <cstdio>
#include <cmath>
#define PI acos(-1.0)
#define EPS 1e-9

int main() {
	int n, T;
	while(scanf("%d %d",&n,&T) == 2) {
		double currX = 0;
		double currY = 0;
		for(int i=0;i<n;i++){
			if(i>0) printf(" ");
			double r,t; scanf("%lf %lf",&r,&t);
			double angle = 2.0*PI * (double)T/t;
			currX += r*cos(angle);
			currY += r*sin(angle);
			printf("%.4lf",sqrt(currX*currX+currY*currY));
		}
		printf("\n");
	}
	return 0;
}