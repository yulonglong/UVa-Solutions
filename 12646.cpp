#include <iostream>
#include <string>
using namespace std;

string solve(string word){
	if((word=="0 1 1")||(word=="1 0 0")){
		return "A";
	}
	else if ((word=="1 0 1")||(word=="0 1 0")){
		return "B";
	}
	else if ((word=="1 1 0")||(word=="0 0 1")){
		return "C";
	}
	else{
		return "*";
	}
}

int main(){
	string word;
	while(getline(cin,word)){
		if(word.length()>0){
			cout << solve(word) << endl;
		}
	}
	return 0;
}
