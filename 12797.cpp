// Steven Kester Yuwono - UVa 12797

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 101
#define MAXL 10
using namespace std;

char graph[MAX][MAX];
bool visited[MAX][MAX];

int n;

void deepCopy(bool lhs[], bool rhs[]) {
	for(int i=0;i<MAXL;i++){
		rhs[i] = lhs[i];
	}
}

struct Node {
	int x;
	int y;
	bool upper[MAXL];
	bool lower[MAXL];
	int cost;
	Node() {};
	Node(int newx, int newy, bool newUpper[MAXL], bool newLower[MAXL], int newCost){
		x = newx;
		y = newy;
		deepCopy(newUpper,upper);
		deepCopy(newLower,lower);
		cost = newCost;
	}
};

bool isRedundant(Node& lhs, Node& rhs) {
	if ((lhs.x!=rhs.x) || (lhs.y!=rhs.y)) {
		return false;
	}
	for(int i=0;i<MAXL;i++){
		if(lhs.upper[i]!=rhs.upper[i])
			return false;
		if(lhs.lower[i]!=rhs.lower[i])
			return false;
	}
	return true;
}

int bfs() {
	vector<Node> visitedNode[MAX][MAX];
	bool firstLower[MAXL], firstUpper[MAXL];
	memset(firstLower,false,sizeof(firstLower));
	memset(firstUpper,false,sizeof(firstUpper));
	memset(visited,false,sizeof(visited));
	char first = graph[0][0];
	if(isupper(first)) {
		firstUpper[first-'A'] = true;
	}
	else {
		firstLower[first-'a'] = true;
	}

	char last = graph[n-1][n-1];
	if(isupper(last)) {
		firstUpper[last-'A'] = true;
	}
	else {
		firstLower[last-'a'] = true;
	}

	Node firstNode(0,0,firstUpper, firstLower, 1);

	queue<Node> q;
	q.push(firstNode);

	while(!q.empty()){
		Node currNode = q.front(); q.pop();
		int x = currNode.x;
		int y = currNode.y;
		//cout << x << "," << y << endl;

		bool lower[MAXL]; 
		deepCopy(currNode.lower,lower);
		bool upper[MAXL];
		deepCopy(currNode.upper,upper);
		int cost = currNode.cost;
		//cout << x << "," << y <<  " " << cost << endl;

		if ((x==n-1)&&(y==n-1)) {
			return cost;
		}
		if (visited[x][y]){
			bool cont = false;
			for(int i=0;i<(int)visitedNode[x][y].size();i++){
				if(isRedundant(currNode,visitedNode[x][y][i])) {
					cont = true;
					break;
				}
			}
			if(cont) {
				continue;
			}
			else {
				visitedNode[x][y].push_back(currNode);
			}
		}
		else {
			visited[x][y] = true;
			visitedNode[x][y].push_back(currNode);
		}

		bool newUpper[MAXL];
		bool newLower[MAXL];
		memset(newUpper,false,sizeof(newUpper));
		memset(newLower,false,sizeof(newLower));
		if(x-1>=0){
			char next = graph[x-1][y];
			if ((isupper(next))&&(!lower[next-'A'])) {
				deepCopy(upper,newUpper);
				deepCopy(lower,newLower);
				newUpper[next-'A'] = true;
				q.push(Node(x-1,y,newUpper,newLower,cost+1));
			}
			if ((islower(next))&&(!upper[next-'a'])) {
				deepCopy(upper,newUpper);
				deepCopy(lower,newLower);
				newLower[next-'a'] = true;
				q.push(Node(x-1,y,newUpper,newLower,cost+1));
			}
		}
		if(x+1<n){
			char next = graph[x+1][y];
			if ((isupper(next))&&(!lower[next-'A'])) {
				deepCopy(upper,newUpper);
				deepCopy(lower,newLower);
				newUpper[next-'A'] = true;
				q.push(Node(x+1,y,newUpper,newLower,cost+1));
			}
			if ((islower(next))&&(!upper[next-'a'])) {
				deepCopy(upper,newUpper);
				deepCopy(lower,newLower);
				newLower[next-'a'] = true;
				q.push(Node(x+1,y,newUpper,newLower,cost+1));
			}
		}
		if(y-1>=0){
			char next = graph[x][y-1];
			if ((isupper(next))&&(!lower[next-'A'])) {
				deepCopy(upper,newUpper);
				deepCopy(lower,newLower);
				newUpper[next-'A'] = true;
				q.push(Node(x,y-1,newUpper,newLower,cost+1));
			}
			if ((islower(next))&&(!upper[next-'a'])) {
				deepCopy(upper,newUpper);
				deepCopy(lower,newLower);
				newLower[next-'a'] = true;
				q.push(Node(x,y-1,newUpper,newLower,cost+1));
			}
		}
		if(y+1<n){
			char next = graph[x][y+1];
			if ((isupper(next))&&(!lower[next-'A'])) {
				deepCopy(upper,newUpper);
				deepCopy(lower,newLower);
				newUpper[next-'A'] = true;
				q.push(Node(x,y+1,newUpper,newLower,cost+1));
			}
			if ((islower(next))&&(!upper[next-'a'])) {
				deepCopy(upper,newUpper);
				deepCopy(lower,newLower);
				newLower[next-'a'] = true;
				q.push(Node(x,y+1,newUpper,newLower,cost+1));
			}
		}
	}
	return -1;
}

int main() {
	while(cin >> n) {
		for(int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin >> graph[i][j];
			}
		}
		cout << bfs() << endl;
	}
	return 0;
}