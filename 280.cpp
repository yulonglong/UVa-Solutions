//Steven Kester Yuwono - UVa 280

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> adjList[101];
bool visited[101];

void init(){
	for(int i=0;i<101;i++){
		adjList[i].clear();
	}
	memset(visited,false,sizeof(visited));
}



vector<int> getUnvisited(int numVertex){
	vector<int> tempUnvisited;
	for(int i=1;i<=numVertex; i++){
		if(!visited[i]){
			tempUnvisited.push_back(i);
		}
	}
	return tempUnvisited;
}

void traverse(int startVertex){
	queue<int> q;
	q.push(startVertex);
	while(!q.empty()){
		int currVertex = q.front();
		q.pop();
		for(int i=0;i<(int)adjList[currVertex].size();i++){
			if(!visited[adjList[currVertex][i]]){
				q.push(adjList[currVertex][i]);
				visited[adjList[currVertex][i]]=true;
			}
		}
	}
}

int main(){
	
	
	int N;
	cin >> N;
	while(N!=0){	
		init();
		int source;
		cin >> source;
		while(source!=0){
			int dest;
			cin >> dest;
			while(dest!=0){
				adjList[source].push_back(dest);
				//cout << source << " -> " << dest << endl; 
				cin >> dest;
				
			}
			cin >> source;
		}
		
		int subTc;
		cin >> subTc;
		for(int i=0;i<subTc;i++){
			memset(visited,false,sizeof(visited));
			int startVertex;
			cin >> startVertex;
			//cout << "start vertex " << startVertex << endl;
			traverse(startVertex);
			
			vector<int> unvisited = getUnvisited(N);
			cout << unvisited.size();
			for(int i=0;i<(int)unvisited.size();i++){
				cout <<  " " << unvisited[i];
			}
			cout << endl;
		}
		cin >> N;
	}

	
	return 0;
}
