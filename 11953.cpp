// Steven Kester Yuwono - UVa 11953

#include <iostream>
#define MAX 102
using namespace std;

char field[MAX][MAX];

bool search(int x, int y, int n) {
	if(field[x][y] == '.'){
		return false;
	}
	bool alive = false;
	if(field[x][y] == 'x') {
		alive = true;
	}
	field[x][y] = '.';

	if(x-1>=0){
		alive = search(x-1,y,n) || alive;
	}
	if(x+1<n) {
		alive = search(x+1,y,n) || alive;
	}
	if(y-1>=0){
		alive = search(x,y-1,n) || alive;
	}
	if(y+1<n){
		alive = search(x,y+1,n) || alive;
	}

	return alive;
}

int main() {
	int tc; cin >> tc;
	for(int d=1;d<=tc;d++){
		int n; cin >> n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> field[i][j];
			}
		}
		int count = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if (search(i,j,n)) {
					count++;
				}
			}
		}
		cout << "Case " << d << ": " << count << endl;
	}
	return 0;
}