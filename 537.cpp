// Steven Kester Yuwono - UVa 537

#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;


bool isP = true;
bool isU = true;
bool isI = true;
string str;
double P,U,I;

void process(int curr) {
	string temp = "";
	int i = 0;
	for (i = curr+1;!isalpha(str[i]);i++) {
		temp += str[i];
	}

	char prefix = str[i];
	double V = atof(temp.c_str());

	if (prefix == 'm') V /= 1000;
	else if (prefix == 'k') V *= 1000;
	else if (prefix == 'M') V *= 1000000;
	
	if (str[curr-1] == 'P') {
		isP = false;
		P = V;
	}
	else if (str[curr-1] == 'U') {
		isU = false;
		U = V;
	}
	else if (str[curr-1] == 'I') {
		isI = false;
		I = V;
	}
}

int main() {
	int tc;
	scanf("%d\n", &tc);
	for (int d = 1; d <= tc; d++) {
		isP = isU = isI = true;
		getline(cin, str);

		int first = str.find_first_of("=");
		int last = str.find_last_of("=");

		process(first);
		process(last);
		
		printf("Problem #%d\n", d);
		if (isP) printf("P=%.2lfW\n", U*I);
		else if (isU) printf("U=%.2lfV\n", P/I);
		else if (isI) printf("I=%.2lfA\n", P/U);
		printf("\n");
	}
	return 0;
}
