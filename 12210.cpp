// Steven Kester Yuwono - UVa 12210
#include <cstdio>

int main() {
	int n,m;
	int d = 1;
	while ((scanf("%d %d",&n,&m)==2) && (n||m)) {
		int boy[10010];
		int girl[10010];
		int minBoy = 100;
		for(int i=0;i<n;i++){
			scanf("%d",&boy[i]);
			if (minBoy > boy[i]) {
				minBoy = boy[i];
			}
		}
		for(int i=0;i<m;i++){
			scanf("%d",&girl[i]);
		}
		printf("Case %d: ",d++);
		if (n-m <= 0) printf("0\n");
		else printf("%d %d\n",n-m, minBoy);
	}
	return 0;
}
