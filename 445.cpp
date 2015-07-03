// Steven Kester Yuwono - UVa 445

#include <iostream>
using namespace std;

void printLine (int num) {
	for(int i=0;i<num;i++){
		cout << num;
	}
	cout << endl;
}

int main() {
	int tc; cin >> tc;

	while(tc--) {
		int amp, freq;
		cin >> amp >> freq;

		for(int i=0;i<freq;i++){
			for(int j=1;j<=amp;j++) {
				printLine(j);
			}
			for(int j=amp-1;j>=1;j--) {
				printLine(j);
			}
			if ((tc!=0)||(i!=freq-1)) cout << endl;
		}

	}
	return 0;
}
