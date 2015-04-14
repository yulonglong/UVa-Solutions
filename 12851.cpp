// Steven Kester Yuwono - UVa 12851

#include <cstdio>
#include <cmath>
#define PI acos(-1.0)
using namespace std;

double diameterLid(double h, double V) {
	double smallradius = sqrt( (3.0*V*282.0) / (7.0*PI*h) );
	return 4*smallradius;
}

int main (){
	int tc; scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		double h, V;
		scanf("%lf %lf",&h,&V);
		printf("Case %d: %.3lf\n",d,diameterLid(h,V));
	}
	return 0;
}