//Steven Kester Yuwono - UVa 11278

#include <iostream>
using namespace std;

string qwertylower = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
string dvoraklower = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
string qwertyhigher = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
string dvorakhigher = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

char convertLetter(char x) {
	for(int i=0;i<(int)qwertylower.length();i++){
		if(x == qwertylower[i]) {
			return dvoraklower[i];
		}
		if(x == qwertyhigher[i]) {
			return dvorakhigher[i];
		}
	}
}

void convertString (string& line) {
	for(int i=0;i<(int)line.length();i++){
		if(line[i] == ' '){
			continue;
		}
		line[i] = convertLetter(line[i]);
	}
}

int main() {
	string line;
	while(getline(cin,line)) {
		convertString(line);
		cout << line << endl;
	}
	return 0;
}