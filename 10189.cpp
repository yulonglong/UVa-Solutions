//Steven Kester Yuwono - UVa 10189 - Minesweeper

#include <iostream>
using namespace std;

int getNumMines(char field[][100],int x,int y,int m,int n){
	int count=0;
	if(x-1>=0){
		if(field[x-1][y]=='*'){
			count++;
		}
	}
	if(x+1<=m-1){
		if(field[x+1][y]=='*'){
			count++;
		}
	}
	if(y+1<=n-1){
		if(field[x][y+1]=='*'){
			count++;
		}
	}
	if(y-1>=0){
		if(field[x][y-1]=='*'){
			count++;
		}
	}
	if((x-1>=0)&&(y-1>=0)){
		if(field[x-1][y-1]=='*'){
			count++;
		}
	}
	if((x-1>=0)&&(y+1<=n-1)){
		if(field[x-1][y+1]=='*'){
			count++;
		}
	}
	if((x+1<=m-1)&&(y+1<=n-1)){
		if(field[x+1][y+1]=='*'){
			count++;
		}
	}
	if((x+1<=m-1)&&(y-1>=0)){
		if(field[x+1][y-1]=='*'){
			count++;
		}
	}
	
	return count;
}


int main(){
	int count=1;
	char field[100][100];
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			field[i][j]='.';
		}
	}
	int n=0;
	int m=0;
	cin >> n >> m;
	while(!((n==0)&&(m==0))){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> field[i][j];
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(field[i][j]=='.'){
					field[i][j]=getNumMines(field,i,j,n,m)+'0';
				}
			}
		}
		if(count>1){
			cout << endl;
		}
		
		cout << "Field #" << count << ":" << endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << field[i][j];
			}
			cout << endl;
		}
		
		
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				field[i][j]='.';
			}
		}
		count++;
		cin >> n >> m;
	}
	return 0;
}
