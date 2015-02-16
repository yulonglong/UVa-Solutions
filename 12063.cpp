//Steven Kester Yuwono - UVa 12063

#include <cstdio>
#include <cstring>
#define MAXBIT 40
#define MAXMOD 110

long long memo[MAXBIT][MAXBIT][MAXMOD];
int main() {
	int tc;
	scanf("%d", &tc);
	for(int d = 1; d <= tc; d++) {
		printf("Case %d: ", d);

		int n, k;
		scanf("%d %d", &n, &k);		
		if ((n%2 == 1) || (k == 0)) {
			printf("0\n");
			continue;
		}

		memset(memo, 0, sizeof(memo));

		n = n/2;
		memo[0][1][1%k] = 1;
		
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=n; j++) {
				for(int h=0; h<k; h++) {
					memo[i][j+1][ ((h<<1)+1)%k ] += memo[i][j][h];
					memo[i+1][j][ (h<<1)%k ] += memo[i][j][h];
				}
			}
		}
		printf("%lld\n", memo[n][n][0]);
	}
    return 0;
}