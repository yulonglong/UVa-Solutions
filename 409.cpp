//Steven Kester Yuwono - UVa 409 

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string convertToLower(string word){
	int length = word.length();
	for(int i=0;i<length;i++){
		word[i] = tolower(word[i]);
	}
	return word;
}

int contains(string word, string keyword){
	int wordlength = word.length();
	string tempword = "";
	int counter = 0;
	for(int i=0;i<wordlength;i++){
		if(!isalpha(word[i])){
			if(tempword==keyword){
				counter++;
			}
			tempword = "";
		}
		else{
			tempword = tempword + word[i];
		}
	}
	if(tempword==keyword){
		counter++;
	}
	return counter;
}

string keywords[21];
string oriSentences[21];
string sentences[21];
int count[21];

int main(){
	int K,E;
	int tc = 1;
	while(cin >> K >> E){
		memset(count,0,sizeof(count));
		string temp;
		getline(cin,temp); //dummy getline
		
		//read keywords and sentences
		for(int i=0;i<K;i++){
			getline(cin,keywords[i]);
		}
		for(int i=0;i<E;i++){
			getline(cin,oriSentences[i]);
			sentences[i] = convertToLower(oriSentences[i]);
		}

		//count the number of occurences
		for(int i=0;i<E;i++){
			for(int j=0;j<K;j++){
				count[i] += contains(sentences[i],keywords[j]);
			}
		}

		//count the number excuses and store its index
		vector<int> ans;
		int max = 1;
		for(int i=0;i<E;i++){
			if(max<count[i]){
				ans.clear();
				ans.push_back(i);
				max = count[i];
			}
			else if(max==count[i]){
				ans.push_back(i);
			}
		}

		//print the necessary information
		cout << "Excuse Set #" << tc << endl;
		for(int i=0;i<(int)ans.size();i++){
			cout << oriSentences[ans[i]] << endl;
		}
		cout << endl;

		tc++;
	}

	return 0;
}