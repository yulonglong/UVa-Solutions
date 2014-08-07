//Steven Kester Yuwono - UVa 10813 - Traditional BINGO

#include <iostream>
using namespace std;

bool isBingo(int grid[][7]){
	for(int i=0;i<6;i++){
		if(grid[i][5]==4){
			return true;
		}
	}
	for(int i=0;i<6;i++){
		if(grid[5][i]==4){
			return true;
		}
	}
	if(grid[6][6]==4){
		return true;
	}
	return false;
}

void mark (int grid[][7], int num){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(grid[i][j]==num){
				grid[i][j]=-1;
				grid[i][5]++;
				grid[5][j]++;
				if(i==j){
					grid[5][5]++;
				}
				else if((i+j)==4){
					grid[6][6]++;
				}
			}
		}
	}
}

int main(){
	bool bingo=false;
	int counter=0;
	int tempInt;
	int grid[7][7];
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			grid[i][j]=-1;
		}
	}
	grid[2][5]++;
	grid[5][2]++;
	grid[5][5]++;
	grid[6][6]++;
	
	int n=0;
	cin >> n ;
	while (n--){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if((i==2)&&(j==2)){
				}
				else{
					cin >> tempInt;
					grid[i][j]=tempInt;
				}
			}
		}
		
		for(int i=1;i<=75;i++){
			cin >> tempInt;
			if(!bingo){
				mark(grid,tempInt);
				counter=i;
				bingo=isBingo(grid);
			}	
		}
		
		cout << "BINGO after " << counter << " numbers announced" << endl;
		/*
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}*/
		
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				grid[i][j]=-1;
			}
		}
		grid[2][5]++;
		grid[5][2]++;
		grid[5][5]++;
		grid[6][6]++;
		counter=0;
		bingo=false;
	}
	return 0;
}
