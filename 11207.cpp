// Steven Kester Yuwono - UVa 11207

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while ((scanf("%d",&n)==1) && (n>0)) {
		double biggest = -1;
		int index = -1;
		for(int d=1;d<=n;d++) {
			double smaller,bigger; scanf("%lf %lf",&smaller, &bigger);
			if (smaller > bigger) swap(smaller,bigger);
			double possible = max(smaller/2.0, min(smaller,bigger/4.0));
			if (possible > biggest) {
				biggest = possible;
				index = d;
			}
		}
		printf("%d\n",index);
	}
	return 0;
}
