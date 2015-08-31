// Steven Kester Yuwono - UVa 12243
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string line;
	while (getline(cin,line)) {
		if (line == "*") break;
		istringstream istream(line);
		string word; istream >> word;
		char letter = tolower(word[0]);
		bool valid = true;
		while (istream >> word) {
			if (letter != tolower(word[0])) {
				valid = false;
				break;
			}
		}
		if (valid) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	return 0;
}
