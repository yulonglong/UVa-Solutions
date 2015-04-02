// Steven Kester Yuwono - UVa 12894

#include <cstdio>
#include <cmath>
#define EPS 1e-9
using namespace std;

int main() {
	int tc; scanf("%d",&tc);
	while (tc--){
		int x0,y0,x1,y1,cx,cy,r;
		scanf("%d %d %d %d %d %d %d",&x0,&y0,&x1,&y1,&cx,&cy,&r);
		double length = x1-x0;
		double width = y1-y0;
		double centerX = (double)x0+(length*9.0/20.0);
		double centerY = (double)y0+(width/2.0);

		if ( (fabs((length/width)-(10.0/6.0)) > EPS) ||
			(fabs((length/(double)r)-5.0) > EPS) ||
			(fabs(centerX-cx) > EPS) ||
			(fabs(centerY-cy) > EPS) )
			printf("NO\n");
		else printf("YES\n");

	}
	return 0;
}