// Steven Kester Yuwono - UVa 1636

#include <iostream>
#include <cmath>
using namespace std;

void calculateProbability(int &empty, int &filled, int &nextEmpty, int &nextFilled, string line) {
	int prev = line.length() - 1;
	for(int i=0;i<(int)line.length();i++){
		if(line[i] == '0') {
			empty++;
			if (line[prev] == '0'){
				nextEmpty++;
			}
		}
		else if (line[i] == '1'){
			filled++;
			if (line[prev] == '0'){
				nextFilled++;
			}
		}
		prev = i;
	}
}

int main () {
	string line;
	while (getline(cin,line)) {
		int empty= 0,filled=0,nextEmpty=0,nextFilled=0;
		calculateProbability(empty,filled,nextEmpty,nextFilled,line);
		double rotate = (double)empty/((double)empty+(double)filled);
		double shoot = (double)nextEmpty/((double)nextEmpty+(double)nextFilled);
		if(fabs(rotate-shoot) < 0.0000001) {
			cout << "EQUAL" << endl;
		}
		else if(rotate > shoot) {
			cout << "ROTATE" << endl;
		}
		else if (shoot > rotate) {
			cout << "SHOOT" << endl;
		}
	}
}