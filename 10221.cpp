// Steven Kester Yuwono - UVa 10221

#include <iostream>
#include <cstdio>
#include <cmath>
#define PI acos(-1.0)
using namespace std;

double DEG_to_RAD(double d) { return d * PI / 180.0; }

int main() {
	double radius = 6440;
	double s,a;
	string name;
	while (cin >> s >> a >> name) {
		if(a > 180.0) a = 360.0-a;
		if(name == "min") a = a/60.0;
		s = radius + s;
		double arc = 2.0*PI*s*a/360.0;
		double chord = sqrt( s*s + s*s - 2.0*s*s*cos(DEG_to_RAD(a)) );
		printf("%.6lf %.6lf\n",arc,chord);
	}
	return 0;
}