//Steven Kester Yuwono - UVa 11221 - Magic square palindromes.

#include <iostream>
#include <cmath>
using namespace std;


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

bool is_perfect_square(int n, int &root2) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    root2=root;
    return n == root * root;
}

bool isMagicPalindrome(char* newWord,int size){
	char word1[10001];
	char word2[10001];
	char word3[10001];
	char word4[10001];
	
	char grid[101][101];
	int counter=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			grid[i][j]=newWord[counter++];
		}
	}
	
	counter=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			word1[counter++]=grid[i][j];
		}
	}
	
	counter=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			word2[counter++]=grid[j][i];
		}
	}
	
	counter=0;
	for(int i=size-1;i>=0;i--){
		for(int j=size-1;j>=0;j--){
			word3[counter++]=grid[i][j];
		}
	}
	
	counter=0;
	for(int i=size-1;i>=0;i--){
		for(int j=size-1;j>=0;j--){
			word4[counter++]=grid[j][i];
		}
	}
	
	for(int i=0;i<counter;i++){
		if((word1[i]==word2[i])&&(word2[i]==word3[i])&&(word3[i]==word4[i])){
		}
		else{
			return false;
		}
	}
	return true;
}	

int main(){
	int root=0;
	string word;
	
	char* newWord;
	newWord = new char[10500];
	int len=0;
	int n=0;
	cin >> n;
	getline(cin,word);
	for (int z=1;z<=n;z++){
		getline(cin,word);
		newWord = new char[10500];
		len=0;
		len=trimWords(word,newWord);
		cout << "Case #" << z << ":" << endl;
		if(!is_perfect_square(len,root)){
			cout << "No magic :(" << endl;
		}
		else{
			if(isMagicPalindrome(newWord,root)){
				cout << root << endl;
			}
			else{
				cout << "No magic :(" << endl;
			}
		}
		
		root=0;
	}
	return 0;
}
