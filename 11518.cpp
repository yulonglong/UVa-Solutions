// Steven Kester Yuwono - UVa 11518

#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 10010
using namespace std;

vector<int> adjList[MAX];
bool visited[MAX];

void init() {
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
	memset(visited,false,sizeof(visited));
}

void dfs(int vertex) {
	if (visited[vertex]) return;
	visited[vertex] = true;
	for(int i=0;i<(int)adjList[vertex].size();i++){
		dfs(adjList[vertex][i]);
	}
}

int main() {
	int tc; scanf("%d",&tc);
	while (tc--){
		init();
		int n,m,l;
		scanf("%d %d %d",&n,&m,&l);
		for(int i=0;i<m;i++){
			int from, to;
			scanf("%d %d",&from,&to);
			adjList[from].push_back(to);
		}
		for(int i=0;i<l;i++) {
			int touched;
			scanf("%d",&touched);
			dfs(touched);
		}
		int fall = 0;
		for(int i=1;i<=n;i++){
			if (visited[i]) fall++;
		}
		printf("%d\n",fall);
	}
	return 0;
}
