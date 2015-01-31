//Steven Kester Yuwono - UVa 1329

#include <cstdio>
#include <cmath>
#include <vector>
#define MAX 20010
using namespace std;

int parent[MAX]; //keep track of the parent of a vertex
int dist[MAX]; //keep track of the distance of a vertex to its parent

void clearCache() {
	for(int i=0;i<MAX;i++){
		parent[i] = i;
		dist[i] = 0;
	}
}

// Semi DP / Caching
int findDist(int vertex) {
	if(vertex == parent[vertex]) {
		return vertex;
	}
	int topVertex = findDist(parent[vertex]);
	dist[vertex] += dist[parent[vertex]];
	parent[vertex] = topVertex;
	return topVertex;
}

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--){
		clearCache();
		int N;
		scanf("%d",&N);
		char command;
		while ((scanf("%c",&command)==1)&&(command!='O')) {
			if(command == 'E') {
				int I;
				scanf("%d",&I);
				findDist(I);
				printf("%d\n",dist[I]);
			}
			else if(command == 'I') {
				int I, J;
				scanf("%d %d",&I,&J);
				parent[I] = J;
				dist[I] = abs(I-J);
				dist[I] %= 1000;
			}
		}
	}
	return 0;
}
