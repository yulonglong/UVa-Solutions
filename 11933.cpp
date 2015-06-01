// Steven Kester Yuwono - UVa 11933

#include <cstdio>

int LSOne (int n) { return (n & -n); }
int main() {
	int n;
	while ((scanf("%d",&n)==1) && (n>0)) {
		int a = 0;
		int b = 0;
		bool odd = true;
		while(n>0){
			int lsb = LSOne(n);
			if (odd) a += lsb;
			else b += lsb;
			odd = !odd;
			n -= lsb;
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}