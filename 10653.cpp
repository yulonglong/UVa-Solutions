// Steven Kester Yuwono - UVa 10653
// Breadth-First Search

#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std;

int r,c;
int startX, startY, endX, endY;
bool visited[MAX][MAX];

struct Node{
	int x;
	int y;
	int cost;
	Node(int _x, int _y, int _cost) {
		x = _x; y = _y; cost = _cost;
	}
};

int traverse() {
	queue<Node> q;
	q.push(Node(startX,startY,0));
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cost = q.front().cost;
		q.pop();
		if (visited[x][y]) continue;
		visited[x][y] = true;
		if ((x==endX)&&(y==endY)) return cost;
		if (x+1<r)  q.push(Node(x+1,y,cost+1));
		if (x-1>=0) q.push(Node(x-1,y,cost+1));
		if (y+1<c)  q.push(Node(x,y+1,cost+1));
		if (y-1>=0) q.push(Node(x,y-1,cost+1));
	}
	return 0;
}


int main() {
	while ((scanf("%d %d",&r,&c)==2) && (r>0 && c>0)) {
		memset(visited,false,sizeof(visited));
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++){
			int currRow; scanf("%d",&currRow);
			int numBombs; scanf("%d",&numBombs);
			for(int j=0;j<numBombs;j++){
				int currCol; scanf("%d",&currCol);
				visited[currRow][currCol] = true;
			}
		}
		scanf("%d %d",&startX,&startY);
		scanf("%d %d",&endX,&endY);
		printf("%d\n",traverse());
	}
	return 0;
}
