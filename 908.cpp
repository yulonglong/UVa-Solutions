//Steven Kester Yuwono - UVa 908
//Minimum Spanning Tree - Prim's Algorithm

#include <iostream>
#include <vector>
#include <queue>
#define vii vector<pair<int,int> >
#define MAX 1000000
using namespace std;

vii adjList[MAX];
bool connected[MAX];

void init(){
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
		connected[i]=false;
	}
	return;
}

struct Node{
	int vertex;
	int cost;
	bool operator () (const Node& lhs, const Node& rhs){
		return lhs.cost>rhs.cost;
	}
};

int prims(){
	connected[1] = true;
	int totalCost = 0;
	priority_queue < Node, vector<Node>, Node> pq;

	//initialize edges in the queue for first vertex
	for(int i=0;i<(int)adjList[1].size();i++){
		Node start;
		start.vertex = adjList[1][i].first;
		start.cost = adjList[1][i].second;
		pq.push(start);
	}

	while(!pq.empty()){
		Node curr = pq.top();
		pq.pop();
		if(connected[curr.vertex]){
			continue;
		}
		connected[curr.vertex]=true;
		totalCost += curr.cost;
		for(int i=0;i<(int)adjList[curr.vertex].size();i++){
			Node next;
			next.vertex = adjList[curr.vertex][i].first;
			next.cost = adjList[curr.vertex][i].second;
			pq.push(next);
		}
	}
	return totalCost;
}

int main(){
	int N;
	bool first = true;
	while (cin >> N){
		init();
		int initialCost = 0;
		for(int i=1;i<N;i++){
			int a,b,cost;
			cin >> a >> b >> cost;
			initialCost += cost;
		}
		int K;
		cin >> K;
		for(int i=0;i<K;i++){
			int a,b,cost;
			cin >> a >> b >> cost;
			adjList[a].push_back(pair<int,int>(b,cost));
			adjList[b].push_back(pair<int,int>(a,cost));
		}
		int M;
		cin >> M;
		for(int i=0;i<M;i++){
			int a,b,cost;
			cin >> a >> b >> cost;
			adjList[a].push_back(pair<int,int>(b,cost));
			adjList[b].push_back(pair<int,int>(a,cost));
		}

		if (first){
			first = false;
		}
		else {
			cout << endl;
		}

		cout << initialCost << endl;
		cout << prims() << endl;

	}
	return 0;
}