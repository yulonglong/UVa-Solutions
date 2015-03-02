// Steven Kester Yuwono - UVa 10436
// Standard SSSP (Single Source Shortest Path) - Dijkstra

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#define MAX 22
#define INF 2000000000
using namespace std;

map<string,int> stringToInt;
map<string,int>::iterator stoiIter;
map<int,string> intToString;
map<int,string>::iterator itosIter;

int costCity[MAX];
vector<pair<int,int> > adjList[MAX];

int globalCost[MAX];
int parent[MAX];

void init() {
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
	stringToInt.clear();
	intToString.clear();
	memset(parent,-1,sizeof(parent));
}

struct Node {
	int vertex;
	int cost;

	bool operator () (const Node& lhs, const Node& rhs){
		return lhs.cost > rhs.cost;
	}
	Node() : vertex(0), cost(0) {}
	Node(int vertexNew, int costNew) : vertex(vertexNew), cost(costNew) {}
};


void dijkstra(int startVertex) {
	for (int i=0;i<MAX;i++){
		globalCost[i] = INF;
	}

	Node startNode(startVertex,costCity[startVertex]);
	priority_queue<Node,vector<Node>,Node> pq;
	pq.push(startNode);

	while(!pq.empty()){
		Node currNode = pq.top(); pq.pop();
		int currVertex = currNode.vertex;
		int currCost = currNode.cost;
		if(currCost > globalCost[currVertex]) {
			continue;
		}
		for(int i=0;i<(int)adjList[currVertex].size();i++){
			int nextVertex = adjList[currVertex][i].first;
			int nextCost = adjList[currVertex][i].second;
			if(currCost + nextCost < globalCost[nextVertex]) {
				globalCost[nextVertex] = currCost + nextCost;
				Node nextNode(nextVertex,currCost+nextCost);
				parent[nextVertex] = currVertex;

				pq.push(nextNode);
			}
		}
	}
}


int main() {
	int tc;
	cin >> tc;

	for (int d=1; d<=tc; d++) {
		init();

		if(d>1){
			printf("\n");
		}
		printf("Map #%d\n",d);

		// City Definitions
		int nCity;
		cin >> nCity;
		for(int i=0;i<nCity;i++){
			string cityName;
			cin >> cityName;
			cin >> costCity[i];
			stringToInt.insert(pair<string,int>(cityName,i));
			intToString.insert(pair<int,string>(i,cityName));
		}

		// Path Definitions
		int nPath;
		cin >> nPath;
		for(int i=0;i<nPath;i++){
			string cityName1, cityName2;
			int cost;
			cin >> cityName1 >> cityName2 >> cost;
			stoiIter = stringToInt.find(cityName1);
			int city1 = stoiIter->second;
			stoiIter = stringToInt.find(cityName2);
			int city2 = stoiIter->second;
			int costTo1 = cost*2 + costCity[city1];
			int costTo2 = cost*2 + costCity[city2];
			adjList[city1].push_back(pair<int,int>(city2,costTo2));
			adjList[city2].push_back(pair<int,int>(city1,costTo1));
		}

		// Query Definitions
		int nQuery;
		cin >> nQuery;
		for(int i=1;i<=nQuery;i++){
			printf("Query #%d\n",i);

			string cityName1, cityName2;
			int seats;
			cin >> cityName1 >> cityName2 >> seats;
			stoiIter = stringToInt.find(cityName1);
			int city1 = stoiIter->second;
			stoiIter = stringToInt.find(cityName2);
			int city2 = stoiIter->second;

			dijkstra(city1);

			int index = city2;
			stack<string> ans;
			while(index != city1){
				itosIter = intToString.find(index);
				ans.push(itosIter->second);
				index = parent[index];
			}	

			itosIter = intToString.find(city1);
			printf("%s",(itosIter->second).c_str());
			while (!ans.empty()){
				printf(" %s",ans.top().c_str());
				ans.pop();
			}
			printf("\n");

			double passengerCost = (double)globalCost[city2] * 1.1 / (double)seats;
			printf("Each passenger has to pay : %.2f taka\n", passengerCost);
		}
	}
	return 0;
}