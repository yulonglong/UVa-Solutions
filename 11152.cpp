// Steven Kester Yuwono - UVa 11152

#include <cstdio>
#include <cmath>
using namespace std;

#define PI acos(-1.0)

double perimeter(double ab, double bc, double ca) {
	return ab + bc + ca; }

double area(double ab, double bc, double ca) {
	// Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
	double s = 0.5 * perimeter(ab, bc, ca);
	return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); }

double rInCircle(double ab, double bc, double ca) {
	return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); }

double rCircumCircle(double ab, double bc, double ca) {
	return ab * bc * ca / (4.0 * area(ab, bc, ca)); }

int main() {
	double a,b,c;
	while (scanf("%lf %lf %lf",&a,&b,&c)==3) {
		double r = rInCircle(a,b,c);
		double R = rCircumCircle(a,b,c);
		double triangleArea = area(a,b,c);
		double sunflowers = (PI*R*R)-triangleArea;
		double roses = (PI*r*r);
		double violets = triangleArea-roses;
		printf("%.4f %.4f %.4f\n",sunflowers,violets,roses);
	}
	return 0;
}
