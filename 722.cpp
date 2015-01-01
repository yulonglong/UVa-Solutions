//Steven Kester Yuwono - UVa 722

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#define MAX 104
using namespace std;

char map[MAX][MAX];
int maxX, maxY;

void init(){
	memset(map,0,sizeof(map));
	maxX = 0;
	maxY = 0;
	return;
}

int findConnected(int x, int y){
	if (map[x][y]!='0'){
		return 0;
	}
	else {
		map[x][y]='1';
	}

	int count = 1;
	if(x+1<maxX){
		count = count + findConnected(x+1,y);
	}
	if(x-1>0){
		count = count + findConnected(x-1,y);
	}
	if(y+1<maxY){
		count = count + findConnected(x,y+1);
	}
	if(y-1>0){
		count = count + findConnected(x,y-1);
	}
	return count;
}

int main(){
	string temp;
	int tc;
	getline(cin,temp);
	tc = atoi(temp.c_str());
	getline(cin,temp); // to read the blank line
	for(int d=0;d<tc;d++){
		init();
		getline(cin,temp); // to read the row and column starting point;
		int startX,startY;
		istringstream istream1(temp);
		istream1 >> startY >> startX;

		int indexX = 1;
		int indexY = 1;
		while((getline(cin,temp))&&(temp.length()>0)){
			istringstream istream2(temp);
			char tempChar;
			indexX = 1;
			while(istream2 >> tempChar){
				map[indexX][indexY] = tempChar;
				indexX++;
			}
			indexY++;
		}
		maxX = indexX;
		maxY = indexY;

		if(d>0){
			cout << endl;
		}
		cout << findConnected(startX,startY) << endl;
	}
	return 0;
}