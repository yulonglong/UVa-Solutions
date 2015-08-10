// Steven Kester Yuwono - UVa 10922

#include <iostream>
using namespace std;

bool isNine(string &number, int &deg) {
	deg = 1;
	int total = 0;
	for(int i=0;i<(int)number.length();i++){
		total += (int)number[i]-48;
	}
	while (total>9) {
		deg++;
		int curr = total;
		total = 0;
		while (curr>0){
			total += curr%10;
			curr/=10;
		}
	}
	if (total==9) return true;
	return false;
}

int main() {
	string line;
	while (getline(cin,line)) {
		if (line == "0") break;
		int deg = 0;
		if (isNine(line,deg)) {
			cout << line << " is a multiple of 9 and has 9-degree " <<  deg << "." << endl;
		}
		else {
			cout << line << " is not a multiple of 9." << endl;
		}
	}
	return 0;
}
