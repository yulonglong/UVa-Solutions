//Steven Kester Yuwono - UVa 821
//All-Pairs Shortest Paths (run Dijkstra |V| times)

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#define MAX 101
#define INF 2000000000
using namespace std;


map<int,int> vertexToIndex;
map<int,int> indexToVertex;


int insertVertex(int vertex){
	map<int,int>::iterator it;
	it = vertexToIndex.find(vertex);
	if(it == vertexToIndex.end()){
		int newIndex = vertexToIndex.size();
		vertexToIndex.insert(pair<int,int>(vertex,newIndex));
		return newIndex;
	}
	else{
		return it->second;
	}
}

vector<int> adjList[MAX];
int dist[MAX];

struct Node{
	int index;
	int cost;
	bool operator()(const Node& lhs, const Node& rhs){
		return lhs.cost>rhs.cost;
	}
};

void init(){
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
	vertexToIndex.clear();
	indexToVertex.clear();
}

void initDist(){
	for(int i=0;i<MAX;i++){
		dist[i]=INF;
	}
}

int dijkstra(int source,int size){
	initDist();

	priority_queue<Node,vector<Node>,Node> pq;

	dist[source]=0;

	Node startNode;
	startNode.index = source;
	startNode.cost = 0;

	pq.push(startNode);

	while(!pq.empty()){
		Node currNode = pq.top();
		pq.pop();
		int currIndex = currNode.index;
		int currCost = currNode.cost;
		if(dist[currIndex]<currCost){
			continue;
		}
		for(int i=0;i<(int)adjList[currIndex].size();i++){
			int destIndex = adjList[currIndex][i];
			if(dist[destIndex]>currCost+1){
				dist[destIndex] = currCost+1;
				Node destNode;
				destNode.index = destIndex;
				destNode.cost = currCost+1;
				pq.push(destNode);
			}
		}
	}

	double result = 0;
	for(int i=0;i<size;i++){
		if(i!=source){
			result = result + (double)dist[i];
		}
	}
	return result;
}

int main(){
	int tc=1;
	int n=-1;
	int m=-1;
	
	cin >> n >> m;
	while(!((n==0)&&(m==0))){
		init();

		
		if ((n==0)&&(m==0)){
			break;
		}
		
		int indexN = insertVertex(n);
		int indexM = insertVertex(m);
		adjList[indexN].push_back(indexM);

		cin >> n >> m;
		while(!((n==0)&&(m==0))){
			indexN = insertVertex(n);
			indexM = insertVertex(m);
			adjList[indexN].push_back(indexM);
			cin >> n >> m;
		}

		int size = vertexToIndex.size();
		int totalLength = 0;
		for(int i=0;i<size;i++){
			totalLength = totalLength + dijkstra(i,size);
		}
		double denominator = (double)size * (double)(size-1);
		double averageLength = totalLength / denominator;

		printf("Case %d: average length between pages = %.3f clicks\n",tc++,averageLength);
		cin >> n >> m;
	}
	return 0;
}