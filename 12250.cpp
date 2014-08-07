//Steven Kester Yuwono - UVa 12250 - Language Detection

#include <iostream>
#include <string>
using namespace std;

string getLang(string word){
	if (word=="HELLO"){
		return "ENGLISH";
	}
	else if (word=="HOLA"){
		return "SPANISH";
	}
	else if (word=="HALLO"){
		return "GERMAN";
	}
	else if (word=="BONJOUR"){
		return "FRENCH";
	}
	else if (word=="CIAO"){
		return "ITALIAN";
	}
	else if (word=="ZDRAVSTVUJTE"){
		return "RUSSIAN";
	}
	return "UNKNOWN";
}

int main(){
	int counter=1;
	string word;
	getline(cin,word);
	while(word!="#"){
		cout << "Case " << counter << ": ";
		cout << getLang(word) << endl;
		counter++;
		getline(cin,word);
	}
	return 0;
}
