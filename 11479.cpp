// Steven Kester Yuwono - UVa 11479

#include <cstdio>
#include <string>
using namespace std;

string getType(long long x, long long y, long long z) {
	if ((x <= 0) || (y <= 0) || (z <= 0)) return "Invalid";
	if (x+y <= z) return "Invalid";
	if (y+z <= x) return "Invalid";
	if (x+z <= y) return "Invalid";
	if (x==y && y==z) return "Equilateral";
	if ((x==y && x!=z) || (x==z && x!=y) || (y==z && x!=y)) return "Isosceles";
	return "Scalene";
}

int main() {
	int tc; scanf("%d",&tc);
	for(int d=1;d<=tc;d++) {
		long long x,y,z; scanf("%lld %lld %lld", &x, &y, &z);
		printf("Case %d: %s\n",d,getType(x,y,z).c_str());
	}
	return 0;
}