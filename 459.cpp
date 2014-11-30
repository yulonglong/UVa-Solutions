//Steven Kester Yuwono - UVa 459
//Finding connected components - DFS

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#define MAX 27
using namespace std;

vector<int> adjList[MAX];
bool visited[MAX];

void init(){
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
	memset(visited,0,sizeof(visited));
	return;
}

void dfs(int index){
	if(visited[index]){
		return;
	}
	visited[index]=true;
	for(int i=0;i<(int)adjList[index].size();i++){
		dfs(adjList[index][i]);
	}
	return;
}

bool traverse(int start){
	if(visited[start]){
		return false;
	}
	dfs(start);
	return true;
}

int main(){
	string tempstr;
	getline(cin,tempstr);
	int tc = atoi(tempstr.c_str());
	getline(cin,tempstr);

	for(int d=0;d<tc;d++){
		init();
		getline(cin,tempstr);
		char max = tempstr[0];
		while((getline(cin,tempstr))&&(tempstr.length()>0)){
			char first = tempstr[0];
			char second = tempstr[1];
			adjList[first-'A'].push_back(second-'A');
			adjList[second-'A'].push_back(first-'A');
		}
		int count = 0;
		for(int i=0;i<=max-'A';i++){
			if(traverse(i)){
				count += 1;
			}
		}
		if(d>0){
			cout << endl;
		}
		cout << count << endl;
	}
	return 0;
}