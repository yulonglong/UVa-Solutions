// Steven Kester Yuwono - UVa 10589

#include <cstdio>
#include <cmath>

struct point { double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
};

int insideCircle(point p, point c, int r) {
	double dx = p.x - c.x, dy = p.y - c.y;
	double Euc = dx * dx + dy * dy, rSq = r * r;
	return Euc < rSq ? 2 : Euc == rSq ? 1 : 0; //inside/border/outside
}

int main() {
	int N, a;
	while ((scanf("%d %d",&N,&a)==2) && (N>0)) {
		point center1(0,0);
		point center2(0,a);
		point center3(a,0);
		point center4(a,a);

		int M = 0;
		for(int i=0;i<N;i++){
			double x,y; scanf("%lf %lf",&x,&y);
			point random(x,y);
			if( insideCircle(random,center1,a) &&
				insideCircle(random,center2,a) &&
				insideCircle(random,center3,a) &&
				insideCircle(random,center4,a)
				)
			{
				M++;
			}
		}
		double ans = (double)M * (double)a * (double)a / (double)N;
		printf("%.5lf\n",ans);
	}
	return 0;
}
