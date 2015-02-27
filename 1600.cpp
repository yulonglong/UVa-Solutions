// Steven Kester Yuwono - UVa 1600

#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 25
#define INF 2000000000
using namespace std;

bool visited[MAX][MAX][MAX];
int grid[MAX][MAX];
int n,m,k;

struct Node {
	int x;
	int y;
	int z;
	int cost;
	Node(int newX, int newY, int newZ, int newCost) : x(newX), y(newY), z(newZ), cost(newCost){}
};

int bfs() {
	memset(visited,false,sizeof(visited));
	int ans = INF;

	Node startNode(1,1,0,0);
	queue<Node> q;
	q.push(startNode);

	while(!q.empty()){
		Node currNode = q.front(); q.pop();
		int x = currNode.x;
		int y = currNode.y;
		int z = currNode.z;
		int cost = currNode.cost;

		if ((x==n)&&(y==m)&&(z<=k)) {
			ans = min(ans, cost);
			continue;
		}
		if(visited[x][y][z]) {
			continue;
		}
		visited[x][y][z] = true;

		if(x-1>=1){
			int tempZ = 0;
			if(grid[x-1][y] == 1) {
				tempZ = z + 1;
			}
			if(tempZ <= k){
				q.push(Node(x-1,y,tempZ,cost+1));
			}
		}
		if(x+1<=n){
			int tempZ = 0;
			if(grid[x+1][y] == 1) {
				tempZ = z + 1;
			}
			if(tempZ <= k){
				q.push(Node(x+1,y,tempZ,cost+1));
			}
		}
		if(y-1>=1){
			int tempZ = 0;
			if(grid[x][y-1] == 1) {
				tempZ = z + 1;
			}
			if(tempZ <= k){
				q.push(Node(x,y-1,tempZ,cost+1));
			}
		}
		if(y+1<=m){
			int tempZ = 0;
			if(grid[x][y+1] == 1) {
				tempZ = z + 1;
			}
			if(tempZ <= k){
				q.push(Node(x,y+1,tempZ,cost+1));
			}
		}
	}
	return ans;
}

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d %d",&n,&m);
		scanf("%d",&k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&grid[i][j]);
			}
		}
		int ans = bfs();
		if(ans == INF){
			printf("-1\n");
		}
		else {
			printf("%d\n",ans);
		}

	}
	return 0;
}