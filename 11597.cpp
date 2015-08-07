// Steven Kester Yuwono - UVa 11597
#include <cstdio>

int main() {
	int n; int d = 1;
	while ((scanf("%d",&n)==1) && (n>0)) {
		printf("Case %d: %d\n",d++,n/2);
	}
	return 0;
}
