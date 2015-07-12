// Steven Kester Yuwono - UVa 11461
#include <cstdio>

int main() {
	int a,b;
	while ((scanf("%d %d",&a,&b)==2) && (a||b)) {
		int count = 0;
		for(int i=1;i*i<=b;i++) {
			if (i*i >= a) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
