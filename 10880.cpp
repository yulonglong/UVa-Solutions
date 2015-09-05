// Steven Kester Yuwono - UVa 10880
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int main() {
	int tc; scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		printf("Case #%d:",d);
		long long c,r;
		scanf("%lld %lld",&c,&r);
		if (c==r) {
			printf(" 0\n");
			continue;
		}
		set<long long> s;
		long long diff = c-r;
		long long loopMax = sqrt(diff);
		for(int i=1;i<=loopMax;i++){
			if (diff%i == 0) {
				s.insert(i);
				if (i != diff/i) s.insert(diff/i);
			}
		}
		set<long long>::iterator it;
		for(it = s.begin(); it != s.end(); it++) {
			if (*it > r) printf(" %lld",*it);
		}
		printf("\n");
	}
	return 0;
}
