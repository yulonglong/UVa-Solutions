// Steven Kester Yuwono - UVa 12748

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point_i { int x, y;     // whenever possible, work with point_i
	point_i() { x = y = 0; }                      // default constructor
	point_i(int _x, int _y) : x(_x), y(_y) {} };          // constructor

struct point { double x, y;   // only used if more precision is needed
	point() { x = y = 0.0; }                      // default constructor
	point(double _x, double _y) : x(_x), y(_y) {} };      // constructor

int insideCircle(point_i p, point_i c, int r) { // all integer version
	int dx = p.x - c.x, dy = p.y - c.y;
	int Euc = dx * dx + dy * dy, rSq = r * r;             // all integer
	return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; } //inside/border/outside

bool circle2PtsRad(point p1, point p2, double r, point &c) {
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
							(p1.y - p2.y) * (p1.y - p2.y);
	double det = r * r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return true; }         // to get the other center, reverse p1 and p2

int main() {
	int tc;
	scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		int n,m;
		scanf("%d %d",&n,&m);

		vector<pair<point_i,int> > router;
		for(int i=0;i<n;i++){
			int x,y,r;
			scanf("%d %d %d",&x,&y,&r);
			point_i pt(x,y);
			router.push_back(pair<point_i,int>(pt,r));
		}

		vector<point_i> location;
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			point_i pt(x,y);
			location.push_back(pt);
		}
		
		printf("Case %d:\n",d);
		for(int i=0;i<(int)location.size();i++){
			bool valid = false;
			for(int j=0;j<(int)router.size();j++){
				point_i center = router[j].first;
				int radius = router[j].second;
				point_i person = location[i];
				int inside = insideCircle(person,center,radius);
				if ((inside == 0)||(inside == 1)) { // 0-inside ; 1-at border ; 2-outside
					valid = true;
					break;
				}
			}
			if(valid) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
