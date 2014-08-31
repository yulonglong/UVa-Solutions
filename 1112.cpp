//Steven Kester Yuwono - UVa 1112
//Single Source Shortest Path (SSSP) - Dijkstra

#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 1000000000;
using namespace std;

typedef pair<int,int> ii; //first is the destination index, second is the cost

vector<ii> adjList[MAX];
int dist[MAX];

void init(){
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
		dist[i] = INF;
	}
	return;
}

struct node{
	int cost;
	int curr;
	bool operator() (const node& lhs, const node& rhs){
		return (lhs.cost>rhs.cost);
	}
};

int main(){
	int tc;
	cin >> tc;
	bool first=true;

	while(tc--){
		init();
		int N,E,T,M;
		cin >> N >> E >> T >> M;
		for(int i=0;i<M;i++){
			int source, dest, cost;
			//reverse dest and source to run SSSP starting from exit E
			cin >> dest >> source >> cost;
			ii temp;
			temp.first = dest;
			temp.second = cost;
			adjList[source].push_back(temp);
		}


		//straight forward dijkstra
		priority_queue <node,vector<node>,node> pq;
		node firstNode;
		firstNode.cost = 0;
		firstNode.curr = E;
		dist[E]=0;
		pq.push(firstNode);

		while(!pq.empty()){
			node currNode = pq.top();
			pq.pop();
			int currCost = currNode.cost;
			int currIndex = currNode.curr;
			if(dist[currIndex]<currCost){
				continue;
			}
			for(int i=0;i<(int)adjList[currIndex].size();i++){
				int dest = adjList[currIndex][i].first;
				int destCost = adjList[currIndex][i].second;
				if(dist[dest] > currCost + destCost){
					dist[dest] = currCost + destCost;
					node destNode;
					destNode.curr = dest;
					destNode.cost = currCost + destCost;
					pq.push(destNode);
				}
			}
		}

		//counting the number cells which can be reached within time T
		int sum=0;
		for(int i=1;i<=N;i++){
			if(dist[i]<=T){
				sum++;
			}
		}

		//takes care of the blankline between test cases
		if(first){
			first=false;
		}
		else{
			cout << endl;
		}
		cout << sum << endl;
	}

	return 0;
}