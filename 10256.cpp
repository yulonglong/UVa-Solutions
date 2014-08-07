//Steven Kester Yuwono - UVa 10256

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

// struct point_i { int x, y; };    // basic raw form, minimalist mode
struct point_i { int x, y;     // whenever possible, work with point_i
  point_i() { x = y = 0; }                      // default constructor
  point_i(int _x, int _y) : x(_x), y(_y) {} };         // user-defined

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

struct vec { double x, y;  // name: `vec' is different from STL vector
vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y); }

double dist(point p1, point p2) {                // Euclidean distance
	return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

struct line { double a, b, c; };          // a way to represent a line


bool areParallel(line l1, line l2) {       // check coefficients a & b
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) {           // also check coefficient c
  return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }


// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
  if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
    l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
    l.c = -(double)(l.a * p1.x) - p1.y;
} }


// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
	double result = 0.0;
	for (int i = 0; i < (int)P.size()-1; i++)  // remember that P[0] = P[n-1]
		result += dist(P[i], P[i+1]);
	return result; }

// returns the area, which is half the determinant
double area(const vector<point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size()-1; i++) {
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0; }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) {  // returns angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0; }


// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

// returns true if we always make the same turn while examining
// all the edges of the polygon one by one
bool isConvex(const vector<point> &P) {
	int sz = (int)P.size();
	if (sz <= 3) return false;   // a point/sz=2 or a line/sz=3 is not convex
	bool isLeft = ccw(P[0], P[1], P[2]);               // remember one result
	for (int i = 1; i < sz-1; i++)            // then compare with the others
		if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
			return false;            // different sign -> this polygon is concave
	return true; }                                  // this polygon is convex

// returns true if point p is in either convex/concave polygon P
// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
	for (int i = 0; i < (int)P.size(); i++) {
		if(pt==P[i]){
			return true;
		}
	}
	
  if ((int)P.size() == 0) return false;
  double sum = 0;    // assume the first vertex is equal to the last vertex
  for (int i = 0; i < (int)P.size()-1; i++) {
	double angletemp =  angle(P[i], pt, P[i+1]);
	
	//cout << P[i] << " " << pt <<  " " << P[i+1] << endl;
    if (ccw(pt, P[i], P[i+1])){ // left turn/ccw
		//cout << "plus " << angletemp << endl;
		sum += angletemp;  
	}            
    else {
		//cout << "minus" << angletemp << endl;
		
		if(fabs(angletemp-PI)<EPS){
			sum += angletemp;
		}
		else{
			sum -= angletemp;  
		}
	}
}
  return fabs(fabs(sum) - 2*PI) < EPS; }
// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
	vector<point> P;
	for (int i = 0; i < (int)Q.size(); i++) {
		double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
		if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
		if (left1 > -EPS) P.push_back(Q[i]);       // Q[i] is on the left of ab
		if (left1 * left2 < -EPS)        // edge (Q[i], Q[i+1]) crosses line ab
			P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
	}
	if (!P.empty() && !(P.back() == P.front()))
		P.push_back(P.front());        // make P's first point = P's last point
	return P; }

point pivot;
bool angleCmp(point a, point b) {                 // angle-sorting function
	if (collinear(pivot, a, b))                               // special case
		return dist(pivot, a) < dist(pivot, b);    // check which one is closer
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }   // compare two angles


vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
  return vec(v.x * s, v.y * s); }               // shorter.same.longer

point translate(point p, vec v) {        // translate p according to v
  return point(p.x + v.x , p.y + v.y); }

double distToLine(point p, point a, point b, point &c) {
  // formula: c = a + u * ab
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));                  // translate a to c
  return dist(p, c); }           // Euclidean distance between p and c

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) { c = point(a.x, a.y);                   // closer to a
    return dist(p, a); }         // Euclidean distance between p and a
  if (u > 1.0) { c = point(b.x, b.y);                   // closer to b
    return dist(p, b); }         // Euclidean distance between p and b
  return distToLine(p, a, b, c); }          // run distToLine as above


