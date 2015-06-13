// Steven Kester Yuwono - UVa 12442

#include <cstdio>
#include <cstring>
#define MAX 50010
#define END -1
using namespace std;

int graph[MAX];
bool visited[MAX];
int messageReached[MAX];

int dfs(int curr) {
	visited[curr] = true;
	int count = 0;
	if ((graph[curr] != END) && (!visited[graph[curr]]))
		count  = count + dfs(graph[curr]) + 1;
	visited[curr] = false;
	messageReached[curr] = count;
	return count;
}

int main() {
	int tc; scanf("%d",&tc);
	for(int d=1;d<=tc;d++) {
		int martian; scanf("%d",&martian);
		memset(graph,-1,sizeof(graph));
		for(int i=0;i<martian;i++){
			int from, to;
			scanf("%d %d",&from,&to);
			graph[from] = to;
		}
		int maxSpread = 0;
		int index = -1;

		memset(messageReached,-1,sizeof(messageReached));
		memset(visited,false,sizeof(visited));
		for(int i=1;i<=martian;i++){
			if(messageReached[i] == END) {
				dfs(i);
			}
			if (maxSpread < messageReached[i]) {
				maxSpread = messageReached[i];
				index = i;
			}
		}
		printf("Case %d: %d\n",d,index);
	}
	return 0;
}