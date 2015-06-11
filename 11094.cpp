// Steven Kester Yuwono - UVa 11094

#include <iostream>
#include <cstring>
#define MAX 21
using namespace std;

char graph[MAX][MAX];
bool visited[MAX][MAX];
int globalX,globalY;
char land;

int traverse(int x, int y, int n, int m){
	if(visited[x][y]) return 0;
	if(graph[x][y] != land) return 0;
	visited[x][y] = true;
	int count = 1;
	if(x-1>=0) count += traverse(x-1,y,n,m);
	if(x+1<m) count += traverse(x+1,y,n,m);
	count += traverse(x,(y-1+n)%n,n,m);
	count += traverse(x,(y+1)%n,n,m);
	return count;
}

int main() {
	int n,m;
	while(cin >> m >> n) {
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin >> graph[i][j];
			}
		}
		memset(visited,false,sizeof(visited));
		cin >> globalX >> globalY;
		land = graph[globalX][globalY];
		traverse(globalX,globalY,n,m);
		int maxContinent = 0;

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if (!visited[i][j]) {
					maxContinent = max(maxContinent,traverse(i,j,n,m));
				}
			}
		}
		cout << maxContinent << endl;
	}
	return 0;
}
