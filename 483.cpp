#include <iostream>
#include <sstream>
using namespace std;

int main(){
	string word;
	string word2;
	int count=0;
	while(getline(cin,word)){
		istringstream instream(word);
		while(getline(instream,word2,' ')){
			if(count>0){
				cout << " ";
			}
			for(int i=word2.length()-1;i>=0;i--){
				cout << word2[i];
			}
			count++;
		}
		cout << endl;
		count=0;
	}
	return 0;
}
