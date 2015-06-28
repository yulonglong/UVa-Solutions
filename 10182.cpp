// Steven Kester Yuwono - UVa 10182

#include <cstdio>
#define MAX 120100

int global_x[MAX];
int global_y[MAX];
int counter = 2;

void updateCounter(int &x, int &y) {
	global_x[counter] = x;
	global_y[counter++] = y;
}

void up(int &x, int &y) { y--; updateCounter(x,y); }
void upRight(int &x, int &y) { x++; y--; updateCounter(x,y); }
void downRight(int &x, int &y) { x++; updateCounter(x,y); }
void down(int &x, int &y) { y++; updateCounter(x,y); }
void downLeft(int &x, int &y) { x--; y++; updateCounter(x,y); }
void upLeft(int &x, int &y) { x--; updateCounter(x,y); }

int main() {
	int x = 0;
	int y = 0;
	global_x[1] = 0;
	global_y[1] = 0;
	for(int i=1;i<184;i++){
		down(x,y);
		for(int j=1;j<i;j++) downLeft(x,y);
		for(int j=0;j<i;j++) upLeft(x,y);
		for(int j=0;j<i;j++) up(x,y);
		for(int j=0;j<i;j++) upRight(x,y);
		for(int j=0;j<i;j++) downRight(x,y);
		for(int j=0;j<i;j++) down(x,y);
	}
	int query;
	while(scanf("%d",&query)==1) {
		printf("%d %d\n",global_x[query],global_y[query]);
	}
	return 0;
}
