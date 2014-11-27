//Steven Kester Yuwono - UVa 116612

#include <iostream>
using namespace std;

int main(){
	int hwayLength;
	while((cin>>hwayLength)&&(hwayLength>0)){
		int shortestDist = hwayLength;
		int lastD = -hwayLength;
		int lastR = -hwayLength;
		string hway;
		cin >> hway;
		for(int i=0;i<hwayLength;i++){
			if(hway[i] == 'Z'){
				shortestDist = 0;
				break;
			}
			else if (hway[i] == 'R'){
				shortestDist = min(shortestDist,i-lastD);
				lastR = i;
			}
			else if (hway[i] == 'D'){
				shortestDist = min(shortestDist,i-lastR);
				lastD = i;
			}
		}
		cout << shortestDist << endl;
	}
	return 0;
}