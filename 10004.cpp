// Steven Kester Yuwono - UVa 10004

#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 202
using namespace std;

vector<int> adjList[MAX];
int color[MAX];

void init() {
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
}

bool bfs(int start, int c) {
	queue<int> q;
	q.push(start);
	color[start] = c;

	while(!q.empty()) {
		int curr = q.front(); q.pop();
		int currColor = color[curr];
		int neighbourColor = (currColor+1) %2;
		for(int i=0;i<(int)adjList[curr].size();i++){
			if(color[adjList[curr][i]]==-1){
				color[adjList[curr][i]] = neighbourColor;
				q.push(adjList[curr][i]);
			}
			else if (color[adjList[curr][i]] != neighbourColor) return false;
		}
	}
	return true;
}

int main() {
	int n,m;
	while(scanf("%d %d",&n,&m)==2) {
		init();
		for(int i=0;i<m;i++){
			int from,to;
			scanf("%d %d",&from, &to);
			adjList[from].push_back(to);
			adjList[to].push_back(from);
		}
		memset(color,-1,sizeof(color));
		bool ans = bfs(0,0);
		if(!ans) {
			memset(color,-1,sizeof(color));
			ans = bfs(0,1);
		}
		if (ans) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	return 0;
}
