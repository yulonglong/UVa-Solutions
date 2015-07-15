// Steven Kester Yuwono - UVa 10252

#include <iostream>
#include <cstring>
#define MAX 123
using namespace std;

int freq1[MAX];
int freq2[MAX];

int main() {
	string line1,line2;
	while(getline(cin,line1)) {
		getline(cin,line2);
		memset(freq1,0,sizeof(freq1));
		memset(freq2,0,sizeof(freq2));
		for(int i=0;i<(int)line1.length();i++){
			freq1[line1[i]]++;
		}
		for(int i=0;i<(int)line2.length();i++){
			freq2[line2[i]]++;
		}
		for(int i ='a';i<='z';i++){
			int maxChar = min(freq1[i],freq2[i]);
			for(int j=0;j<maxChar;j++){
				cout << (char)i;
			}
		}
		cout << endl;
	}
	return 0;
}
