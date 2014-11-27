//Steven Kester Yuwono - UVa 12504

#include <iostream>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	string temp;
	getline(cin,temp); // dummy getline
	for(int d=0;d<tc;d++){

		string line;
		getline(cin,line);
		line = line.substr(1,line.length()-2);
		istringstream istream1(line);

		map<string,string> m;
		map<string,string>::iterator it;

		string key, value;
		while(getline(istream1,key,':')){
			getline(istream1,value,',');
			m.insert(pair<string,string>(key,value));
		}

		set<string> add;
		set<string> minus;
		set<string> change;

		getline(cin,line);
		line = line.substr(1,line.length()-2);
		istringstream istream2(line);
		
		while(getline(istream2,key,':')){
			getline(istream2,value,',');
			
			it = m.find(key);
			if(it==m.end()){
				add.insert(key);
			}
			else if(it->second!=value){
				change.insert(key);
				m.erase(it);
			}
			else{
				m.erase(it);
			}
		}

		for(it=m.begin();it!=m.end();it++){
			minus.insert(it->first);
		}

		bool printed = false;

		set<string>::iterator itset;
		if(add.size()>0){
			itset = add.begin();
			cout << "+" << *itset;
			itset++;
			for(;itset!=add.end();itset++){
				cout << "," << *itset;
			}
			cout << endl;
			printed = true;
		}
		if(minus.size()>0){
			itset = minus.begin();
			cout << "-" << *itset;
			itset++;
			for(;itset!=minus.end();itset++){
				cout << "," << *itset;
			}
			cout << endl;
			printed = true;
		}
		if(change.size()>0){
			itset = change.begin();
			cout << "*" << *itset;
			itset++;
			for(;itset!=change.end();itset++){
				cout << "," << *itset;
			}
			cout << endl;
			printed = true;
		}

		if(!printed){
			cout << "No changes" << endl;
		}

		cout << endl;
	}
	return 0;
}