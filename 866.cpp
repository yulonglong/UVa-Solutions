// Steven Kester Yuwono - UVa 866

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point { double x, y;   // only used if more precision is needed
	point() { x = y = 0.0; }                      // default constructor
	point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
	bool operator < (point other) const { // override less than operator
		if (fabs(x - other.x) > EPS)                 // useful for sorting
			return x < other.x;          // first criteria , by x-coordinate
		return y < other.y; }          // second criteria, by y-coordinate
	// use EPS (1e-9) when testing equality of two floating points
	bool operator == (point other) const {
	 return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

double dist(point p1, point p2) {                // Euclidean distance
											// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
	double rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
	return point(p.x * cos(rad) - p.y * sin(rad),
							 p.x * sin(rad) + p.y * cos(rad)); }

struct line { double a, b, c; };          // a way to represent a line

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
		l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
	} else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
		l.c = -(double)(l.a * p1.x) - p1.y;
} }

bool areParallel(line l1, line l2) {       // check coefficients a & b
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) return false;            // no intersection
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else                  p.y = -(l2.a * p.x + l2.c);
	return true; }

struct vec { double x, y;  // name: `vec' is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
	return vec(v.x * s, v.y * s); }               // shorter.same.longer

point translate(point p, vec v) {        // translate p according to v
	return point(p.x + v.x , p.y + v.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p, point a, point b, point &c) {
	// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));                  // translate a to c
	return dist(p, c); }           // Euclidean distance between p and c

double distToLineSegment(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) { c = point(a.x, a.y);                   // closer to a
		return dist(p, a); }         // Euclidean distance between p and a
	if (u > 1.0) { c = point(b.x, b.y);                   // closer to b
		return dist(p, b); }         // Euclidean distance between p and b
	return distToLine(p, a, b, c); }          // run distToLine as above

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

int main() {
	int tc; scanf("%d",&tc);
	bool first = true;
	while (tc--) {
		if (first) first = false;
		else printf("\n");

		vector<point> start, end;
		vector<line> lines;
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x1,y1,x2,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			start.push_back(point(x1,y1));
			end.push_back(point(x2,y2));
			line l;
			pointsToLine(point(x1,y1),point(x2,y2),l);
			lines.push_back(l);
		}
		vector<set<point> > intersection(n);
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				point p;
				if (areIntersect(lines[i],lines[j],p)) {
					point temp;
					if((distToLineSegment(p,start[i],end[i],temp) < EPS) &&
					 (distToLineSegment(p,start[j],end[j],temp) < EPS)) {
						intersection[i].insert(p);
						intersection[j].insert(p);
					}
				}
			}
		}
		int totalSegments = 0;
		for(int i=0;i<n;i++){
			totalSegments += (intersection[i].size() + 1);
		}

		printf("%d\n",totalSegments);		
	}
	return 0;
}
