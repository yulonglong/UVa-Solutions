//Steven Kester Yuwono - UVa 11492
//Single Souce Shortest Path - Dijkstra with special rules

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define MAX 4040
#define MAXLETTER 27
#define INF 2000000000
using namespace std;

struct Node{
	int dest;
	int cost;
	char initialLetter;
	bool operator () (const Node& lhs, const Node& rhs){
		return lhs.cost > rhs.cost;
	}
};

vector<Node> adjList[MAX];
map<string,int> languageToIndex;
map<int,string> indexToLanguage;

void init(){
	languageToIndex.clear();
	indexToLanguage.clear();
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
}

int getIndex(string word){
	map<string,int>::iterator it;
	it = languageToIndex.find(word);
	if(it == languageToIndex.end()){
		return -1;
	}
	return it->second;
}

string getLanguage(int index){
	map<int,string>::iterator it;
	it = indexToLanguage.find(index);
	if(it == indexToLanguage.end()){
		return "";
	}
	return it->second;
}

int insertLanguage(string word){
	map<string,int>::iterator it;
	it = languageToIndex.find(word);
	if(it == languageToIndex.end()){
		int newIndex = languageToIndex.size();
		languageToIndex.insert(pair<string,int>(word,newIndex));
		return newIndex;
	}
	else{
		return it->second;
	}
}

void setEdge(int indexStart, int indexEnd, int length, char initialLetter){
	Node tempNode;
	tempNode.dest = indexEnd;
	tempNode.cost = length;
	tempNode.initialLetter = initialLetter;
	adjList[indexStart].push_back(tempNode);
}

void printAdjList(int size){
	for(int i=0;i<size;i++){
		cout << "from " << i << endl;
		for(int j=0;j<(int)adjList[i].size();j++){
			cout << "(" << adjList[i][j].dest << "," << adjList[i][j].cost << ")" << endl;
		}
	}
}

int dijkstra(int startIndex, int endIndex, int numVertex){
	//initialize distance table
	int dist[MAXLETTER][MAX];
	for(int h=0;h<MAXLETTER;h++){
		for(int i=0;i<numVertex;i++){
			dist[h][i] = INF;
		}
	}

	priority_queue<Node,vector<Node>,Node> pq;
	//set the cost to the first vertex to zero
	for(int i=0;i<MAXLETTER;i++){
		dist[i][startIndex] = 0;
	}

	//initialize and push first vertex
	Node startNode;
	startNode.dest = startIndex;
	startNode.cost = 0;
	startNode.initialLetter = 'z'+1;
	pq.push(startNode);

	//standard dijkstra, with special rule (first letter cannot be the same) and 27 split nodes inside a vertex
	while(!pq.empty()){
		Node currNode = pq.top();
		pq.pop();
		int currIndex = currNode.dest;
		int currCost = currNode.cost;
		char currInitialLetter = currNode.initialLetter;
		if(dist[currInitialLetter-'a'][currIndex]<currCost){
			continue;
		}

		for(int i=0;i<(int)adjList[currIndex].size();i++){
			int destIndex = adjList[currIndex][i].dest;
			int destCost = adjList[currIndex][i].cost;
			char destInitialLetter = adjList[currIndex][i].initialLetter;
			if ((dist[destInitialLetter-'a'][destIndex] > currCost + destCost)&&(destInitialLetter!=currInitialLetter)){
				dist[destInitialLetter-'a'][destIndex] = currCost + destCost;
				Node destNode;
				destNode.dest = destIndex;
				destNode.cost = currCost + destCost;
				destNode.initialLetter = destInitialLetter;
				pq.push(destNode);
			}
		}
	}

	int ans = INF;
	//get the best answer from the endIndex vertex
	for(int i=0;i<MAXLETTER;i++){
		if(ans>dist[i][endIndex]){
			ans = dist[i][endIndex];
		}
	}
	return ans;
}


int main(){
	int M;
	string O, D;

	while ((cin>>M)&&(M>0)){
		init();
		//cout << "test" << endl;
		cin >> O >> D;
		for(int i=0;i<M;i++){
			string start, end, word;
			cin >> start >> end >> word;
			int length = word.length();
			int indexStart = insertLanguage(start);
			int indexEnd = insertLanguage(end);
			char initialLetter = word[0];
			setEdge(indexStart,indexEnd,length,initialLetter);
			setEdge(indexEnd,indexStart,length,initialLetter);
		}

		int oIndex = getIndex(O);
		int dIndex = getIndex(D);
		
		if((oIndex==-1)||(dIndex==-1)){
			cout << "impossivel" << endl;
		}
		else{
			int result = dijkstra(oIndex,dIndex,languageToIndex.size());
			if(result == INF){
				cout << "impossivel" << endl;
			}
			else{
				cout << result << endl;
			}
		}
		
	}

	return 0;	
}