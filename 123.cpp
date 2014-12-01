//Steven Kester Yuwono - UVa 123

#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

string allToLower(string word){
	for(int i=0;i<(int)word.length();i++){
		word[i] = tolower(word[i]);
	}
	return word;
}

string allToUpper(string word){
	for(int i=0;i<(int)word.length();i++){
		word[i] = toupper(word[i]);
	}
	return word;
}

struct Data{
	string keyword;
	string word;
	int order1;
	int order2;
	bool operator() (const Data& lhs, const Data& rhs){
		if (lhs.keyword != rhs.keyword) {  
            return lhs.keyword > rhs.keyword;  
        }
        else if (lhs.order1 != rhs.order1) {  
            return lhs.order1 > rhs.order1;  
        }
        else {  
            return lhs.order2 > rhs.order2;  
        }  
	}
};

set<string> ignoreSet;
set<string>::iterator it;

int main(){
	string ignore;
	while((getline(cin,ignore))&&(ignore!="::")){
		ignoreSet.insert(allToLower(ignore));
	}

	priority_queue<Data,vector<Data>,Data> pq;

	int count1=0;
	string sentence;
	while(getline(cin,sentence)){
		istringstream istream(sentence);
		vector<string> sentenceVec;
		string word;
		while(istream>>word){
			sentenceVec.push_back(allToLower(word));
		}
		for(int i=0;i<(int)sentenceVec.size();i++){
			it = ignoreSet.find(sentenceVec[i]);
			if(it!=ignoreSet.end()){
				continue;
			}

			//if the word is not in the ignore list
			string newWord;
			string newKeyword;
			for(int j=0;j<(int)sentenceVec.size();j++){
				string currWord = sentenceVec[j];
				if(j==i){
					currWord = allToUpper(sentenceVec[j]);
					newKeyword = currWord;
				}
				if(j==0){
					newWord = newWord + currWord;
				}
				else{
					newWord = newWord + " " + currWord;
				}
			}

			Data newData;
			newData.keyword = newKeyword;
			newData.word = newWord;
			newData.order1 = count1;
			newData.order2 = i;
			pq.push(newData);
		}
		count1++;
	}

	while(!pq.empty()){
		cout << pq.top().word << endl;
		pq.pop();
	}


	return 0;
}