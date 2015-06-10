// Steven Kester Yuwono - UVa 11697

#include <iostream>
#include <set>
#include <vector>
using namespace std;

char matrix[5][5];

void makeMatrix(vector<char> &keytable) {
	int fir = 0; int sec = 0;
	for(int i=0;i<(int)keytable.size();i++){
		matrix[fir][sec] = keytable[i];
		sec++;
		if(sec>=5) {
			sec = sec%5;
			fir++;
		}
	}
}

void findIndex(int &x, int &y, char letter){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(letter == matrix[i][j]) {
				x = i;
				y = j;
			}
		}
	}
}

int main() {
	int tc; cin >> tc;
	string temp; getline(cin,temp);
	while(tc--){
		string keyphrase; getline(cin,keyphrase);
		string message; getline(cin,message);

		vector<char> keytable;
		set<char> inserted;
		set<char>::iterator it;

		for(int i=0;i<(int)keyphrase.length();i++){
			if(isalpha(keyphrase[i])) {
				it = inserted.find(keyphrase[i]);
				if(it == inserted.end()) {
					keytable.push_back(keyphrase[i]);
					inserted.insert(keyphrase[i]);
				}
			}
		}
		for(int i=97;i<=122;i++){
			if(i==113) continue;
			char curr = (char)i;
			it = inserted.find(curr);
			if(it == inserted.end()) {
				keytable.push_back(curr);
				inserted.insert(curr);
			}
		}
		makeMatrix(keytable);
		

		string answer;
		string current = "";
		for(int i=0;i<(int)message.length();i++){
			if(isalpha(message[i])) {
				current = current + message[i];
			}
			if ((current.length() == 1) && (i == message.length()-1)) {
				current = current + "x";
			}
			if (current.length() == 2){
				int x0,y0;
				findIndex(x0,y0,current[0]);
				int x1,y1;
				findIndex(x1,y1,current[1]);
				if(current[0] == current[1]) {
					current[1] = 'x'; i--;
					findIndex(x1,y1,current[1]);
				}
				if (x0 == x1) {
					answer = answer + matrix[x0][(y0+1)%5];
					answer = answer + matrix[x1][(y1+1)%5];
				}
				else if (y0 == y1) {
					answer = answer + matrix[(x0+1)%5][y0];
					answer = answer + matrix[(x1+1)%5][y1];
				}
				else {
					answer = answer + matrix[x0][y1];
					answer = answer + matrix[x1][y0];
				}
				current = "";
			}
		}

		for(int i=0;i<(int)answer.length();i++){
			cout << (char)toupper(answer[i]);
		}
		cout << endl;

	}
	return 0;
}
