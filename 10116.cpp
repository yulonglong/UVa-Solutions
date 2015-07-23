// Steven Kester Yuwono - UVa 10116

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define MAX 5000
#define NOTVISITED -1
using namespace std;

int r,c,startC;
char grid[MAX][MAX];
int visited[MAX][MAX];
bool loop, quit;
int length, lengthLoop;

struct Node {
	int x;
	int y;
	int cost;
	Node(int _x, int _y, int _cost) {
		x = _x; y = _y; cost = _cost;
	}
};

void traverse() {
	queue<Node> q;
	q.push(Node(0,startC,0));

	loop = false;
	quit = false;
	length = 0;
	lengthLoop = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cost = q.front().cost;
		q.pop();
		if (visited[x][y] != NOTVISITED) {
			lengthLoop = cost-visited[x][y];
			length = visited[x][y];
			loop = true;
			break;
		}
		visited[x][y] = cost;
		cost++;

		char currDirection = grid[x][y];
		if (currDirection == 'N') {
			if (x==0) {
				length = cost;
				quit = true;
				break;
			}
			else q.push(Node(x-1,y,cost));
		}
		else if (currDirection == 'S') {
			if (x==r-1) {
				length = cost;
				quit = true;
				break;
			}
			else q.push(Node(x+1,y,cost));
		}
		else if (currDirection == 'W') {
			if (y==0) {
				length = cost;
				quit = true;
				break;
			}
			else q.push(Node(x,y-1,cost));
		}
		else if (currDirection == 'E') {
			if (y==c-1) {
				length = cost;
				quit = true;
				break;
			}
			else q.push(Node(x,y+1,cost));
		}
	}
}

int main() {
	
	while ((scanf("%d %d %d",&r,&c,&startC)==3) && (r||c||startC)) {
		memset(grid,0,sizeof(grid));
		memset(visited,-1,sizeof(visited));
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> grid[i][j];
			}
		}
		startC--;
		traverse();
		if (quit) printf("%d step(s) to exit\n",length);
		else printf("%d step(s) before a loop of %d step(s)\n",length,lengthLoop);
	}
	return 0;
}