bool areIntersectSegment(point p1,point p2, point c1,point c2) {
	point p;
	line l1;
	pointsToLine(p1,p2,l1);
	line l2;
	pointsToLine(c1,c2,l2);
	if(areSame(l1, l2)) {
		point ans;
		double d = distToLineSegment(p1, c1, c2, ans);
		if(d<EPS){
			return true;
		}
		 d = distToLineSegment(p2, c1, c2, ans);
		 if(d<EPS){
			return true;
		}
		 d = distToLineSegment(c1, p1, p2, ans);
		if(d<EPS){
			return true;
		}
		 d = distToLineSegment(c2, p1, p2, ans);
		 if(d<EPS){
			return true;
		}
		return false;
	}
  if (areParallel(l1, l2)) return false;            // no intersection
  // solve system of 2 linear algebraic equations with 2 unknowns
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  // special case: test for vertical line to avoid division by zero
  if (fabs(l1.b) > EPS) {
	  p.y = -(l1.a * p.x + l1.c);
  }
  else                 {
	   p.y = -(l2.a * p.x + l2.c);
   }
   
   //additional comparison
  double x1,x2,x3,x4;
  if(p1.x>p2.x){
	  x1=p2.x;
	  x2=p1.x;
  }
  else{
	  x1=p1.x;
	  x2=p2.x;
  }
  if(c1.x>c2.x){
	  x3=c2.x;
	  x4=c1.x;
  }
  else{
	  x3=c1.x;
	  x4=c2.x;
  }
  
  double y1,y2,y3,y4;
  if(p1.y>p2.y){
	  y1=p2.y;
	  y2=p1.y;
  }
  else{
	  y1=p1.y;
	  y2=p2.y;
  }
  if(c1.y>c2.y){
	  y3=c2.y;
	  y4=c1.y;
  }
  else{
	  y3=c1.y;
	  y4=c2.y;
  }
  //cout << x1 << " "<< x2 << " " << x3 << " " << x4 << endl;
  // cout << y1 << " "<< y2 << " " << y3 << " " << y4 << endl;
   //cout << p.x <<  " " << p.y << endl;
  if((x1<=p.x)&&(p.x<=x2)&&(x3<=p.x)&&(p.x<=x4)&(y1<=p.y)&&(p.y<=y2)&&(y3<=p.y)&&(p.y<=y4)){
   return true;
}
return false;
  }


vector<point> CH(vector<point> P) {   // the content of P may be reshuffled
	int i, j, n = (int)P.size();
	if (n <= 3) {
		if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
		return P;                           // special case, the CH is P itself
	}

	// first, find P0 = point with lowest Y and if tie: rightmost X
	int P0 = 0;
	for (i = 1; i < n; i++)
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;

	point temp = P[0]; P[0] = P[P0]; P[P0] = temp;    // swap P[P0] with P[0]

	// second, sort points by angle w.r.t. pivot P0
	pivot = P[0];                    // use this global variable as reference
	sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

	// third, the ccw tests
	vector<point> S;
	S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   // initial S
	i = 2;                                         // then, we check the rest
	while (i < n) {           // note: N must be >= 3 for this method to work
		j = (int)S.size()-1;
		if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
		else S.pop_back(); }   // or pop the top of S until we have a left turn
	return S; }                                          // return the result

int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int m, c;
	scanf("%d %d",&m,&c);
	while (!((m==0)&&(c==0))){
		vector<point> M;
		vector<point> C;
		M.clear();
		C.clear();
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			point temp(x,y);
			M.push_back(temp);
		}
		M.push_back(M[0]);
		for(int i=0;i<c;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			point temp(x,y);
			C.push_back(temp);
		}
		C.push_back(C[0]);
		
		if ((m==0)||(c==0)){
			printf("Yes\n");
			scanf("%d %d",&m,&c);
			continue;
		}
		else if((m==1)&&(c==1)){
			if (M[0]==C[0]){
				printf("No\n");
			}
			else{
				printf("Yes\n");
			}
			scanf("%d %d",&m,&c);
			continue;
		}
		else if(m==1){
			if(inPolygon(M[0],C)){
				printf("No\n");
			}
			else{
				printf("Yes\n");
			}
			scanf("%d %d",&m,&c);
			continue;
		}
		else if(c==1){
			if(inPolygon(C[0],M)){
				printf("No\n");
			}
			else{
				printf("Yes\n");
			}
			scanf("%d %d",&m,&c);
			continue;
		}
		
		M=CH(M);
		C=CH(C);
		/*
		for(int i=0;i<(int)M.size();i++){
			cout << M[i].x << " " << M[i].y << endl;
		}
		cout << endl;
		for(int i=0;i<(int)C.size();i++){
			cout << C[i].x << " " << C[i].y << endl;
		}
		cout << endl;*/
		
		bool valid = true;
		int csize = C.size();
		int msize = M.size();
		
		for(int i=0;i<csize;i++){
			if(inPolygon(C[i],M)){
				valid=false;
				break;
			}
		}
		for(int i=0;i<msize;i++){
			if(inPolygon(M[i],C)){
				valid=false;
				break;
			}
		}
		
		for(int i=1;i<csize;i++){
			for(int j=1;j<msize;j++){
				if(areIntersectSegment(M[j],M[j-1],C[i],C[i-1])){
					valid=false;
					break;
				}
			}
			if(!valid){
				break;
			}
		}
		
		//bool z = areIntersectSegment(point(2,4),point(3,7),point(2,6),point(4,1));
		//cout << z << endl;
		
		if(valid){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
		scanf("%d %d",&m,&c);
	}
	return 0;
}	
