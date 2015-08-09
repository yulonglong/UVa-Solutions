// Steven Kester Yuwono - UVa 12144
// Single-Source Shortest Path (SSSP) - Dijkstra

#include <cstdio>
#include <vector>
#include <queue>
#define MAX 502
#define INF 2000000000
using namespace std;

typedef pair<int,int> pii;

int start,dest,n,m;
vector<pii> adjList[MAX];
int globalCost[MAX];
vector<int> parent[MAX];

// Print function for debugging purposes
void printAdjList(int size) {
	for(int i=0;i<size;i++){
		printf("adjList[%d]\n",i);
		for(int j=0;j<adjList[i].size();j++) {
			printf("%d - %d\n",adjList[i][j].first,adjList[i][j].second);
		}
		printf("\n");
	}
}

struct Node {
	int vertex;
	int cost;
	Node(int _vertex, int _cost) {
		vertex = _vertex; cost = _cost;
	}
	Node() {
		vertex = 0; cost = 0;
	}
	bool operator() (const Node& lhs, const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
};

void init(bool clearAdjList) {
	for(int i=0;i<MAX;i++){
		if (clearAdjList) adjList[i].clear();
		globalCost[i] = INF;
		parent[i].clear();
	}
}

void dijkstra() {
	globalCost[start] = 0;
	priority_queue<Node, vector<Node>, Node> pq;
	pq.push(Node(start,0));
	while(!pq.empty()) {
		int currVertex = pq.top().vertex;
		int currCost = pq.top().cost;
		pq.pop();
		if (currCost > globalCost[currVertex]) continue;
		for(int i=0;i<(int)adjList[currVertex].size();i++){
			int nextVertex = adjList[currVertex][i].first;
			int nextCost = adjList[currVertex][i].second;
			if (globalCost[nextVertex] > nextCost + currCost) {
				globalCost[nextVertex] = nextCost + currCost;
				pq.push(Node(nextVertex,currCost+nextCost));
				// Keep track of shortest path
				parent[nextVertex].clear();
				parent[nextVertex].push_back(currVertex);
			}
			else if (globalCost[nextVertex] == nextCost + currCost) {
				// Keep track of shortest path
				parent[nextVertex].push_back(currVertex);
			}
		}
	}
}

int main() {
	while ((scanf("%d %d",&n,&m)==2) && (n||m)) {
		init(true);
		scanf("%d %d",&start,&dest);
		for(int i=0;i<m;i++){
			int from,to,cost;
			scanf("%d %d %d",&from,&to,&cost);
			adjList[from].push_back(pii(to,cost));
		}

		// Run Dijkstra
		dijkstra();
		
		// Remove all possible paths from the shortest path
		int currVertex = dest;
		queue<int> q;
		q.push(currVertex);
		while (!q.empty()) {
			int currVertex = q.front(); q.pop();
			for(int i=0;i<(int)parent[currVertex].size();i++) {
				int from = parent[currVertex][i];
				int to = currVertex;
				if (from != start) q.push(from);
				for(int i=0;i<(int)adjList[from].size();i++){
					if (adjList[from][i].first == to) {
						adjList[from].erase(adjList[from].begin()+i);
						break;
					}
				}
			}
		}

		// Run Dijkstra again
		init(false);
		dijkstra();

		if (globalCost[dest] == INF) printf("-1\n");
		else printf("%d\n",globalCost[dest]);
	}
	return 0;
}
