// Steven Kester Yuwono - UVa 490

#include <iostream>
using namespace std;

int main() {
	string lines[105];
	int index=0;
	int longest = 0;
	while(getline(cin,lines[index])) {
		if(longest < lines[index].length()) {
			longest = lines[index].length();
		}
		index++;
	}
	for(int j=0;j<longest;j++){
		for(int i=index-1;i>=0;i--){
			if (j >= lines[i].length()) cout << " ";
			else cout << lines[i][j];
		}
		cout << endl;
	}
	return 0;
}
