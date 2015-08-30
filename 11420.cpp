// Steven Kester Yuwono - UVa 11420
#include <cstdio>
#define MAX 66
#define INVALID -1

long long memo [MAX][MAX][2];

long long dp(int n, int s, int o) {
	if (n<0||s<0||s>n) return 0;
	if (s==0 && n==0) return 1;
	if (memo[n][s][o] != INVALID) return memo[n][s][o];
	if (o == 1) return memo[n][s][1] = dp(n-1,s,0)   + dp(n-1,s,1);
	else        return memo[n][s][0] = dp(n-1,s-1,0) + dp(n-1,s,1);
}

int main() {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			memo[i][j][0]= INVALID;
			memo[i][j][1]= INVALID;
		}
	}
	int n,s;
	while ((scanf("%d %d", &n, &s)==2) && (n>0)) {
		printf("%lld\n", dp(n,s,0));
	}
	return 0;
}
