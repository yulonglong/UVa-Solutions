// Steven Kester Yuwono - UVa 11608
#include <cstdio>

int qn[13];

int main() {
	int first;
	int d = 1;
	while ((scanf("%d",&qn[0]) == 1) && (qn[0]>=0)) {
		printf("Case %d:\n", d++);
		for(int i=1;i<13;i++){
			scanf("%d",&qn[i]);
		}
		int sum = 0;
		for(int i=0;i<12;i++){
			int curr; scanf("%d",&curr);
			sum += qn[i];
			if (sum < curr) {
				printf("No problem. :(\n");
			}
			else {
				printf("No problem! :D\n");
				sum -= curr;
			}
		}
	}
	return 0;
}
