// Steven Kester Yuwono - UVa 12712

#include <cstdio>
#include <cstring>
#define MODCONST 10000000000007

long long permutateMemo[10002];

void init(int pmMax) {
	memset(permutateMemo,0,sizeof(permutateMemo));
	permutateMemo[0] = pmMax;
	for(int i=1;i<=pmMax;i++){
		permutateMemo[i] = ((pmMax-i) * permutateMemo[i-1]) % MODCONST;
	}
}

int main() {
	int tc;
	scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		int l, m, n;
		scanf("%d %d %d",&l,&m,&n);
		init(l*l);
		long long sum = 0;
		for(int i=m-1;i<n;i++){
			sum = (sum + permutateMemo[i]) % MODCONST;
		}
		printf("Case %d: %lld\n",d,sum);
	}
	return 0;
}