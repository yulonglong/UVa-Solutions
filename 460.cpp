// Steven Kester Yuwono - UVa 460

#include <cstdio>

int main() {
	int tc; scanf("%d",&tc);
	while(tc--) {
		int x11,y11,x21,y21;
		scanf("%d %d %d %d", &x11, &y11, &x21, &y21);
		int x12, y12, x22, y22;
		scanf("%d %d %d %d", &x12, &y12, &x22, &y22);

		int x1 = x11 > x12 ? x11 : x12;
		int y1 = y11 > y12 ? y11 : y12;
		int x2 = x21 < x22 ? x21 : x22;
		int y2 = y21 < y22 ? y21 : y22;

		if (x1<x2 && y1<y2) printf("%d %d %d %d\n",x1,y1,x2,y2);
		else printf("No Overlap\n");
		if (tc>0) printf("\n");
	}
	return 0;
}
