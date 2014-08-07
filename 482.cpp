#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main(){
	string word;
	int first=true;
	int tc;
	cin >> tc;
	getline(cin,word);
	while(tc--){
		if(first){
			first=false;
		}
		else{
			cout << endl;
		}
		getline(cin,word);
		string word1;
		string word2;
		getline(cin,word1);
		istringstream istream1(word1);
		getline(cin,word2);
		istringstream istream2(word2);
		map<int,string> m;
		int index=0;
		while(istream1>>index){
			string data;
			istream2>>data;
			m.insert(pair<int,string>(index,data));
		}
		map<int,string>::iterator it;
		for(it=m.begin();it!=m.end();it++){
			cout << it->second << endl;
		}
	}
	
	return 0;
}
