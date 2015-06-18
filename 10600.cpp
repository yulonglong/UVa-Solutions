// Steven Kester Yuwono - UVa 10600
// Minimum Spanning Tree

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 102
#define INF 2000000000
using namespace std;

struct Node {
	int from;
	int index;
	int cost;
	Node() {
		index=0; cost=0;
	}
	Node(int newFrom, int newIndex, int newCost) {
		from = newFrom;
		index = newIndex;
		cost = newCost;
	}
	bool operator() (const Node& lhs, const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
};

vector<pair<int,int> > adjList[MAX];
bool visited[MAX];
vector<Node> edgesUsed;

int mst(bool first){
	int index = 0;
	memset(visited,false,sizeof(visited));

	Node firstNode = Node(0,0,0);
	priority_queue<Node,vector<Node>,Node> pq;
	pq.push(firstNode);

	int totalCost = 0;

	while(!pq.empty()){
		Node currNode = pq.top(); pq.pop();
		if(visited[currNode.index]) continue;
		if (first) edgesUsed.push_back(currNode);
		visited[currNode.index] = true;
		totalCost += currNode.cost;

		for(int i=0;i<(int)adjList[currNode.index].size();i++){
			pq.push(Node(currNode.index,adjList[currNode.index][i].first, adjList[currNode.index][i].second));
		}
	}
	return totalCost;
}

int main() {
	int tc; scanf("%d",&tc);
	int n,m;
	while (tc--) {
		scanf("%d %d",&m,&n);
		for(int i=0;i<MAX;i++){
			adjList[i].clear();
		}
		edgesUsed.clear();
		for (int i=0;i<n;i++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			x--;y--;
			adjList[x].push_back(pair<int,int>(y,z));
			adjList[y].push_back(pair<int,int>(x,z));
		}
		int firstMst = mst(true);
		int secondMst = INF;
		for(int i=1;i<(int)edgesUsed.size();i++){
			vector<pair<int,int> >::iterator it;
			it = find(adjList[edgesUsed[i].from].begin(), adjList[edgesUsed[i].from].end(), (pair<int,int>(edgesUsed[i].index,edgesUsed[i].cost)));
			int originalCost = it->second;
			it->second = INF;
			int currMst = mst(false);
			secondMst = min(currMst,secondMst);
			it->second = originalCost;
		}
		printf("%d %d\n",firstMst,secondMst);
	}
	return 0;
}
