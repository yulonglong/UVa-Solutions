// Steven Kester Yuwono - UVa 11648

#include <cstdio>
#include <cmath>
using namespace std;

int main () {
	int tc; scanf("%d",&tc);
	for(int d=1;d<=tc;d++){ 
		double a, b, left,right;
		scanf("%lf %lf %lf %lf",&b,&a,&left,&right);
		double c = sqrt((a*a + b*b) / 2.0);
		double ltop = (c-a)/(b-a)*left;
		double lbot = left - ltop;
		double rtop = (c-a)/(b-a)*right;
		double rbot = right - rtop;
		printf("Land #%d: %.6lf %.6lf\n",d,lbot,rbot);
	}
	return 0;
}