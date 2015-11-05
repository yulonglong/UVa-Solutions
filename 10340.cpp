// Steven Kester Yuwono - UVa 10340

#include <iostream>
using namespace std;

int main() {
	string s,t;
	while (cin >> s >> t) {
		int sIndex = 0;
		int tIndex = 0;
		for(sIndex=0;((sIndex < (int)s.length()) && (tIndex < (int)t.length()));sIndex++){
			while (s[sIndex] != t[tIndex]) {
				tIndex++;
				if (tIndex == t.length()) {
					sIndex--;
					break;
				}
			}
			tIndex++;
		}
		if (sIndex == s.length()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
