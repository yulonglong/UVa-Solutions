// Steven Kester Yuwono - UVa 11670

#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS 1e-9
using namespace std;

double dist[100100];

bool isSame(double lhs, double rhs) {
	return (fabs(lhs-rhs) < EPS);
}

int main() {
	int tc = 1;
	int n;
	while (scanf("%d",&n)==1 && n!= 0){
		for(int i=0;i<n;i++){
			scanf("%lf",&dist[i]);
		}
		sort(dist,dist+n);
		// Make sure everything starts from zero
		for(int i=n-1;i>=0;i--){
			dist[i] = dist[i] - dist[0];
		}

		double range; scanf("%lf",&range);
		double heatedRange = range;

		double t = 0;
		double distMoved = 0;

		for(int i=1;i<n;i++){
			
			if ((dist[i] < heatedRange) || (isSame(dist[i],heatedRange))) {
				heatedRange = dist[i] + range;
			}
			else if ((dist[i]-distMoved < heatedRange) || isSame(dist[i]-distMoved,heatedRange)) {
				heatedRange += range;
			}
			else {
				distMoved = dist[i] - heatedRange;
				heatedRange += range;
			}
		}
		printf("Case %d: %.3lf\n",tc++,distMoved/2.0);

	}
	return 0;
}