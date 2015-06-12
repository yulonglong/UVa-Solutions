// Steven Kester Yuwono - UVa 11631
// Minimum Spanning Tree

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 200100
using namespace std;

struct Node {
	int index;
	int cost;
	Node() {
		index=0; cost=0;
	}
	Node(int newIndex, int newCost) {
		index = newIndex;
		cost = newCost;
	}
	bool operator() (const Node& lhs, const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
};

vector<pair<int,int> > adjList[MAX];
bool visited[MAX];

int mst(int m){
	int index = 0;
	memset(visited,false,sizeof(visited));

	Node firstNode = Node(0,0);
	priority_queue<Node,vector<Node>,Node> pq;
	pq.push(firstNode);

	int totalCost = 0;

	while(!pq.empty()){
		Node currNode = pq.top(); pq.pop();
		if(visited[currNode.index]) continue;
		visited[currNode.index] = true;
		totalCost += currNode.cost;

		for(int i=0;i<(int)adjList[currNode.index].size();i++){
			pq.push(Node(adjList[currNode.index][i].first, adjList[currNode.index][i].second));
		}
	}
	return totalCost;
}


int main() {
	int n,m;
	while ((scanf("%d %d",&m,&n)==2) && (n||m)) {
		int originalCost = 0;
		for(int i=0;i<MAX;i++){
			adjList[i].clear();
		}
		for (int i=0;i<n;i++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			adjList[x].push_back(pair<int,int>(y,z));
			adjList[y].push_back(pair<int,int>(x,z));
			originalCost += z;
		}
		int newCost = mst(m);
		printf("%d\n",originalCost-newCost);
	}
	return 0;
}
