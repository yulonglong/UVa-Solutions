//Steven Kester Yuwono - UVa 11857
//Minimum Spanning Tree - Prim's Algorithm

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define vii vector<pair<int,int> > 
#define pii pair<int,int>
#define MAX 100000
using namespace std;

vii adjList[MAX];
bool visited[MAX];

struct Node{
	int vertex;
	int cost;
	bool operator () (const Node &lhs, const Node &rhs){
		return lhs.cost>rhs.cost;
	}
};

int prims(int numCity){
	int max = -1;

	priority_queue<Node,vector<Node>,Node> pq;

	Node start;
	start.vertex = 0;
	start.cost = 0;
	pq.push(start);
	while(!pq.empty()){
		Node curr = pq.top();
		pq.pop();

		if(visited[curr.vertex]){
			continue;
		}
		visited[curr.vertex] = true;
		if(max<curr.cost){
			max = curr.cost;
		}

		for(int i=0;i<(int)adjList[curr.vertex].size();i++){
			Node next;
			next.vertex = adjList[curr.vertex][i].first;
			next.cost = adjList[curr.vertex][i].second;
			pq.push(next);
		}

	}

	for(int i=0;i<numCity;i++){
		if(!visited[i]){
			return -1;
		}
	}
	return max;
}

void init(){
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
	memset(visited,0,sizeof(visited));
	return;
}

int main(){
	int n,m;
	while ((scanf("%d %d",&n,&m)==2)&&(!((n==0)&&(m==0)))){
		init();

		for(int i=0;i<m;i++){
			int a,b,cost;
			scanf("%d %d %d",&a,&b,&cost);
			adjList[a].push_back(pii(b,cost));
			adjList[b].push_back(pii(a,cost));
		}

		int ans = prims(n);
		if(ans==-1){
			printf("IMPOSSIBLE\n");
		}
		else{
			printf("%d\n",ans);
		}

	}
	return 0;
}