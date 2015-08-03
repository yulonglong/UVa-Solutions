// Steven Kester Yuwono - UVa 11624
// Breadth-First Search

#include <iostream>
#include <queue>
#define MAX 1010
using namespace std;

struct Node {
	int x;
	int y;
	int cost;
	char state;
	Node (int _x, int _y, int _cost, char _state) {
		x= _x; y=_y; cost = _cost; state = _state;
	}
	Node() {
		x = 0; y = 0; cost = 0; state = '#';
	}
};

queue<Node> q;
char grid[MAX][MAX];
int r,c;

int traverse() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cost = q.front().cost;
		char state = q.front().state;
		q.pop();

		if ((state == 'J') && ((x==0) || (x==r-1) || (y==0) || (y==c-1))) return cost+1;

		if ((x-1>=0) && (grid[x-1][y]=='.')) {
			q.push(Node(x-1,y,cost+1,state));
			grid[x-1][y] = state;
		}
		if ((x+1<r) && (grid[x+1][y]=='.')) {
			q.push(Node(x+1,y,cost+1,state));
			grid[x+1][y] = state;
		}
		if ((y-1>=0) && (grid[x][y-1]=='.')) {
			q.push(Node(x,y-1,cost+1,state)); 
			grid[x][y-1] = state;
		}
		if ((y+1<c) && (grid[x][y+1]=='.')) {
			q.push(Node(x,y+1,cost+1,state));
			grid[x][y+1] = state;
		}
	}
	return -1;
}

int main() {
	int tc; cin >> tc;
	while (tc--){
		while (!q.empty()) q.pop(); // clear global queue
		int startX, startY; // keep track of 'J' coordinate
		cin >> r >> c;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> grid[i][j];
				if (grid[i][j] == 'J') {
					startX = i;
					startY = j;
					grid[i][j] = '.';
				}
				if (grid[i][j]=='F') q.push(Node(i,j,0,'F'));
			}
		}
		q.push(Node(startX,startY,0,'J'));
		int ans = traverse();
		if (ans>=0) cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
