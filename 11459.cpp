//Steven Kester Yuwono - UVa 11459 - Snakes and Ladders

#include <iostream>
using namespace std;

int playerPos[1000001];

int main(){
	
	for(int i=0;i<1000001;i++){
		playerPos[i]=1;
	}
	int grid[101];
	for(int i=0;i<101;i++){
		grid[i]=i;
	}
	
	int start,end;
	int step;
	int n=0;
	int a,b,c;
	bool gameover=false;
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		while(b--){
			cin >> start >> end;
			grid[start]=end;
		}
		gameover=false;
		for(int i=0;i<c;i++){
			cin >> step;
			if(!gameover){
				int playerNum=(i%a)+1;
				
				playerPos[playerNum]+=step;
				if(playerPos[playerNum]>=100){
					playerPos[playerNum]=100;
					gameover=true;
				}
				playerPos[playerNum]=grid[playerPos[playerNum]];
				if(playerPos[playerNum]>=100){
					playerPos[playerNum]=100;
					gameover=true;
				}
			}
		}
		for(int i=1;i<=a;i++){
			cout << "Position of player " << i << " is " << playerPos[i] << "." << endl;
			playerPos[i]=1;
		}
		for(int i=0;i<101;i++){
			grid[i]=i;
		}
	}
	return 0;
}
