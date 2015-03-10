// Steven Kester Yuwono - UVa 10878

#include <iostream>
using namespace std;

int main()
{
	string line;
	while (getline(cin,line)) {
		if (line[0] == '|') {
			int letter = 0;
			for (int i=1; i<(int)line.length()-1; i++){
				if ((line[i] == ' ') || (line[i] == 'o')) {
					letter = letter * 2;
				}
				if (line[i] == 'o') {
					letter++;
				}
			}
			cout << (char) letter;
		}
	}
	return 0;
}