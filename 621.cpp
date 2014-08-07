//Steven Kester Yuwono - UVa 621 - Secret Research

#include <iostream>
using namespace std;

bool isPositive(string word){
	if((word=="1")||(word=="4")||(word=="78")){
		return true;
	}
	return false;
}

bool isNegative(string word){
	string newWord = word.substr(word.length()-2);
	if(newWord=="35"){
		return true;
	}
	return false;
}

bool isFailed(string word){
	string frontWord = word.substr(0,1);
	string backWord = word.substr(word.length()-1);
	if((frontWord=="9")&&(backWord=="4")){
		return true;
	}
	return false;
}

bool isNotCompleted(string word){
	string frontWord = word.substr(0,3);
	if(frontWord=="190"){
		return true;
	}
	return false;
}

int main(){
	string word;
	
	int n;
	cin >> n;
	getline(cin,word);
	while(n--){
		getline(cin,word);
		if(isPositive(word)){
			cout << "+" << endl;
		}
		else if(isNegative(word)){
			cout << "-" << endl;
		}
		else if(isFailed(word)){
			cout << "*" << endl;
		}
		else if(isNotCompleted(word)){
			cout << "?" << endl;
		}
	}
	return 0;
}
