//Steven Kester Yuwono - UVa 865

#include <iostream>
#include <map>
using namespace std;

map<char,char> cypherStore;

char cypher(char letter){
	map<char,char>::iterator it;
	it = cypherStore.find(letter);
	if(it == cypherStore.end()){
		return letter;
	}
	else{
		return it->second;
	}
}

int main(){
	bool first = true;
	string line;
	getline(cin,line); //get dummy number of cases

	while(getline(cin,line)){
		if(line.length()==0){
			if(first){
				first = false;
			}
			else{
				cout << endl;
			}
			cypherStore.clear();
			string before, after;
			getline(cin,before);
			getline(cin,after);
			cout << after << endl;
			cout << before << endl;
			for(int i=0;i<(int)before.length();i++){
				cypherStore.insert(pair<char,char>(before[i],after[i]));
			}
		}
		else{
			for(int i=0;i<(int)line.length();i++){
				cout << cypher(line[i]);
			}
			cout << endl;
		}
	}
	return 0;
}