// Steven Kester Yuwono - UVa 11393
#include <cstdio>

int main() {
	int n;
	while ((scanf("%d",&n)==1) && (n>0)) {
		if (n<3) printf("NO\n");
		else if (((n-1) % 3 == 0) || (n%3 == 0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
