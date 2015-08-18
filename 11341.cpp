// Steven Kester Yuwono - UVa 11341

#include <cstdio>
#include <cstring>
#define INVALID -1
#define EPS 1e-8
using namespace std;

int L[11][101];
int memo[11][101];
int n,m;

int main() {
	int tc; scanf("%d",&tc);
	while (tc--) {
		memset(memo,INVALID,sizeof(memo));
		memo[0][0] = 0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&L[i][j]);
			}
		}
		for (int i=1;i<=n;i++){
			for(int j=m; (j>=1)&&(L[i][j]>=5); j--){
				for(int k=m;k>=j;k--){
					if (memo[i-1][k-j] != INVALID) {
						if (memo[i][k] < memo[i-1][k-j]+L[i][j]) {
							memo[i][k] = memo[i-1][k-j]+L[i][j];
						}
					}
				}
			}
		}
		if (memo[n][m] == INVALID) {
			printf("Peter, you shouldn't have played billiard that much.\n");
		}
		else {
			double average = (double)(memo[n][m]+EPS)/(double)n;
			printf("Maximal possible average mark - %.2lf.\n",average);
		}
	}
	return 0;
}
