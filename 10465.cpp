// Steven Kester Yuwono - UVa 10465
#include <cstdio>
#include <cstring>

int memo[10100];

int main() {
	int n,m,t;
	while (scanf("%d %d %d",&n,&m,&t)==3) {
		memset(memo,-1,sizeof(memo));
		memo[t] = 0;
		for(int i=t;i>=0;i--){
			if (memo[i] == -1) continue;
			if (i-n >=0) {
				if (memo[i-n] < memo[i]+1)
					memo[i-n] = memo[i]+1;
			}
			if (i-m >= 0) {
				if (memo[i-m] < memo[i]+1)
					memo[i-m] = memo[i]+1;
			}
		}

		if (memo[0] > 0) printf("%d\n",memo[0]);
		else {
			for(int i=1;i<=t;i++){
				if (memo[i] >= 0) {
					printf("%d %d\n",memo[i],i);
					break;
				}
			}
		}
	}
	return 0;
}
