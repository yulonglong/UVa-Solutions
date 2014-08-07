//Steven Kester Yuwono - UVa 10260

#include <bits/stdc++.h>
using namespace std;

char getChar(char letter){
	if((letter=='B')||(letter=='F')||(letter=='P')||(letter=='V')){
		return '1';
	}
    else if((letter=='C')||(letter=='G')||(letter=='J')||(letter=='K')||(letter=='Q')||(letter=='S')||(letter=='X')||(letter=='Z')){
		return '2';
	}
	else if((letter=='D')||(letter=='T')){
		return '3';
	}
	else if (letter=='L'){
		return '4';
	}
	else if ((letter=='M')||(letter=='N')){
		return '5';
	}
	else if (letter=='R'){
		return '6';
	}
	return 'x';
}

int main(){
	string word;
	while(getline(cin,word)){
		int length=word.length();
		string answer;
		char prevChar = 'n';
		for(int i=0;i<length;i++){
			char tempChar = getChar(word[i]);
			if((tempChar!='x')&&(prevChar!=tempChar)){
				answer = answer +tempChar;
			}
			prevChar=tempChar;
		}
		cout << answer << endl;
	}
	return 0;
}
