// Steven Kester Yuwono - UVa 12414
#include <iostream>
#include <cstdio>
#define MAX 50
using namespace std;

bool isYuanFen(string name, int st) {
	char str[MAX];
	int index = 0;
	for(int i=0;i<(int)name.length();i++){
		int curr = name[i] - 'A' + st;
		sprintf(str+index,"%d",curr);
		while (str[index] != '\0') index++;
	}
	while (true) {
		if (str[1] == '\0' || str[2] == '\0') break;
		if (str[0] == '1' && str[1] == '0' && str[2] == '0' && str[3] == '\0') break;
		index=0;
		for(int i=1;str[i]!='\0';i++) {
			int first = str[i-1]-'0';
			int second = str[i]-'0';
			int result = (first+second)%10;
			str[index] = result +'0';
			index++;
		}
		str[index] = '\0';
	}
	if (str[0] == '1' && str[1] == '0' && str[2] == '0' && str[3] == '\0') return true;
	return false;
}


int main() {
	string line;
	while (getline(cin,line)) {
		int ans = -1;
		for(int i=1;i<=10000;i++){
			if (isYuanFen(line,i)) {
				ans = i;
				break;
			}
		}
		if (ans == -1) cout << ":(" << endl;
		else cout << ans << endl;
	}
	return 0;
}
