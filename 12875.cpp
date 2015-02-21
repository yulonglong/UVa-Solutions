// Steven Kester Yuwono - UVa 12875

#include <cstdio>
#include <vector>
#include <queue>
#define MAXS 101
#define MAXC 51
#define MAX 5200
#define INF 2000000000
using namespace std;

int profit[MAXS][MAXC];
int cost[MAXS][MAXS];
int dist[MAX];
vector<pair<int,int> > adjList[MAX];

struct Node {
	int vertex;
	int cost;
	bool operator() (const Node& lhs,const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
};

void init() {
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
}

int dijkstra(int start){
	for(int i=0;i<MAX;i++){
		dist[i] = INF;
	}

	priority_queue<Node,vector<Node>,Node> pq;

	Node startNode;
	startNode.vertex = start;
	startNode.cost = 0;

	pq.push(startNode);

	while(!pq.empty()){
		Node currNode = pq.top();
		pq.pop();
		int currVertex = currNode.vertex;
		int currCost = currNode.cost;
		if(dist[currVertex] < currCost){
			continue;
		}
		for(int i=0;i<(int)adjList[currVertex].size();i++){
			int destVertex = adjList[currVertex][i].first;
			int destCost = adjList[currVertex][i].second;
			if(dist[destVertex] > currCost + destCost) {
				dist[destVertex] = currCost + destCost;
				Node destNode;
				destNode.vertex = destVertex;
				destNode.cost = currCost + destCost;
				pq.push(destNode);
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		init();
		int s,c;
		scanf("%d %d",&s,&c);
		for(int i=1;i<=s;i++){
			for(int j=1;j<=c;j++){
				scanf("%d",&profit[i][j]);
			}
		}
		for(int i=1;i<=s;i++){
			for(int j=1;j<=s;j++){
				scanf("%d",&cost[i][j]);
			}
		}

		// Graph Modeling start
		for(int i=1;i<=s;i++){
			pair<int,int> tempPair(i,-1*profit[i][1]);
			adjList[0].push_back(tempPair);
		}
		for(int i=2;i<=c;i++){
			for(int j=1;j<=s;j++){
				for(int k=1;k<=s;k++){
					pair<int,int> tempPair(k+((i-1)*s),(-1*profit[k][i])+cost[j][k]);
					adjList[j+((i-2)*s)].push_back(tempPair);
				}
			}
		}
		int finalVertex = s*c+1;

		for(int j=1;j<=s;j++){
			pair<int,int> tempPair(finalVertex,0);
			adjList[j+((c-1)*s)].push_back(tempPair);
		}
		// Graph Modeling end

		dijkstra(0);
		printf("%d\n",-1*dist[finalVertex]);
	}
	return 0;
}