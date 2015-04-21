// Steven Kester Yuwono - UVa 974

#include <cstdio>

int kaprekar[] = {9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962};

int main() {
	int tc; scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		if(d>1){
			printf("\n");
		}
		int lower, higher; scanf("%d %d",&lower,&higher);
		printf("case #%d\n",d);
		int noAnswer = true;
		for(int i=0;i<19;i++){
			if ((kaprekar[i] >= lower) && (kaprekar[i] <= higher)) {
				printf("%d\n",kaprekar[i]);
				noAnswer = false;
			}
			else if (kaprekar[i] > higher) {
				break;
			}
		}
		if(noAnswer) {
			printf("no kaprekar numbers\n");
		}
	}
	return 0;
}