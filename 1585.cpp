//Steven Kester Yuwono - UVa 1585

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

int main() {
	int tc;
	string line;
	getline(cin,line);
	tc = atoi(line.c_str());

	while (tc--) {
		getline(cin,line);
		int totalScore = 0;
		int prevScore = 0;
		for(int i=0;i<(int)line.length();i++){
			if (line[i]=='O'){
				prevScore++;
				totalScore += prevScore;
			}
			else if(line[i] == 'X'){
				prevScore = 0;
			}
		}
		cout << totalScore << endl;
	}
	return 0;
}