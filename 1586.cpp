//Steven Kester Yuwono - UVa 1586

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

double weight[100];

void init() {
	weight['C'] = 12.01;
	weight['H'] = 1.008;
	weight['O'] = 16.00;
	weight['N'] = 14.01;
	return;
}

double getMolarMass (string compound) {
	double score = 0;
	string prevNum;
	char prevChar = compound[0];
	bool tryNum = false;

	for(int i=1;i<(int)compound.length();i++){
		if ((isalpha(compound[i]))&&(!tryNum)) {
			score += weight[prevChar];
			prevChar = compound[i];
		}
		if ((isalpha(compound[i]))&&(tryNum)) {
			score += weight[prevChar]*(double)atoi(prevNum.c_str());
			tryNum = false;
			prevNum = "";
			prevChar = compound[i];
		}
		if (isdigit(compound[i])) {
			tryNum = true;
			prevNum = prevNum + compound[i];
		}
	}

	if(tryNum) {
		score += weight[prevChar]*(double)atoi(prevNum.c_str());
	}
	else {
		score += weight[prevChar];
	}
	return score;
}

int main() {
	init();

	int tc;
	string line;
	getline(cin,line);
	tc = atoi(line.c_str());

	while (tc--) {
		getline(cin,line);
		printf("%.3f\n",getMolarMass(line));
	}
	return 0;
}