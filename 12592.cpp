//Steven Kester Yuwono - UVa 12592

#include <iostream>
#include <map>
using namespace std;

map<string,string> storage;
map<string,string>::iterator it;

int main(){
	int N;
	cin >> N;
	string temp;
	getline(cin,temp); //clear cin
	for(int d=0;d<N;d++){
		string word1,word2;
		getline(cin,word1);
		getline(cin,word2);
		storage.insert(pair<string,string>(word1,word2));
	}
	int M;
	cin >> M;
	getline(cin,temp); //clear cin
	for(int d=0;d<M;d++){
		string query;
		getline(cin,query);
		it = storage.find(query);
		cout << it->second << endl;
	}
	return 0;
}