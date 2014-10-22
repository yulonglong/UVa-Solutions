//Steven Kester Yuwono - UVa 11060
//Topological Sorting (non-DFS)
//DFS cannot be used to solve this problem (wrong order in the output)

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 103
using namespace std;

//total number of drinks
int n;
//for graph
vector<int> adjList[MAX];
int inDegrees[MAX];
//for DFS
bool visited[MAX];
bool pointed[MAX];
stack<int> finishOrder;

//to map drink's name
map<string,int> nameToIndex;
map<int,string> indexToName;


int getIndex(string name){
	map<string,int>::iterator it;

	it = nameToIndex.find(name);
	return it->second;
}

string getName(int index){
	map<int,string>::iterator it;

	it = indexToName.find(index);
	return it->second;
}

void init(){
	for (int i=0;i<MAX;i++){
		adjList[i].clear();
	}
	nameToIndex.clear();
	indexToName.clear();
	memset(visited,0,sizeof(visited));
	memset(inDegrees,0,sizeof(inDegrees));
}

queue<int> toposort(){
	queue<int> result;
	queue<int> q;
	//put a vertex with in-degree 0 into q
	for(int i=0;i<n;i++){
		if(inDegrees[i]==0){
			q.push(i);
			break;
		}
	}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		result.push(v);
		visited[v] = true;
		for(int j=0;j<(int)adjList[v].size();j++){
			//updating the indegrees (-1) of its neighbours, because the edge is going to be removed
			int dest = adjList[v][j];
			inDegrees[dest]--;
		}
		//erase the outgoing edges
		adjList[v].clear();

		if(q.empty()){
			for(int i=0;i<n;i++){
				if((inDegrees[i]==0)&&(!visited[i])){
					q.push(i);
					break;
				}
			}
		}
		//cout << "A" << endl;
	}
	return result;
}


int main(){
	int d=1;
	
	while(cin>>n){
		init();		

		for(int i=0;i<n;i++){
			string drinkName;
			cin >> drinkName;
			nameToIndex.insert(pair<string,int>(drinkName,i));
			indexToName.insert(pair<int,string>(i,drinkName));
		}



		int m;
		cin >> m;

		for(int i=0;i<m;i++){
			string drinkNameFrom;
			string drinkNameTo;
			cin >> drinkNameFrom >> drinkNameTo;
			
			int indexFrom = getIndex(drinkNameFrom);
			int indexTo = getIndex(drinkNameTo);

			//cout << indexFrom << " " << indexTo << endl;

			adjList[indexFrom].push_back(indexTo);
			inDegrees[indexTo]++;
		}

		for(int i=0;i<n;i++){
			sort(adjList[i].begin(),adjList[i].end());
		}

		queue<int> result = toposort();


		printf("Case #%d: Dilbert should drink beverages in this order:",d);
		while(!result.empty()){
			printf(" %s",getName(result.front()).c_str());
			result.pop();
		}
		printf(".\n\n");



		d++;
	}
	return 0;
}