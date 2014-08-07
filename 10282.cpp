//uva 10282
#include <bits/stdc++.h>
using namespace std;

map<string,string> dict;
map<string,string>::iterator it;

int main(){
	string line;
	getline(cin,line);
	while(line.length()>0){
		istringstream istream(line);
		string word1;
		string word2;
		istream >> word1;
		istream >> word2;
		dict.insert(pair<string,string>(word2,word1));	
		getline(cin,line);
	}
	while(getline(cin,line)){
		it=dict.find(line);
		if(it==dict.end()){
			cout << "eh" << endl;
		}
		else{
			cout << it->second << endl;
		}
	}
	return 0;
}
