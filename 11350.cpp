// Steven Kester Yuwono - UVa 11350

#include <iostream>
using namespace std;

void processSternBrocot(string command) {
	unsigned long long ln, ld, rn, rd, mn, md; // left numerator, left denominator, etc...
	ln = 0; ld = 1; // 0/1
	mn = 1; md = 1; // 1/1
	rn = 1; rd = 0; // 1/0
	for (int i=0;i<(int)command.length();i++) {
		if(command[i] == 'R') {
			ln = mn; ld = md;
			mn = ln + rn;
			md = ld + rd;
		}
		else {
			rn = mn; rd = md;
			mn = ln + rn;
			md = ld + rd;
		}
	}
	cout << mn << "/" << md << endl;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		string command; cin >> command;
		processSternBrocot(command);
	}
	return 0;
}