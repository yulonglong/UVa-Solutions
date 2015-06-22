// Steven Kester Yuwono - UVa 12047
// Single-Source Shortest Path (SSSP)

#include <cstdio>
#include <vector>
#include <queue>
#define MAX 10010
#define INF 2100000000
using namespace std;

vector<pair<int,int> > adjList[MAX];
vector<pair<int,int> > rAdjList[MAX];
int fDist[MAX];
int rDist[MAX];

void init() {
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
		rAdjList[i].clear();
		fDist[i] = INF;
		rDist[i] = INF;
	}
}

struct Node {
	int curr;
	int cost;
	Node() {
		curr = -1;
		cost = -1;
	}
	Node(int _curr, int _cost) {
		curr = _curr;
		cost = _cost;
	}
	bool operator() (const Node& lhs, const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
};


void dijkstra(int start, int (&dist)[MAX], const vector<pair<int,int> > (&alist)[MAX]) {
	priority_queue<Node, vector<Node>,Node > pq;
	pq.push(Node(start,0));
	dist[start] = 0;
	while(!pq.empty()){
		int curr = pq.top().curr;
		int currCost = pq.top().cost;
		pq.pop();
		if(dist[curr] < currCost) continue;
		for(int i=0;i<(int)alist[curr].size();i++){
			if(currCost + alist[curr][i].second < dist[alist[curr][i].first]) {
				dist[alist[curr][i].first] = currCost + alist[curr][i].second;
				pq.push(Node(alist[curr][i].first,dist[alist[curr][i].first]));
			}
		}
	}
}

int main() {
	int tc; scanf("%d",&tc);
	while(tc--){
		init();
		int N,M,s,t,p;
		scanf("%d %d %d %d %d",&N,&M,&s,&t,&p);
		for(int i=0;i<M;i++){
			int from,to,cost;
			scanf("%d %d %d",&from, &to, &cost);
			adjList[from].push_back(pair<int,int>(to,cost));
			rAdjList[to].push_back(pair<int,int>(from,cost));
		}

		dijkstra(s,fDist,adjList); // forward dijkstra on graph
		if ((fDist[t] == INF) || (fDist[t] > p)) {
			printf("-1\n");
			continue;
		}
		
		dijkstra(t,rDist,rAdjList); // dijkstra on a reversed graph

		int ans = -1;
		for(int i=1;i<=N;i++) {
			for(int j=0;j<(int)adjList[i].size();j++){
				int w = adjList[i][j].second;
				int nextVertex = adjList[i][j].first;
				int totalCost = w + fDist[i] + rDist[nextVertex];
				if ((totalCost <= p) && (w > ans)) ans = w;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
