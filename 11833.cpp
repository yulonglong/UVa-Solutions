// Steven Kester Yuwono - UVa 11833
// Single-Source Shortest Path (SSSP) - Dijkstra

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 255
#define INF 2000000000
using namespace std;

vector<pair<int,int> > adjList[MAX];
int globalCost[MAX];
int serviceRouteCost[MAX];
int start, dest;

struct Node {
	int vertex;
	int cost;
	Node(int _vertex, int _cost) {
		vertex = _vertex; cost = _cost;
	}
	Node () {
		vertex = -1; cost = -1;
	}
	bool operator ()(const Node& lhs, const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
};

void init() {
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
		globalCost[i] = INF;
	}
	memset(serviceRouteCost,-1,sizeof(serviceRouteCost));
}

void dijkstra() {
	priority_queue<Node, vector<Node>, Node> pq;
	pq.push(Node(start,0));
	while (!pq.empty()) {
		int vertex = pq.top().vertex;
		int cost = pq.top().cost;
		pq.pop();
		if (cost > globalCost[vertex]) continue;
		for(int i=0;i<(int)adjList[vertex].size();i++) {
			int nextVertex = adjList[vertex][i].first;
			int nextCost = adjList[vertex][i].second;
			if (cost + nextCost < globalCost[nextVertex]) {
				globalCost[nextVertex] = cost + nextCost;
				// Only push to the queue (explore further) if the next vertex is not in the service route
				if (nextVertex > dest) {
					pq.push(Node(nextVertex,cost+nextCost));
				}
			}
		}
	}
}

int main() {
	int n,m,c,k;
	while ((scanf("%d %d %d %d",&n,&m,&c,&k)==4) && (n||m||c||k)) {
		init();
		start = k;
		dest = c-1;
		for(int i=0;i<m;i++){
			int from,to,cost;
			scanf("%d %d %d",&from,&to,&cost);
			adjList[from].push_back(pair<int,int>(to,cost));
			adjList[to].push_back(pair<int,int>(from,cost));
		}
		// Get the cost from each node in the service route to the destination
		serviceRouteCost[c-1] = 0;
		for(int i=c-2;i>=0;i--) {
			for(int j=0;j<(int)adjList[i].size();j++){
				if (adjList[i][j].first == i+1) {
					serviceRouteCost[i] = adjList[i][j].second + serviceRouteCost[i+1];
				}
			}
		}
		// Get the minimum cost
		dijkstra();
		int minimumCost = globalCost[dest];
		for(int i=0;i<dest;i++){
			minimumCost = min (minimumCost,globalCost[i] + serviceRouteCost[i]);
		}
		printf("%d\n",minimumCost);
	}
	return 0;
}
