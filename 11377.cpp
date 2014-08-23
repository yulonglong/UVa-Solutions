//Steven Kester Yuwono - UVa 11377

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 2050
#define INF 1000000000
using namespace std;

bool airport[MAX];
int cost[MAX];
vector<int> adjList[MAX];

void resetAirport(){
	memset(airport,0,sizeof(airport));
	return;
}

void resetCost(){
	for(int i=0;i<MAX;i++){
		cost[i]=INF;
	}
	return;
}

void resetList(){
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
	return;
}

struct node{
	int cost;
	int curr;
	
	bool operator()(const node& lhs, const node& rhs){
		return (lhs.cost>rhs.cost);
	}
};

int dijkstra(int source, int dest){
	if(source==dest){
		return 0;
	}
	priority_queue<node,vector<node>,node> pq;
	node tempNode;
	if (airport[source]==false){
		tempNode.cost=1;
	}
	else{
		tempNode.cost=0;
	}
	tempNode.curr = source;
	
	pq.push(tempNode);
	
	while(!pq.empty()){
		node currNode = pq.top();
		pq.pop();
		int currCost = currNode.cost;
		int currCity = currNode.curr;
		if(cost[currCity]<currCost){
			continue;
		}
		
		for(int i=0;i<(int)adjList[currCity].size();i++){
			int addCost=0;
			if(airport[adjList[currCity][i]]==false){
				addCost=1;
			}
			if(cost[adjList[currCity][i]]>currCost+addCost){
				cost[adjList[currCity][i]]=currCost+addCost;
				node pushNode;
				pushNode.cost = currCost+addCost;
				pushNode.curr = adjList[currCity][i];
				pq.push(pushNode);
			}
		}
	}
	
	if(cost[dest]==INF){
		return -1;
	}
	else{
		return cost[dest];
	}
}

int main(){
	int tc;
	cin >>tc;
	for(int d=0;d<tc;d++){
		resetList();
		resetCost();
		resetAirport();
		cout << "Case " << d+1 << ":" << endl;
		int N, M, K;
		cin >> N >> M >> K;
		
		int airportCity;
		for(int i=0;i<K;i++){
			cin >> airportCity;
			airport[airportCity]=true;
		}
		for(int i=0;i<M;i++){
			int source,dest;
			cin >> source >> dest;
			adjList[source].push_back(dest);
			adjList[dest].push_back(source);
		}
		int Q;
		cin >> Q;
		//cout << Q << endl;
		for(int i=0;i<Q;i++){
			resetCost();
			int source,dest;
			cin >> source >> dest;
			int ans = dijkstra(source,dest);
			
			cout << ans << endl;
		}
		//this last endline is very important!
		//without this will get WA.......
		cout << endl;
	}
	return 0;
}
