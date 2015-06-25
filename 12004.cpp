// Steven Kester Yuwono - UVa 12004

#include <cstdio>
using namespace std;

int main() {
	int tc; scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		long long n; scanf("%lld",&n);
		n *= (n-1);
		printf("Case %d: ",d);
		if (n%4 != 0) printf("%lld/2\n",n/2);
		else printf("%lld\n",n/4);
	}
	return 0;
}
