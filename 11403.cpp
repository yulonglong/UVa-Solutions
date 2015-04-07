// Steven Kester Yuwono - UVa 11403

#include <iostream>
#include <vector>
using namespace std;

vector<string> line;

string createLine(int n){
	string ans = "";
	for(int i=0;i<n;i++){
		ans = ans + "-";
	}
	return ans;
}

string createSpace(int n) {
	string ans = "";
	for(int i=0;i<n;i++){
		ans = ans + " ";
	}
	return ans;
}

string createZero(int n) {
	string ans = "";
	for(int i=0;i<n;i++){
		ans = ans + "0";
	}
	return ans;
}

void updateStringLength(int start) {
	int maxLength = line[line.size()-1].length();
	for(int i=start;i<(int)line.size();i++){
		while(line[i].length() < maxLength) {
			line[i] = " " + line[i];
		}
	}
}

void trimString() {
	int maxLength = line[line.size()-1].length();
	for(int i=0;i<(int)line.size();i++){
		int index = -1;
		for(int j=line[i].length()-1;j>=0;j--) {
			if(line[i][j] == ' '){
				index = j;
			}
			else break;
		}
		if(index != -1){
			line[i] = line[i].substr(0,index);
		}
	}
}

string getResult() {
	string result = "";
	int maxLength = line[line.size()-1].length();
	int carryForward=0;
	for(int k=maxLength-1;k>=0;k--){
		int count = carryForward;
		carryForward = 0;
		for(int i=3;i<(int)line.size();i++){
			if(line[i][k]=='1') {
				count++;
			}
		}
		carryForward += count/2;

		if(count%2 == 0){
			result = "0" + result;
		}
		else{
			result = "1" + result;
		}
	}
	while(carryForward>0){
		if(carryForward%2 == 0){
			result = "0" + result;
			carryForward -= 2;
		}
		else {
			result = "1" + result;
			carryForward -= 1;
		}
	}
	return result;
}

int main () {
	string a,b;
	bool first = true;
	while(cin >> a >> b) {
		if((a=="0")&&(b=="0")) {
			break;
		}
		if(first) first = false;
		else cout << endl;

		line.clear();
		line.push_back(a); line.push_back(b);
		int maxLength = max(a.length(),b.length());
		string firstLine = createLine(maxLength);
		line.push_back(firstLine);

		for(int i=0;i<(int)b.length();i++){
			char curr = b[b.length()-1-i];
			if(curr == '1'){
				string thisLine = a + createSpace(i);
				line.push_back(thisLine);
			}
			else if(curr == '0') {
				string thisLine = createZero(a.length()) + createSpace(i);
				line.push_back(thisLine);
			}
		}

		updateStringLength(3);
		string result = getResult();
		int secondMaxLength = max(line[line.size()-1].length(),result.length());
		string secondLine = createLine(secondMaxLength);

		line.push_back(secondLine);
		line.push_back(result);
		updateStringLength(0);
		trimString();

		for(int i=0;i<(int)line.size();i++){
			cout << line[i] << endl;
		}
	}
}