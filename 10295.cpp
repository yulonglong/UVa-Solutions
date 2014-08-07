//Steven Kester Yuwono - UVa 10295

#include <bits/stdc++.h>
using namespace std;

map<string,int> store;
map<string,int>::iterator it;

int main(){
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++){
		string word1;
		int value;
		cin >> word1;
		cin >> value;
		store.insert(pair<string,int>(word1,value));
	}
	for(int i=0;i<q;i++){
		int total=0;
		string word;
		cin >> word;
		while(word!="."){
			it = store.find(word);
			if(it!=store.end()){
				total+=it->second;
			}
			cin >> word;
		}
		cout << total << endl;
	}
			
	return 0;
}
