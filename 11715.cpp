// Steven Kester Yuwono - UVa 11715
#include <cstdio>
#include <cmath>

int main() {
	int type; int counter = 1;
	while ((scanf("%d",&type)==1) && (type != 0)) {
		printf("Case %d: ",counter++);
		if (type == 1) {
			double u,v,t;
			scanf("%lf %lf %lf",&u,&v,&t);
			double a= (v-u)/t;
			printf("%.3lf %.3lf\n",(v*v-u*u)/(2.0*a),a);
		}
		else if (type == 2) {
			double u,v,a;
			scanf("%lf %lf %lf",&u,&v,&a);
			printf("%.3lf %.3lf\n",(v*v-u*u)/(2.0*a),(v-u)/a);
		}
		else if (type == 3) {
			double u,a,s;
			scanf("%lf %lf %lf",&u,&a,&s);
			double v = sqrt(u*u + 2.0*a*s);
			printf("%.3lf %.3lf\n",v,(v-u)/a);
		}
		else if (type == 4) {
			double v,a,s;
			scanf("%lf %lf %lf",&v,&a,&s);
			double u = sqrt(v*v - 2.0*a*s);
			printf("%.3lf %.3lf\n",u,(v-u)/a);
		}
	}
	return 0;
}
