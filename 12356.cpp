// Steven Kester Yuwono - UVa 12356
#include <cstdio>
#include <cstring>
#define MAX 100020

int left[MAX];
int right[MAX];

int main() {
	int s,b;
	while ((scanf("%d %d",&s,&b)==2) && (s||b)) {
		for(int i=1;i<=s;i++){
			left[i] = i-1;
			right[i] = i+1;
		}
		for(int i=0;i<b;i++){
			int l, r; scanf("%d %d",&l,&r);
			if (left[l] < 1) printf("* ");
			else printf("%d ", left[l]);
			if (right[r] > s) printf("*\n");
			else printf("%d\n", right[r]);
			left[right[r]] = left[l];
			right[left[l]] = right[r];
		}
		printf("-\n");
	}
	return 0;
}
