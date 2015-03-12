// Steven Kester Yuwono - UVa 496

#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main() {
	string line1;
	string line2;
	while (getline(cin,line1) && getline(cin,line2)) {
		set<string> set1, set2;
		string number;

		istringstream istream1(line1.c_str());
		while (istream1 >> number) {
			set1.insert(number);
		}
		istringstream istream2(line2.c_str());
		while (istream2 >> number) {
			set2.insert(number);
		}

		set<string>::iterator it, itx;
		int numAinB = 0;
		for (it = set1.begin();it != set1.end(); it++ ){
			itx = set2.find(*it);
			if (itx!= set2.end()) {
				numAinB++;
			}
		}
		int numBinA = 0;
		for (it = set2.begin();it != set2.end(); it++ ){
			itx = set1.find(*it);
			if (itx!= set1.end()) {
				numBinA++;
			}
		}

		if ((numAinB == 0) && (numBinA == 0)) {
			cout << "A and B are disjoint" << endl;
		}
		else if ((numAinB == set1.size()) && (set1.size() < set2.size())) {
			cout << "A is a proper subset of B" << endl;
		}
		else if ((numBinA == set2.size()) && (set2.size() < set1.size())) {
			cout << "B is a proper subset of A" << endl;
		}
		else if ((numBinA == numAinB) && (numBinA == set1.size()) && (set1.size() == set2.size())) {
			cout << "A equals B" << endl;
		}
		else {
			cout << "I'm confused!" << endl;	
		}

	}
	return 0;
}