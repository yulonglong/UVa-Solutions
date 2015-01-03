//Steven Kester Yuwono - UVa 824

#include <cstdio>
using namespace std;

int map[3][3];
int map2[8];

int nextMove(){
	map2[0] = map[1][2];
	map2[1] = map[0][2];
	map2[2] = map[0][1];
	map2[3] = map[0][0];
	map2[4] = map[1][0];
	map2[5] = map[2][0];
	map2[6] = map[2][1];
	map2[7] = map[2][2];

	// find the previous grid and one step counter clockwise, hence +5
	map[1][1] = (map[1][1]+5)%8; 
	int prevDir = map[1][1];
	while(true){
		// try to find the first land by traversing its surrounding counter clockwise
		if(map2[map[1][1]] == 0){
			prevDir = map[1][1];
			map[1][1] = (map[1][1]+1)%8;
		}
		if(map2[map[1][1]] == 1){
			prevDir = map[1][1];
			map[1][1] = (map[1][1]-1+8)%8;
		}
		if(map2[prevDir]!=map2[map[1][1]]){
			if(map2[prevDir] == 1){
				return prevDir;
			}
			else{
				return map[1][1];
			}
		}
	}
	return -1;
}

int main(){
	int x,y,d;
	while ((scanf("%d",&x))&&(x!=-1)){
		scanf("%d %d",&y,&d);
		map[1][1] = d;
		for(int i=0;i<8;i++){
			int tx,ty,tt;
			scanf("%d %d %d",&tx,&ty,&tt);
			map[tx-x+1][ty-y+1] = tt;
		}
		printf("%d\n",nextMove());
	}
	return 0;
}