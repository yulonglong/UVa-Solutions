// Steven Kester Yuwono - UVa 10222

#include <iostream>
using namespace std;

char encoded[] = " abcdefghijklmnopqrstuvwxyz`1234567890-=[];',./\\";
char decoded[] = "  czaqsdfyghjbvui w etx  r   `1234567890opklnm,[";

char decode(char letter) {
	letter = tolower(letter);
	for(int i=0;i<75;i++){
		if(encoded[i] == letter){
			return decoded[i];
		}
	}
	return ' ';
}

int main() {
	string line;
	getline(cin,line);
	for(int i=0;i<line.length();i++){
		cout << decode(line[i]);
	}
	cout << endl;
	return 0;
}