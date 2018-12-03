// Steven Kester Yuwono - UVa 10067
// Breadth First Search

#include <bits/stdc++.h>
using namespace std;

int visited[10][10][10][10];

struct Node {
	int a,b,c,d;
	int hop;
	Node(int f, int g, int h, int i, int j) {
		a=(10+f)%10;b=(10+g)%10;c=(10+h)%10;d=(10+i)%10;
		hop = j;
	}
};

int main() {
	int tc; scanf("%d",&tc);
	while (tc--) {
		memset(visited, 0, sizeof(visited));
		int home[4];scanf("%d %d %d %d",&home[0],&home[1],&home[2],&home[3]);
		int dest[4];scanf("%d %d %d %d",&dest[0],&dest[1],&dest[2],&dest[3]);
		int forbidN; scanf("%d",&forbidN);
		for (int i=0;i<forbidN;i++) {
			int a,b,c,d;scanf("%d %d %d %d",&a,&b,&c,&d);
			visited[a][b][c][d] = 1;
		}
		int ans = -1;
		bool first = true;
		queue<Node> q;
		Node homeNode(home[0],home[1],home[2],home[3], 0);
		q.push(homeNode);
		while (!q.empty()) {
			Node currNode = q.front();
			q.pop();
			if (!first && visited[currNode.a][currNode.b][currNode.c][currNode.d] != 0) {
				continue;
			}
			visited[currNode.a][currNode.b][currNode.c][currNode.d] = 1;
			first = false;
			if (currNode.a == dest[0] && currNode.b == dest[1] && currNode.c == dest[2] && currNode.d == dest[3]) {
				ans = currNode.hop;
				break;
			}
			Node currNode1(currNode.a+1,currNode.b ,currNode.c,currNode.d , currNode.hop + 1);
			Node currNode12(currNode.a-1,currNode.b,currNode.c,currNode.d , currNode.hop + 1);
			Node currNode2(currNode.a,currNode.b+1,currNode.c,currNode.d , currNode.hop + 1);
			Node currNode22(currNode.a,currNode.b-1,currNode.c,currNode.d , currNode.hop + 1);
			Node currNode3(currNode.a,currNode.b,currNode.c+1,currNode.d , currNode.hop + 1);
			Node currNode32(currNode.a,currNode.b,currNode.c-1,currNode.d , currNode.hop + 1);
			Node currNode4(currNode.a,currNode.b,currNode.c ,currNode.d+1, currNode.hop + 1);
			Node currNode42(currNode.a,currNode.b,currNode.c ,currNode.d-1, currNode.hop + 1);
			q.push(currNode1); q.push(currNode2); q.push(currNode3); q.push(currNode4);
			q.push(currNode12); q.push(currNode22); q.push(currNode32); q.push(currNode42);
		}
		printf("%d\n", ans);
	}

	return 0;
}