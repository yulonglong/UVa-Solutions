// Steven Kester Yuwono - UVa 10940

#include <cstdio>
#define MAX 500005
using namespace std;

int last[MAX];

void init() {
	last[1]=1;
	last[2]=2;
	int top = 2;
	for (int i=3;i<MAX;i++){
		if (i<top) top = 2;
		last[i] = top; top += 2;
	}
}

int main() {
	init();
	int n;
	while ((scanf("%d",&n)==1) && (n>0)) {
		printf("%d\n",last[n]);
	}
	return 0;
}
