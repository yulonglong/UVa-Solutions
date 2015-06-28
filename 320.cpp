// Steven Kester Yuwono - UVa 320

#include <iostream>
#include <cstring>
using namespace std;

bool grid[33][33];

int main() {
	int tc; cin >> tc;
	for(int d=1;d<=tc;d++){
		memset(grid,false,sizeof(grid));
		int x,y; cin >> x >> y;
		char direction;
		while (true) {
			cin >> direction;
			if(direction == '.') break;
			if(direction=='E') {
				x++;
				grid[x-1][y-1] = true;
			}
			if(direction=='N') {
				y++;
				grid[x][y-1] = true;
			}
			if(direction=='W') {
				x--;
				grid[x][y] = true;
			}
			if(direction=='S'){
				y--;
				grid[x-1][y] = true;
			}
		}
		cout << "Bitmap #" << d << endl;
		for(int i=31;i>=0;i--){
			for(int j=0;j<=31;j++){
				if (grid[j][i]) cout << 'X';
				else cout << '.';
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}