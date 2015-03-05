// Steven Kester Yuwono - UVa 895

#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int dict[1001][30];
int curr[30];

int main() {
	string line;

	while(getline(cin,line)) {
		if(line == "#"){}
		memset(dict,0,sizeof(dict));
		int counter = 0;
		while (line !="#"){
			for(int i=0;i<line.length();i++){
				dict[counter][line[i]-'a']++;
			}
			counter++;
			getline(cin,line);
		}
		while (getline(cin,line) && (line !="#")){
			int ans = 0;
			memset(curr,0,sizeof(curr));
			istringstream istream(line);
			char letter;
			while(istream >> letter) {
				curr[letter-'a']++;
			}
			for(int i=0;i<counter;i++){
				bool valid = true;
				for(int j=0;j<27;j++){
					if(curr[j] < dict[i][j]) {
						valid=false;
						break;
					}
				}
				if(valid) {
					ans++;
				}
			}
			cout << ans << endl;
		}
	}
}