//Steven Kester Yuwono - UVa 10361

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
	int tc;
	cin >> tc;

	string temp;
	getline(cin,temp);//dummy getline

	for(int d=0;d<tc;d++){
		string sentence1;
		string sentence2;
		getline(cin,sentence1);
		getline(cin,sentence2);
		string s[6];

		//first line
		istringstream stream1(sentence1);
		getline(stream1,s[1],'<');
		getline(stream1,s[2],'>');
		getline(stream1,s[3],'<');
		getline(stream1,s[4],'>');
		getline(stream1,s[5]);
		cout << s[1] << s[2] << s[3] << s[4] << s[5] << endl;

		//second line
		istringstream stream2(sentence2);
		getline(stream2,s[0],'.');
		cout << s[0] << s[4] << s[3] << s[2] << s[5] << endl;
	}

	return 0;
}