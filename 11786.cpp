//Steven Kester Yuwono - UVa 11786

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	//ifstream cin("input.txt");
	int level=0;
	int total=0;;
	int pending[10001];
	for(int i=0;i<10001;i++){
		pending[i]=0;
	}
	string word;
	int n;
	cin >> n;
	getline(cin,word);
	while(n--){
		getline(cin,word);
		//cout << word << endl;
		for(unsigned int i=0;i<word.length();i++){
			if (word[i]=='\\'){
				level++;
				for(int j=1;j<=level;j++){
					pending[j]++;
				}
			}
			else if(word[i]=='/'){
				level--;
				if(level>=0){
					for(int j=1;j<=level;j++){
						pending[j]++;
					}
					total=total+pending[level+1];
					pending[level+1]=0;
				}
				else{
					level=0;
				}
			}
			else{
				if(level>=0){
					for(int j=1;j<=level;j++){
						pending[j]++;
					}
				}
			}
		}
		cout << total << endl;
		total=0;
		level=0;
		for(int i=0;i<10001;i++){
			pending[i]=0;
		}
	}
	return 0;
}
