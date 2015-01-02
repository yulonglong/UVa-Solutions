//Steven Kester Yuwono - UVa 758

#include <vector>
#include <cstdio>
#define MAXX 10
#define MAXY 15
using namespace std;

struct Node{
	int cluster;
	int x;
	int y;
};

char board[MAXX+1][MAXY+1];
char copyBoard[MAXX+1][MAXY+1];

void dropDownRealBoard(){
	for(int i=1;i<=MAXX;i++){
		for(int j=1;j<=MAXY;j++){
			if(board[i][j]=='E'){
				for(int k=i+1;k<=MAXX;k++){
					if(board[k][j]!='E'){
						board[i][j] = board[k][j];
						board[k][j] = 'E';
						break;
					}
				}
			}
		}
	}
}

void dropLeftRealBoard(){
	bool empty = true;
	for(int j=1;j<MAXY;j++){
		empty = true;
		for(int i=1;i<=MAXX;i++){
			if(board[i][j]!='E'){
				empty = false;
				break;
			}
		}
		if(empty){
			for(int k=j;k<MAXY;k++){
				for(int l=1;l<=MAXX;l++){
					board[l][k]=board[l][k+1];
					board[l][k+1] = 'E';
				}
			}
			bool allEmpty = true;
			for(int k=j;k<=MAXY;k++){
				for(int l=1;l<=MAXX;l++){
					if(board[l][k]!='E'){
						allEmpty = false;
						break;
					}
				}
				if(!allEmpty){
					break;
				}
			}

			if(allEmpty){
				return;
			}
			j--;
		}
	}
}

void dropRealBoard(){
	dropDownRealBoard();
	dropLeftRealBoard();
}

void updateRealBoard(int x, int y,char color){
	if((board[x][y]!=color)||(board[x][y]=='E')){
		return;
	}
	board[x][y] = 'E';
	if(x-1>=1){
		updateRealBoard(x-1,y,color);
	}
	if(x+1<=MAXY){
		updateRealBoard(x+1,y,color);
	}
	if(y-1>=1){
		updateRealBoard(x,y-1,color);
	}
	if(y+1<=MAXY){
		updateRealBoard(x,y+1,color);
	}
	return;
}

int search(int x, int y, char color){
	if((copyBoard[x][y]!=color)||(copyBoard[x][y]=='E')){
		return 0;
	}
	copyBoard[x][y] = 'E';
	int count = 1;
	if(x-1>=1){
		count += search(x-1,y,color);
	}
	if(x+1<=MAXY){
		count += search(x+1,y,color);
	}
	if(y-1>=1){
		count += search(x,y-1,color);
	}
	if(y+1<=MAXY){
		count += search (x,y+1,color);
	}
	return count;
}

int ballsRemaining(){
	int count = 0;
	for(int i=MAXX;i>=1;i--){
		for(int j=1;j<=MAXY;j++){
			if(board[i][j]!='E'){
				count++;
			}
		}
	}
	return count;
}


void getAnswer(vector<Node> &potentialAnswers, Node &answer){
	answer.cluster = 0;
	answer.x = 0;
	answer.y = 0;
	for(int i=0;i<(int)potentialAnswers.size();i++){
		if(answer.cluster < potentialAnswers[i].cluster){
			answer.cluster = potentialAnswers[i].cluster;
			answer.x = potentialAnswers[i].x;
			answer.y = potentialAnswers[i].y;
		}
	}
	return;
}

void duplicateBoard(){
	for(int i=MAXX;i>=1;i--){
		for(int j=1;j<=MAXY;j++){
			copyBoard[i][j] = board[i][j];
		}
	}
	return;
}

void printBoard(){
	for(int i=MAXX;i>=1;i--){
		for(int j=1;j<=MAXY;j++){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		if(d>1){
			printf("\n");
		}
		printf("Game %d:\n\n",d);

		for(int i=MAXX;i>=1;i--){
			for(int j=1;j<=MAXY;j++){
				scanf(" %c", &board[i][j]);
			}
		}

		int totalScore = 0;

		for(int z=1;;z++){
			duplicateBoard();
			vector<Node> potentialAnswers;
			Node answer;
			for(int j=1;j<=MAXY;j++){
				for(int i=1;i<=MAXX;i++){
					Node temp;
					temp.cluster = search(i,j,board[i][j]);
					temp.x = i;
					temp.y = j;
					potentialAnswers.push_back(temp);
				}
			}
			getAnswer(potentialAnswers,answer);


			if((answer.cluster!=0)&&(answer.cluster!=1)){
				int m = answer.cluster - 2;
				int currScore = (m*m);
				totalScore += currScore;
				//printBoard();
				
				printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",z,answer.x,answer.y,answer.cluster,board[answer.x][answer.y],currScore);
				updateRealBoard(answer.x,answer.y,board[answer.x][answer.y]);
				//printBoard();
				dropRealBoard();
				//printBoard();
			}
			else {
				int remaining = ballsRemaining();
				if(remaining == 0){
					totalScore += 1000;
				}
				printf("Final score: %d, with %d balls remaining.\n",totalScore,remaining);
				break;
			}
		}

	}
	return 0;
}