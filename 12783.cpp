// Steven Kester Yuwono - UVa 12783

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 1010
#define INF 2000000000
using namespace std;

vector<int> adjList[MAX];
bool visited[MAX];
int depth[MAX];
vector<pair<int,int> > bridge;
vector<pair<int,int> >::iterator it;

void init() {
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
	bridge.clear();
	memset(visited,false,sizeof(visited));
}

int findBridge(int currVertex, int fromVertex, int currDepth) {
	visited[currVertex] = 1;
	depth[currVertex] = currDepth;
	int back = INF;
	for(int i = 0; i < (int)adjList[currVertex].size(); i++) {
		int destVertex = adjList[currVertex][i];
		if(destVertex == fromVertex)	continue;
		if(!visited[destVertex]) {
			int b = findBridge(destVertex, currVertex, currDepth+1);
			if(b > currDepth) {
				bridge.push_back(pair<int,int>(currVertex, destVertex));
			}
			back = min(back, b);
		}
		else {
			back = min(back, depth[destVertex]);
		}
	}
	return back;
}

int main() {
	int n, m;
	while(scanf("%d %d",&n,&m)==2) {
		if ((n==0)&&(m==0)) {
			break;
		}
		init();
		for(int i=0;i<m;i++){
			int start,dest;
			scanf("%d %d",&start,&dest);
			adjList[start].push_back(dest);
			adjList[dest].push_back(start);
		}

		for(int i=0;i<n;i++){
			if(!visited[i]){
				findBridge(i,INF,0);
			}
		}
		for(int i=0;i<(int)bridge.size();i++){
			if (bridge[i].first > bridge[i].second){
				swap(bridge[i].first, bridge[i].second);
			}
		}
		sort(bridge.begin(),bridge.end());

		printf("%d",bridge.size());
		for(it = bridge.begin();it!= bridge.end();it ++){
			printf(" %d %d",it->first, it->second);
		}
		printf("\n");

	}
	return 0;
}