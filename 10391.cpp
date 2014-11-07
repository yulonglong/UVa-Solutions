//Steven Kester Yuwono - UVa 10391

#include <iostream>
#include <cstring>
#include <set>
using namespace std;

set<string> wordSet;
set<string> answerSet;

bool wordExists(string word){
	set<string>::iterator iter;
	iter = wordSet.find(word);
	if(iter == wordSet.end()){
		return false;
	}
	return true;
}

int main(){
	string tempword;

	while(getline(cin,tempword)){
		wordSet.insert(tempword);
	}

	int size = wordSet.size();
	set<string>::iterator iter1;
	set<string>::iterator iter2;
	string word;
	string prevword;

	for(iter1=wordSet.begin();iter1!=wordSet.end();iter1++){
		prevword = *iter1;
		for(iter2=iter1,iter2++;iter2!=wordSet.end();iter2++){
			int length = prevword.length();
			word = *iter2;
			int length2 = word.length();
			if(length > length2){
				break;
			}
			string word1 = word.substr(0,length);
			string word2 = word.substr(length);
			if(word1 != prevword){
				break;
			}
			if(wordExists(word2)){
				answerSet.insert(word);
			}
			
		}
	}

	for(iter1=answerSet.begin();iter1!=answerSet.end();iter1++){
		cout << *iter1 << endl;
	}
	return 0;
}