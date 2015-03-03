// Steven Kester Yuwono - UVa 10682

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#define MAX 1010
using namespace std;

map<string,int> stringToInt;
map<string,int>::iterator stoiIter;
map<int,string> intToString;
map<int,string>::iterator itosIter;

vector<pair<int,int> > adjList[MAX];
int parent[MAX];
bool visited[MAX][MAX];

void init() {
	stringToInt.clear();
	intToString.clear();
	memset(parent,-1,sizeof(parent));
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
}

bool comparator(pair<int,int> lhs, pair<int,int> rhs) {
	return lhs.first < rhs.first;
}

void sortInput() {
	for(int i=0;i<MAX;i++){
		sort(adjList[i].begin(),adjList[i].end(),comparator);
	}
}

struct Road {
	int vertex1;
	int vertex2;
	int speed;
	Road() : vertex1(-1), vertex2(-1), speed(0) {}
	Road(int vertex1New, int vertex2New, int speedNew) : vertex1(vertex1New), vertex2(vertex2New), speed(speedNew) {}
};

bool bfs(int start, int end) {
	queue<Road> q;
	memset(visited,false,sizeof(visited));
	memset(parent,-1,sizeof(parent));

	Road startRoad(start,start,0);

	q.push(startRoad);

	while(!q.empty()) {
		Road currRoad = q.front(); q.pop();
		int vertex1 = currRoad.vertex1;
		int vertex2 = currRoad.vertex2;
		int speed = currRoad.speed;
		for (int i=0;i<(int)adjList[vertex2].size();i++){
			int nextVertex2 = adjList[vertex2][i].first;
			if ((adjList[vertex2][i].second >= speed) && (!visited[vertex2][nextVertex2])) {
				parent[vertex2] = vertex1;
				parent[nextVertex2] = vertex2;
				visited[vertex2][nextVertex2] = true;
				visited[nextVertex2][vertex2] = true;

				Road nextRoad(vertex2,nextVertex2,adjList[vertex2][i].second);
				q.push(nextRoad);

				if(nextVertex2 == end) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	bool first = true;
	int n;
	while(cin >> n) {
		init();
		if (first){
			first = false;
		}
		else {
			printf("\n");
		}
		int currMapIndex = 0;
		for(int i=0;i<n;i++){
			string cityName1, cityName2;
			int speed, city1, city2;
			cin >> cityName1 >> cityName2 >> speed;
			stoiIter = stringToInt.find(cityName1);
			if (stoiIter == stringToInt.end()) {
				stringToInt.insert(pair<string,int>(cityName1,currMapIndex));
				intToString.insert(pair<int,string>(currMapIndex,cityName1));
				city1 = currMapIndex++;
			}
			else{
				city1 = stoiIter->second;
			}
			stoiIter = stringToInt.find(cityName2);
			if (stoiIter == stringToInt.end()) {
				stringToInt.insert(pair<string,int>(cityName2,currMapIndex));
				intToString.insert(pair<int,string>(currMapIndex, cityName2));
				city2 = currMapIndex++;
			}
			else{
				city2 = stoiIter->second;
			}
			adjList[city1].push_back(pair<int,int>(city2,speed));
			adjList[city2].push_back(pair<int,int>(city1,speed));
		}
		sortInput();

		string startCityName, endCityName;
		cin >> startCityName >> endCityName;

		stoiIter = stringToInt.find(startCityName);
		if(stoiIter == stringToInt.end()) {
			printf("No valid route.\n");
			continue;
		}
		int startCity = stoiIter->second;

		stoiIter = stringToInt.find(endCityName);
		if(stoiIter == stringToInt.end()) {
			printf("No valid route.\n");
			continue;
		}
		int endCity = stoiIter->second;

		if(!bfs(startCity,endCity)){
			printf("No valid route.\n");
			continue;
		}
		else {

			stack<string> ans;
			int index = endCity;
			while(index != startCity){
				itosIter = intToString.find(index);
				ans.push(itosIter->second);
				index = parent[index];
			}	

			itosIter = intToString.find(startCity);
			printf("%s",(itosIter->second).c_str());
			while (!ans.empty()){
				printf(" %s",ans.top().c_str());
				ans.pop();
			}
			printf("\n");
		}

	}
	return 0;
}