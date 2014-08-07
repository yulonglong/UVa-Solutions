//Steven Kester Yuwono - UVa 10945 - Mother bear

#include <iostream>
using namespace std;


bool isPalindrome(char* word, int len){
	if(len==1){
		return true;
	}
	else if(len==2){
		if(word[0]!=word[1]){
			return false;
		}
	}
	for (int i=0;i<(len+1)/2;i++){
		if(word[i]!=word[len-1-i]){
			return false;
		}
	}
	return true;
}

bool isChar(char ch){
	if((ch>='a')&&(ch<='z')){
		return true;
	}
	return false;
}

char toLower(char ch){
	if((ch>='A')&&(ch<='Z')){
		return ch+32;
	}
	return ch;
}

int trimWords(string word,char* charWord){
	//cout << word << endl;
	int wordLen=word.length();
	int counter=0;
	for(int i=0;i<wordLen;i++){
		word[i]=toLower(word[i]);
		if(isChar(word[i])){
			charWord[counter++]=word[i];
		}
	}
	/*
	for(int i=0;i<counter;i++){
		cout << charWord[i];
	}
	cout << endl;*/
	return counter;
}

int main(){
	string word;
	getline(cin,word);
	char* newWord;
	newWord = new char[300];
	int len=0;
	
	while(word!="DONE"){
		len=trimWords(word,newWord);
		if(isPalindrome(newWord,len)){
			cout << "You won't be eaten!" << endl;
		}
		else{
			cout << "Uh oh.." << endl;
		}
		
		newWord = new char[300];
		len=0;
		getline(cin,word);
	}
	return 0;
}
