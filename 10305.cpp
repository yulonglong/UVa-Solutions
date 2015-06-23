// Steven Kester Yuwono - UVa 10305

#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#define MAX 104
using namespace std;

vector<int> adjList[MAX];
stack<int> stk;
bool visited[MAX];

void init() {
	for (int i=0;i<MAX;i++){
		adjList[i].clear();
	}
}

void dfs(int start) {
	if(visited[start]) return;
	visited[start] = true;
	for(int i=0;i<(int)adjList[start].size();i++) {
		dfs(adjList[start][i]);
	}
	stk.push(start);
}

int main() {
	int n,m;
	while ((scanf("%d %d",&n,&m)==2) && (n||m)) {
		init();
		for(int i=0;i<m;i++){
			int from,to;
			scanf("%d %d",&from,&to);
			adjList[from].push_back(to);
		}
		memset(visited,false,sizeof(visited));
		for(int i=1;i<=n;i++){
			if(!visited[i]) {
				dfs(i);
			}
		}
		while(!stk.empty()){
			if (stk.size()==1) printf("%d\n",stk.top());
			else printf("%d ",stk.top());
			stk.pop();
		}
	}
	return 0;
}
