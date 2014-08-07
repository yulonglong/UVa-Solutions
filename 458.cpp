#include <iostream>
using namespace std;

int main(){
	string word;
	char temp;
	while(getline(cin,word)){
		for(unsigned int i=0;i<word.length();i++){
			temp=word[i]-7;
			cout << temp;
		}
		cout << endl;
	}
	return 0;
}
