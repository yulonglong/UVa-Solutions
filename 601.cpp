// Steven Kester Yuwono - UVa 601

#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
#define MAXN 85
using namespace std;

char board[MAXN][MAXN];
char boardOriginal[MAXN][MAXN];
bool visited[MAXN][MAXN];
set<pair<int,int> > toBeFilled;
int n;
bool successful;

void boardCopy(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			board[i][j] = boardOriginal[i][j];
		}
	}
	toBeFilled.clear();
}

void fillBoard(char target) {
	set<pair<int,int> >::iterator it;
	for(it = toBeFilled.begin(); it!=toBeFilled.end(); it++){
		board[it->first][it->second] = target;
	}
	return;
}

void dfs(int x,int y, char target) {
	if((visited[x][y])||(board[x][y] != target)){
		return;
	}
	visited[x][y] = true;
	if ((target== 'W')&&(y == n-1)) {
		successful = true;
		return;
	}
	if ((target== 'B')&&(x == n-1)) {
		successful = true;
		return;
	}
	if (x-1>=0){
		dfs(x-1,y,target);
	}
	if (y-1>=0){
		dfs(x,y-1,target);
	}
	if (x+1<n){
		dfs(x+1,y,target);
	}
	if (y+1<n){
		dfs(x,y+1,target);
	}
}

void dfsSpread(int x,int y, char target) {
	if((visited[x][y])||(board[x][y] != target)){
		return;
	}
	visited[x][y] = true;

	if (x-1>=0){
		if(board[x-1][y] == 'U') {
			toBeFilled.insert(pair<int,int>(x-1,y));
		}
		dfsSpread(x-1,y,target);
	}
	if (y-1>=0){
		if(board[x][y-1] == 'U') {
			toBeFilled.insert(pair<int,int>(x,y-1));
		}
		dfsSpread(x,y-1,target);
	}
	if (x+1<n){
		if(board[x+1][y] == 'U') {
			toBeFilled.insert(pair<int,int>(x+1,y));
		}
		dfsSpread(x+1,y,target);
	}
	if (y+1<n){
		if(board[x][y+1] == 'U') {
			toBeFilled.insert(pair<int,int>(x,y+1));
		}
		dfsSpread(x,y+1,target);
	}
}

int main() {
	while ((cin>>n)&&(n>0)) {
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> boardOriginal[i][j];
			}
		}
		boardCopy();

		// Check whether white wins
		successful = false;
		memset(visited,false,sizeof(visited));
		for(int i=0;i<n;i++){
			if(!visited[i][0]) {
				dfs(i,0,'W');
				if (successful){
					break;
				}
			}
		}
		if(successful){
			printf("White has a winning path.\n");
			continue;
		}

		// Check whether black wins
		successful = false;
		memset(visited,false,sizeof(visited));
		for(int i=0;i<n;i++){
			if(!visited[0][i]) {
				dfs(0,i,'B');
				if (successful){
					break;
				}
			}
		}
		if(successful){
			printf("Black has a winning path.\n");
			continue;
		}

		// Check whether white wins in one turn
		boardCopy();
		toBeFilled.clear();
		memset(visited,false,sizeof(visited));
		for(int i=0;i<n;i++){
			if(!visited[i][0]) {
				dfsSpread(i,0,'W');
			}
		}
		fillBoard('W');

		successful = false;
		memset(visited,false,sizeof(visited));
		for(int i=0;i<n;i++){
			if(!visited[i][0]) {
				dfs(i,0,'W');
				if (successful){
					break;
				}
			}
		}
		if(successful){
			printf("White can win in one move.\n");
			continue;
		}

		// Check whether black wins in one turn
		boardCopy();
		toBeFilled.clear();
		memset(visited,false,sizeof(visited));
		for(int i=0;i<n;i++){
			if(!visited[0][i]) {
				dfsSpread(0,i,'B');
			}
		}
		fillBoard('B');

		successful = false;
		memset(visited,false,sizeof(visited));
		for(int i=0;i<n;i++){
			if(!visited[0][i]) {
				dfs(0,i,'B');
				if (successful){
					break;
				}
			}
		}
		if(successful){
			printf("Black can win in one move.\n");
			continue;
		}

		// Nobody can win
		printf("There is no winning path.\n");

	}
	return 0;
}