// Steven Kester Yuwono - UVa 11407
#include <cstdio>
#include <cstring>
#define MAX 10202
#define INF 2000000000

int memo[MAX];

int main() {
	memo[0]=0;
	for(int j=1;j<MAX;j++) {
		memo[j] = 4;
	}
	for (int i=1;i<102;i++){
		memo[i*i] = 1;
	}
	for(int i=1;i<=MAX;i++){
		if (memo[i] == 1) continue;
		for(int j=1;j<=i;j++){
			if (memo[i] > memo[i-j]+memo[j])
				memo[i] = memo[i-j]+memo[j];
		}
	}
	int n; scanf("%d",&n);
	for(int d=1;d<=n;d++) {
		int i; scanf("%d",&i);
		printf("%d\n",memo[i]);
	}
	return 0;
}
