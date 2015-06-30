// Steven Kester Yuwono - UVa 11834

#include <cstdio>

int L,C,r1,r2;
bool check() {
	int smallerL = L<C? L:C;
	if ((r1+r1 > smallerL) || (r2+r2 > smallerL)) return false;
	int xy1 = (C-r2-r1);
	int xy2 = (L-r2-r1);
	int r = r1+r2;
	int distanceBetweenCenters = xy1*xy1 + xy2*xy2;
	int totalR = r*r;
	if (distanceBetweenCenters < totalR) return false;
	return true;
}

int main() {
	while ((scanf("%d %d %d %d",&L,&C,&r1,&r2)==4) && (L||C||r1||r2)) {
		if (check()) printf("S\n");
		else printf("N\n");
	}
	return 0;
}
