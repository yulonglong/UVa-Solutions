//Steven Kester Yuwono - UVa 12289 - One-Two-Three

#include <iostream>
using namespace std;

int getAns(string word){
	string one="one";
	string two="two";
	string three="three";
	int count=0;
	if (word.length()==5){
		for(int i=0;i<5;i++){
			if(word[i]!=three[i]){
				count++;
			}
		}
		if(count<=1){
			return 3;
		}
		
	}
	else if(word.length()==3){
		for(int i=0;i<3;i++){
			if(word[i]!=two[i]){
				count++;
			}
		}
		if(count<=1){
			return 2;
		}
		count=0;
		for(int i=0;i<3;i++){
			if(word[i]!=one[i]){
				count++;
			}
		}
		if(count<=1){
			return 1;
		}
		
	}
	return 0;
}

int main(){
	string word;
	int n=0;
	cin >> n;
	getline(cin,word);
	while(n--){
		getline(cin,word);
		cout << getAns(word) << endl;
	}
	
	return 0;
}
