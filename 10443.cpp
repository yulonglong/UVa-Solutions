//10443 - Rock

#include <iostream>
using namespace std;

char getChar (char grid[][101], int r, int c, int x, int y){
	char winChar='0';
	if(grid[x][y]=='S'){
		winChar='R';
	}
	else if(grid[x][y]=='P'){
		winChar='S';
	}
	else if(grid[x][y]=='R'){
		winChar='P';
	}
	if(x-1>=0){
		if(grid[x-1][y]==winChar){
			return winChar;
		}
	}
	if(y-1>=0){
		if(grid[x][y-1]==winChar){
			return winChar;
		}
	}
	if(x+1<=r-1){
		if(grid[x+1][y]==winChar){
			return winChar;
		}
	}
	if(y+1<=c-1){
		if(grid[x][y+1]==winChar){
			return winChar;
		}
	}
	return grid[x][y];
}


void process(char grid[][101], char newGrid[][101],int r, int c){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			newGrid[i][j]=grid[i][j];
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			newGrid[i][j]=getChar(grid,r,c,i,j);
		}
	}
}

int main(){
	int r=0;
	int c=0;
	int d=0;
	char grid[101][101];
	char newGrid[101][101];
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			grid[i][j]='0';
		}
	}
	
	int n=0;
	cin >> n;
	for(int z=0;z<n;z++){
		cin >> r >> c >> d;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> grid[i][j];
			}
		}
		while(d--){
			process(grid,newGrid,r,c);
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					grid[i][j]=newGrid[i][j];
				}
			}
		}
		
		if(z>0){
			cout << endl;
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cout << grid[i][j];
			}
			cout << endl;
		}
		
	}
	return 0;
}
